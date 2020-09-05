#include <map>
#include <string>
#include "piece.h"

using namespace std;

class Player{
  string color;
  map<string,Piece> pieces;//map of pieces

public:
  Player():color{"why oh why?"}{};
  Player(string c):color{c}{

    pieces["king"]=Piece("king");
    
  };


  string toString() const;
};
