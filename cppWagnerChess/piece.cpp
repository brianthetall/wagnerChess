#include "piece.h"
#include "location.h"

Piece::Piece(string name){
  this->name=name;
}

string Piece::toString() const{
  return name;
}
