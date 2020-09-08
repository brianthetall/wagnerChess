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

protected:
  string name;
  PieceType type;
  Color color;
  Location* location;
  bool virgin,whore;
  
public:
  Piece(){};
  Piece(PieceType pt,Color c,Location* l);
  string toString() const;
  Location* checkIfValid(Location* l);//return nullptr if not
  Color getColor(){return color;}
  void sex(){
    if (virgin==false)
      whore=true;
    virgin=false;
  }
  bool isWhore(){ return whore; }
  void unsex(){virgin=true;}
  void setLocation(Location* l){location=l;}
  virtual vector<Location*> getMoves()=0;
  virtual ~Piece(){}
};
