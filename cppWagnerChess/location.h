#pragma once

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include "coordinate.h"
//#include <bits/unique_ptr.h>

using namespace std;

class Piece;

class Location{
  Coordinate* c;
  Piece* piece;
  map<string,Location*> neighbors;
  
 public:
  Location(){};
  Location(Coordinate* c);
  Location& setPiece(Piece* p);
  Piece* getPiece();
  Location& clearPiece();
  void connectToNeighbors(unordered_map<string,Location*> locations);
  string toString(void);
  
};
