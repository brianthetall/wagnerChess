#include <fstream>
#include <sstream>
#include <string.h>
#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>
#include "location.h"
#include "piece.h"
#include "coordinate.h"
#include "player.h"
#include "invalidLocation.h"
#include "notYourPiece.h"
#include "inCheck.h"
#include <ezSql.h>

using namespace std;

enum class MoveOutcome{ACCEPTED,NOT_YOUR_PIECE,ILLEGAL_MOVE,IN_CHECK};
enum rows{A,B,C,D,E,F,G,H};

class Board{

  EzSql *sql;
  unordered_map<string,Player*> player;
  unordered_map<string,Location*> locations;

 public:
  Board();
  
  MoveOutcome move(string l,string lnew,string color,string moveString);//moveString is for the GUI
  string toString();
  bool isInCheck(Color c);

};
