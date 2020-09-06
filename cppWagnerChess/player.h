#include <memory>//unique_ptr
#include <map>
#include <string>
#include <iostream>
#include "piece.h"
#include "king.h"

using namespace std;

class Player{
  string color;
  map<string,unique_ptr<Piece>> pieces;//map of pieces: cannot have map of abstract class
  
public:

  Player(){};
  Player(string c):color{c}{

    pieces["king"]=unique_ptr<Piece>{new King(PieceType::KING)};
    cout<<toString();
    
  };


  string toString() const;
};
