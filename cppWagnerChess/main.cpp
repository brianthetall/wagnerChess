#include <iostream>
#include <string>
#include "board.h"

int main(int argc, char** argv){

  cout<<"MAIN\n";
  
  Board *b=new Board{};

  cout << "Board Made\n";
  
  cout << b->toString();

  delete b;
  
  return 0;
}
