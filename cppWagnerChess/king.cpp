#include "king.h"
#include "location.h"

using namespace std;

vector<Location*> King::getMoves(){

  Location* temp;
  vector<Location*> moves{};
  //this inherits from Piece: location*
  //location has 'neighbors' map
  //keys are 'n' 'nw', etc

  for(auto& n:location->neighbors){
    //cout << "KING: "<<n.first<<'\n';
    temp=checkIfValid( n.second );
    if(temp!=nullptr){ moves.push_back(temp); }
  }

  
  
  return moves;

}
