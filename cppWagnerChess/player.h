#include <memory>//unique_ptr
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "location.h"

using namespace std;

class Player{
  string color;
  map<string,unique_ptr<Piece>> pieces;//map of pieces: cannot have map of abstract class
  unordered_map<string,Location> locations;
  
public:

  Player(){};
 Player(string c,unordered_map<string,Location> locs):color{c},locations{locs}{

    pieces["king"]=unique_ptr<Piece>{new King(PieceType::KING)};
    cout<<toString();
    
  };


  string toString() const;
};
