#include <sstream>
#include <string.h>
#include <unordered_map>
#include <iostream>
#include "location.h"
#include "piece.h"
#include "coordinate.h"
#include "player.h"
#include "invalidLocation.h"

using namespace std;

enum class MoveOutcome{ACCEPTED,NOT_YOUR_PIECE,ILLEGAL_MOVE,IN_CHECK};
enum rows{A,B,C,D,E,F,G,H};

class Board{

  unordered_map<string,Player*> player;
  unordered_map<string,Location*> locations;

 public:
  Board();
  MoveOutcome move(string l,string lnew,string color);
  string toString();

};
