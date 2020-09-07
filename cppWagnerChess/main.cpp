#include <sstream>
#include <iostream>
#include <string>
#include "board.h"

int main(int argc, char** argv){

  Board *b=new Board{};
  string moveString,temp,start,dest;
  
  while(true){
    while(true){

      cout << b->toString()<<endl;
      cout << "White Move: ";
      cin >> moveString;
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
      cin >> moveString;
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
