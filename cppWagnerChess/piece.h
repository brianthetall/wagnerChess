#pragma once

#include <sstream>
#include <vector>
#include <string>
#include "location.h"

using namespace std;

class Location;//forward declaration

enum class PieceType{KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};
enum class Color{BLACK,WHITE};

class Piece{

private:
  string name;
  PieceType type;
  Color color;

protected:
  Location* location;
  
public:
  Piece(){};
  Piece(PieceType pt,Color c,Location* l);
  string toString() const;
  Location* checkIfValid(Location* l);//return nullptr if not
  Color getColor(){return color;}
  virtual vector<Location*> getMoves()=0;
  virtual ~Piece(){}
};
