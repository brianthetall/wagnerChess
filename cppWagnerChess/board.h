#include <unordered_map>
#include <iostream>
#include "location.h"
#include "piece.h"
#include "coordinate.h"
#include "player.h"

using namespace std;

enum MoveOutcome{ACCEPTED,NOT_YOUR_PIECE,ILLEGAL_MOVE,IN_CHECK};
//enum class rows{A,B,C,D,E,F,G,H};
//enum class cols{a,b,c,d,e,f,g,h};

class Board{

  unordered_map<string,Player> player;

  //,{"black",new Player("black")} };
  //map<string,int> player{ {"1",1},{"2",2} };
  //Coordinate locations[8][8]{};

 public:
  Board();
  MoveOutcome move(Location l,Location lnew,string);
  string toString();

};
