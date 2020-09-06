#include "location.h"
#include "piece.h"

Location::Location(Coordinate* c){
  this->c=c;
  //cout << "Location@ " << this->c->toString();
}

Location& Location::setPiece(Piece* p){
  piece=p;
  //cout << "Piece Set=" << piece->toString()<<" @ "<<this->c->toString()<<'\n';
  return *this;
}

Piece* Location::getPiece(){
  return piece;
}

Location& Location::clearPiece(){
  piece=nullptr;
  return *this;
}

void Location::connectToNeighbors(unordered_map<string,Location*> locations ){

  cout<<"Connect To Neighbors Stub\n";  
  
}

string Location::toString(void){return piece==nullptr ? c->toString() : piece->toString();}
