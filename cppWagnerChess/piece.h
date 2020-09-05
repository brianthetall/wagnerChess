#pragma once

//#include <bits/unique_ptr.h>
#include <string>

using namespace std;

class Location;

class Piece{
  string name;
  //unique_ptr<Location> l;
  //Location* l;
  
public:
  Piece():name{"why do i need this default constructor???"}{};
  Piece(const string& n):name{n}{};
  string toString() const;
};
