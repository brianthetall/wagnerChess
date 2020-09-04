#include "coordinate.h"
#include <bits/unique_ptr.h>

using namespace std;

class Piece;

class Location{
  Coordinate c;
  Piece* p;

 public:
  Location(Coordinate c);
  Location& setPiece(Piece* p);
  Location& clearPiece();
};
