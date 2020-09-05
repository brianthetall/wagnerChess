#include "location.h"
#include "piece.h"

Location::Location(Coordinate c={'A',0}){
  this->c=c;
  cout << "Location@ " << this->c.toString();
}

Location& Location::setPiece(Piece* p){
  this->p=p;
  return *this;
}

Location& Location::clearPiece(){
  p=nullptr;
  return *this;
}

void Location::connectToNeighbors(unordered_map<string,Location> locations ){

  
  
}
