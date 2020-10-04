#include <boost/algorithm/string.hpp>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sstream>
#include <iostream>
#include <string>
#include <board.h>
#include <mySocket.h>

#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>  

#define BUFFER 256
#define PORT 2599

int main(void){

  Type mode;
  string moveString,temp,start,dest;
  MySocket socket;
  static bool turn=true;//true == white

  cout << "Content-type:text/html\r\n\r\n";
  cout << "<html>\n";
  cout << "<head>\n";
  cout << "<title>CGI Wagner Chess</title>\n";
  cout << "</head>\n";
  cout << "<body>\n";
  cout << "Making Board...";

  //the game:
  Board *b=new Board{};
    
  ofstream debug;
  debug.open("/home/user/logs/mainDebug");

  
  while(true){
    while(true){

      cout << b->toString()<<endl;
      
      if(b->move(start,dest,"white",moveString)==MoveOutcome::ACCEPTED)//send moveString for the GUI
	break;
      
    }

    while(true){

      cout << b->toString()<<endl;
      
      if(b->move(start,dest,"black",moveString)==MoveOutcome::ACCEPTED)//send moveString for the GUI
	break;
      
    }
  }
  
  delete b;
  
  return 0;
}
