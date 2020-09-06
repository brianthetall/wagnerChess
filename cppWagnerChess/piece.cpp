#include "piece.h"
#include "location.h"

Piece::Piece(PieceType pt,Location& l):type{pt},location{&l}{

  location->setPiece(*this);//Pass reference of this class to the Location
    
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
