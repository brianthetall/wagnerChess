#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "board.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 2599
#define CLIENT 1
#define SERVER 2

int checkInput(char*);

int checkInput(char* location){

  //printf("CheckInput: %d<=%d<=%d %d<=%d<=%d\n", 'A',location[0],'H','0',location[1],'7');
  if ('A' <= location[0] && location[0] <= 'H' && '0' <= location[1] && location[1]<= '7'){
    return 1;
  }
  return INVALID_INPUT_EXCEPTION;
}

int main(int argc,char** argv){

  int mode=0;//CLIENT OR SERVER
  int moveResult=0;
  char* input=(char*)malloc(10);
  char* loc=(char*)malloc(4);//for user input via scanf
  char* locNew=(char*)malloc(4);//for user input via scanf
  BoardPtr board=initBoard();

  //setup Server socket
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
  else if (argc==2 && 0==strcmp(*++argv,"s")){
    
    printf("setup server socket\n");
    mode=SERVER;
  
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
      {
	perror("socket failed");
	exit(EXIT_FAILURE);
      }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
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
  
  while(1){
    while(1){
      printf("\n%s",board->toString(board));
      printf("White Move:");

      if(mode==SERVER){
	scanf("%s",input);
	send(new_socket , input , strlen(input) , 0 );
 
      }else if(mode==CLIENT){
	read( sock , input, 1024);
	printf("Client rx'ed:%s\n",input);
      }
      
      loc=strtok(input,",");
      locNew=strtok(NULL,",");

      if(loc==NULL || locNew==NULL){
	printf("INVALID_INPUT_EXCEPTION\n");
	continue;
      }
      
      if(checkInput(loc)==LEGAL_INPUT && checkInput(locNew)==LEGAL_INPUT)
	printf("LegalInput\n");
      else{
	printf("INVALID_INPUT_EXCEPTION\n");
	continue;
      }
      
      //printf("Main: %s %s\n",loc,locNew);
      
      moveResult=board->move(board,loc,locNew,"white");
      
      if (moveResult!=LEGAL_MOVE){
	if (moveResult==NOT_YOUR_PIECE){
	  printf("\nNOT_YOUR_PIECE\n");
	  continue;
	}else if(moveResult==ILLEGAL_MOVE_EXCEPTION){
	  printf("\nILLEGAL_MOVE_EXCEPTION\n");
	  continue;
	}else if(moveResult==IN_CHECK_EXCEPTION){
	  printf("\nIN_CHECK_EXCEPTION\n");
	  continue;
	}else{
	  printf("\nException\n");
	  continue;
	}
      }
      break;//all good
    }

    while(1){
      printf("%s",board->toString(board));
      printf("Black Move:");

      
      if(mode==CLIENT){
	scanf("%s",input);
	send(sock , input , strlen(input) , 0 );
 
      }else if(mode==SERVER){
	read( new_socket , input, 1024);
	printf("Server rx'ed:%s\n",input);
      }

      loc=strtok(input,",");
      locNew=strtok(NULL,",");

      if(loc==NULL || locNew==NULL){
	printf("INVALID_INPUT_EXCEPTION\n");
	continue;
      }
      
      if(checkInput(loc)==LEGAL_INPUT && checkInput(locNew)==LEGAL_INPUT)
	printf("LegalInput\n");
      else{
	printf("INVALID_INPUT_EXCEPTION\n");
	continue;
      }
          
      printf("%s %s",loc,locNew);
      moveResult=board->move(board,loc,locNew,"black");
      if (moveResult!=0){
	if (moveResult==NOT_YOUR_PIECE){
	  printf("NOT YOUR PIECE\n");
	  continue;
	}else if(moveResult==ILLEGAL_MOVE_EXCEPTION){
	  printf("ILLEGAL_MOVE_EXCEPTION\n");
	  continue;
	}else if(moveResult==IN_CHECK_EXCEPTION){
	  printf("IN_CHECK_EXCEPTION\n");
	  continue;
	}else{
	  printf("Exception\n");
	  continue;
	}
      }
      break;//all good

    }

  }
  
  return 0;
}
