#include "queen.h"
#include "location.h"

using namespace std;

vector<Location*>Queen::getMoves(){

  Location *current;
  Piece *p;
  vector<Location*> moves{};
    
  for(auto dir : {"n","s","e","w","ne","se","nw","sw"}){

    current=location;//reset
    cout <<"\nQueen Direction: "<<dir;
    while(true){//keep going that direction until...
      
      current = checkIfValid (current->neighbors[dir] );
      if(current!=nullptr){
	moves.push_back(current);
	p=current->getPiece();
	cout << "currentLoc="<<current->toString();
	if(p!=nullptr){
	  if(p->getColor() != color)
	    break;
	}
      }
      else{ break; }
    }

  }



  return moves;

}
