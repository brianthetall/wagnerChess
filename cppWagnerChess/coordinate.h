#pragma once
#include <sstream>
#include <iostream>

using namespace std;

class Coordinate{
  char row;
  int col;

 public:

  Coordinate(){};
  Coordinate(char row,int col):row{row},col{col}{cout<<toString();};
  string toString() const;
  
};
