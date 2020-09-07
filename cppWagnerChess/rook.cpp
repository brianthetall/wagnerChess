#include "rook.h"
#include "location.h"

using namespace std;

vector<Location*>Rook::getMoves(){

  Location *temp,*current;
  Piece *p;
  vector<Location*> moves{};
    
  for(auto dir : {"n","s","e","w"}){

    current=location;//reset
    cout <<"\nRook Direction: "<<dir;
    while(true){//keep going that direction until...
      
      //cout << "."<<dir<<current->toString()<<" ";
      
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
