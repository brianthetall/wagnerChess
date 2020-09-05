#include <sstream>
#include <string.h>
#include <unordered_map>
#include <iostream>
#include "location.h"
#include "piece.h"
#include "coordinate.h"
#include "player.h"

using namespace std;

enum MoveOutcome{ACCEPTED,NOT_YOUR_PIECE,ILLEGAL_MOVE,IN_CHECK};
enum rows{A,B,C,D,E,F,G,H};
//enum class cols{a,b,c,d,e,f,g,h};

class Board{

  unordered_map<string,Player> player;
  unordered_map<string,Location> locations;

 public:
  Board();
  MoveOutcome move(Location l,Location lnew,string);
  string toString();

};
