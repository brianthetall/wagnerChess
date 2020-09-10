#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <cstring>

using namespace std;

enum class Type{SERVER,CLIENT};

class MySocket{

  Type type;
  int port,buffer;
  string ip;
  
  char* input;
  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);

  //open socket connection to server
  struct sockaddr_in serv_addr;

public:
  
  MySocket(){}

  //setup as server
  MySocket(int port,int bufferSize):port{port},buffer{bufferSize}{
  
    type=Type::SERVER;

    input=(char*)malloc(buffer);
        
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
    address.sin_port = htons( port );

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

  //setup as client
  MySocket(string ipAddr,int port,int bufferSize):ip{ipAddr},port{port},buffer{bufferSize}{

    type=Type::CLIENT;

    input=(char*)malloc(buffer);
    
    if ((new_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
      {
	printf("\n Socket creation error \n");
	exit(EXIT_FAILURE);
      }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, ip.c_str() , &serv_addr.sin_addr)<=0)
      {
	printf("\nInvalid address/ Address not supported \n");
	exit(EXIT_FAILURE);
      }

    if (connect(new_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
      {
	printf("\nConnection Failed \n");
	exit(EXIT_FAILURE);
      }

  }

  void sendString(string s){

    send(new_socket,s.c_str(), strlen(s.c_str()) , 0 );
    
  }
  
  string readString(){

    memset(input,0,buffer);
    read( new_socket , input, buffer );
    string inputStr{input};
    return inputStr;

  }

};
