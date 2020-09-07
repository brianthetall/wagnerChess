#include <sstream>
#include <iostream>
#include <string>
#include "board.h"

int main(int argc, char** argv){

  MoveOutcome mo;
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
      mo=b->move(start,dest,"white");

    }

    while(true){
      break;
    }
  }
  
  delete b;
  
  return 0;
}
