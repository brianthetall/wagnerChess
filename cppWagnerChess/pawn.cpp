#include "pawn.h"
#include "location.h"

using namespace std;

vector<Location*>Pawn::getMoves(){

  Location* current;
  vector<Location*> moves{};

  string dir = color==Color::WHITE ? "ne" : "sw";
  
  current=location->neighbors[dir];
  current=checkIfValid(current);
  if(current!=nullptr)
    moves.push_back(current);

  if(virgin && current!=nullptr){
    current=current->neighbors[dir];
    current=checkIfValid(current);
    if(current!=nullptr)
      moves.push_back(current);
  }
    
  return moves;

}

//only valid if a Piece is not on the Location
Location* Pawn::checkIfValid(Location* l){

  if (l==nullptr)
    return nullptr;

  Piece *p = l->getPiece();

  return p==nullptr ? l : nullptr;
  
}
