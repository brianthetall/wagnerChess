#include "player.h"

Player::Player(string c,unordered_map<string,Location> locs):color{c},locations{locs}{
  
    pieces["king"]=unique_ptr<Piece>{new King(PieceType::KING)};
    cout<<toString();
    
  };


string Player::toString() const{
  return "Player: " + color;
}
