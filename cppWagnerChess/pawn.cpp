#include "pawn.h"
#include "location.h"

using namespace std;

vector<Location*>Pawn::getMoves(){

  Location *current,*current1;
  vector<Location*> moves{};

  string dir = color==Color::WHITE ? "ne" : "sw";

  string attacks[2];
  if (color==Color::WHITE){
    attacks[0] = "n";
    attacks[1]="e";
  }
  else{
    attacks[0] = "s";
    attacks[1]="w";
  }
  
  current=location->neighbors[dir];
  current=checkIfValid(current);
  if(current!=nullptr)
    moves.push_back(current);

  //look for double jump on virgin move
  if(virgin && current!=nullptr){
    current=current->neighbors[dir];
    current=checkIfValid(current);
    if(current!=nullptr)
      moves.push_back(current);
  }

  //look for attacks:
  current=location->neighbors[attacks[0]];
  current1=location->neighbors[attacks[1]];

  current=checkForAttack(current);
  current1=checkForAttack(current1);

  if ( current!=nullptr)
    moves.push_back(current);
  if ( current1!=nullptr)
    moves.push_back(current1);
      
  return moves;

}

//only valid if a Piece is not on the Location
Location* Pawn::checkIfValid(Location* l){

  if (l==nullptr)
    return nullptr;

  Piece *p = l->getPiece();

  return p==nullptr ? l : nullptr;
  
}

Location* Pawn::checkForAttack(Location* l){
  if (l==nullptr)
    return nullptr;
  
  Piece *p = l->getPiece();
  if(p == nullptr)
    return nullptr;
  
  return color==p->getColor() ? nullptr : l;
  
}
