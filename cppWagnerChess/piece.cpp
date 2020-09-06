#include "piece.h"
#include "location.h"

Piece::Piece(PieceType pt,Color c,Location* l):type{pt},color{c},location{l}{

  
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
  
  location->setPiece(this);
						}

string Piece::toString() const{

  ostringstream oss{""};

  if(color==Color::BLACK)
    oss<<"\033[1;31m"<<name<<"\033[0m ";

  else
    oss<<"\033[1;33m"<<name<<"\033[0m ";
  
  return oss.str();


}
