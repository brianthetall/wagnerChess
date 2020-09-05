#include <map>
#include <string>
#include <iostream>
#include "piece.h"

using namespace std;

class Player{
  string color;
  map<string,Piece> pieces;//map of pieces
  
public:

  Player(){};
  Player(string c):color{c}{

    pieces["king"]=Piece("king");
    cout<<toString();
    
  };


  string toString() const;
};
