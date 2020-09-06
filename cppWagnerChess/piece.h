#pragma once

#include <vector>
#include <string>

using namespace std;

class Location;//forward declaration

enum class PieceType{KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};

class Piece{

private:
  string name;
  Location* l;
  PieceType type;

public:
  Piece(){};
  Piece(PieceType pt):type{pt}{
    switch(pt){
    case PieceType::KING:
      name="K ";
      break;
    case PieceType::QUEEN:
      name="Q ";
      break;
    case PieceType::BISHOP:
      name="B ";
      break;
    case PieceType::KNIGHT:
      name="N ";
      break;
    case PieceType::ROOK:
      name="R ";
      break;
    case PieceType::PAWN:
      name="p ";
      break;
    default:
      name="mistake";
      break;
    };

  };
  string toString() const{return name;}

  virtual vector<Location> getMoves()=0;
  virtual ~Piece(){}
};
