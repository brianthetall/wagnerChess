#include "location.h"
#include "piece.h"

Location::Location(Coordinate c={'A',69}){
  this->c=c;
}

Location& Location::setPiece(Piece* p){
  this->p=p;
  return *this;
}

Location& Location::clearPiece(){
  p=nullptr;
  return *this;
}
