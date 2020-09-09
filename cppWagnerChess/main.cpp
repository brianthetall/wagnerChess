#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sstream>
#include <iostream>
#include <string>
#include "board.h"

#define PORT 2599
#define CLIENT 1
#define SERVER 2

int main(int argc, char** argv){

  string moveString,temp,start,dest;

  char* input=(char*)malloc(10);
  //setup Server socket
  int mode;
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char rxBuffer[1024] = {0};
  char txBuffer[1024] = {0};

  //open socket connection to server
  int sock = 0;
  struct sockaddr_in serv_addr;


  //CONNECTION FSM STUFF:

  if(argc==1){
    printf("Must specify (c)lient or (s)erver. If client, must also provide IP address of server.\n");
    return -1;
  }

  //SERVER SETUP:
  else if (argc==2 && strcmp(*++argv,"s")==0){
    
    printf("setup server socket\n");
    mode=SERVER;
  
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
      {
	perror("socket failed");
	exit(EXIT_FAILURE);
      }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
		   &opt, sizeof(opt)))
      {
	perror("setsockopt");
	exit(EXIT_FAILURE);
      }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
	     sizeof(address))<0)
      {
	perror("bind failed");
	exit(EXIT_FAILURE);
      }
    if (listen(server_fd, 3) < 0)
      {
	perror("listen");
	exit(EXIT_FAILURE);
      }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
			     (socklen_t*)&addrlen))<0)
      {
	perror("accept");
	exit(EXIT_FAILURE);
      }

  }

  //CLIENT SETUP:
  else if(argc==3 && strcmp(*++argv,"c")==0){
    printf("SETUP client socket\n");
    mode=CLIENT;
    
    char *serverIP=*++argv;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
      {
	printf("\n Socket creation error \n");
	return -1;
      }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, serverIP, &serv_addr.sin_addr)<=0)
      {
	printf("\nInvalid address/ Address not supported \n");
	return -1;
      }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
      {
	printf("\nConnection Failed \n");
	return -1;
      }
    
  }
  else{
    printf("Try Again...\n");
    return -2;
  }


  //the game:
  Board *b=new Board{};
  while(true){
    while(true){

      cout << b->toString()<<endl;
      cout << "White Move: ";
      if(mode==SERVER){
	cin >> moveString;
	input = (char*)moveString.c_str();
	send(new_socket , input , strlen(input) , 0 );
      }else if(mode==CLIENT){
	read( sock , input, 10);
	cout<<"Client RX'ed: "<<input<<endl;
	moveString=input;
      }
      stringstream ss{moveString};
      getline(ss, temp, ',');
      start=temp;
      getline(ss, temp, ',');
      dest=temp;
      if(b->move(start,dest,"white")==MoveOutcome::ACCEPTED)
	break;
      
    }

    while(true){

      cout << b->toString()<<endl;
      cout << "Black Move: ";

      if(mode==CLIENT){
	cin >> moveString;
	input = (char*)moveString.c_str();
	send(sock , input , strlen(input) , 0 );
      }else if ( mode == SERVER){
	read( new_socket , input, 1024);
	cout<<"Server RX'ed: "<<input<<endl;
	moveString=input;
      }
      
      
      stringstream ss{moveString};
      getline(ss, temp, ',');
      start=temp;
      getline(ss, temp, ',');
      dest=temp;
      if(b->move(start,dest,"black")==MoveOutcome::ACCEPTED)
	break;
      
    }
  }
  
  delete b;
  
  return 0;
}
