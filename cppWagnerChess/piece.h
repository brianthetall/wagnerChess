#pragma once

#include <vector>
#include <string>
#include "location.h"

using namespace std;

class Location;//forward declaration

enum class PieceType{KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};

class Piece{

private:
  string name;
  Location* location;
  PieceType type;

public:
  Piece(){};
  Piece(PieceType pt,Location* l);
  string toString() const{return name;}

  virtual vector<Location> getMoves()=0;
  virtual ~Piece(){}
};
