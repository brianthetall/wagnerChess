#pragma once

#include <sstream>
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include "coordinate.h"

using namespace std;

class Piece;

class Location{
  Coordinate* c;
  Piece* piece;
  
 public:
  Location(){};
  Location(Coordinate* c);
  Location& setPiece(Piece* p);
  Piece* getPiece();
  Location& clearPiece();
  Coordinate* getCoordinate(){return c;}
  void connectToNeighbors(unordered_map<string,Location*> locations);
  string toString(void) const;

  map<string,Location*> neighbors;
  string toStringNeighbors(void) const;
};
