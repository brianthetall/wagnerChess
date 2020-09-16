#include <boost/algorithm/string.hpp>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sstream>
#include <iostream>
#include <string>
#include "board.h"
#include "mySocket.h"

#define BUFFER 256
#define PORT 2599

int main(int argc, char** argv){

  Type mode;
  string moveString,temp,start,dest;
  MySocket socket;

  //CONNECTION FSM STUFF:
  if(argc==1){
    printf("Must specify (c)lient or (s)erver. If client, must also provide IP address of server.\n");
    return -1;
  }

  //SERVER SETUP:
  else if (argc==2 && strcmp(*++argv,"s")==0){
    
    printf("setup server socket\n");
    mode=Type::SERVER;
    socket=MySocket{ PORT,BUFFER };
  
  }

  //CLIENT SETUP:
  else if(argc==3 && strcmp(*++argv,"c")==0){

    printf("SETUP client socket\n");
    mode=Type::CLIENT;
    string ip{ *++argv };
    socket=MySocket{ ip.c_str() , PORT , BUFFER };
    
  }
  
  else{
    printf("Try Again...\n");
    return -2;
  }

  //the game:
  Board *b=new Board{};
    
  ofstream debug;
  debug.open("mainDebug");

  
  while(true){
    while(true){

      //cout << b->toString()<<endl;
      //cout << "White Move: \a";
      
      if(mode==Type::SERVER){
	moveString=b->guiUpdate(true);
	boost::to_upper(moveString);
	debug<<moveString<<endl;
	
	//cin >> moveString;
	socket.sendString(moveString);
      }else if(mode==Type::CLIENT){
	b->guiUpdate(false);
	moveString=socket.readString();
	//cout<<"Client RX'ed: "<<moveString<<endl;
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

      //cout << b->toString()<<endl;
      //cout << "Black Move: \a";
            
      if(mode==Type::CLIENT){
	moveString=b->guiUpdate(true);
	boost::to_upper(moveString);
	debug<<moveString<<endl;
	
	//cin >> moveString;
	socket.sendString(moveString);
      }else if ( mode == Type::SERVER){
	b->guiUpdate(false);
	moveString=socket.readString();
	//cout<<"Server RX'ed: "<<moveString<<endl;
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
