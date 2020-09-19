#include <string>
#include <ncurses.h>
#include <map>
#include <forward_list>
#include "player.h"
#include "piece.h"
#include "coordinate.h"

using namespace std;

/* board size */
#define BDEPTH	8
#define BWIDTH	8

/* where to start the instructions */
#define INSTRY	2
#define INSTRX	35
/* notification line */
#define NOTIFYY	21

/* corner of board */
#define BOARDY	2
#define BOARDX	2

#define CX(x)		(2 + 4 * (x))
#define CY(y)		(1 + 2 * (y))
#define cellmove(y, x)	wmove(boardwin, CY(y), CX(x))
#define CXINV(x)	(((x) - 1) / 4)
#define CYINV(y)	(((y) - 2) / 2)


class Gui{

  WINDOW *boardwin;	/* the board window */
  WINDOW *movewin;      //User input window
  WINDOW *gravewin;     //Pieces removed from game
  WINDOW *moveswin;     //History of most recent moves, N-deep
  WINDOW *errorwin;     //Exception Explaination Window; in-check, etc
  
 public:
  Gui();
  int graveyard(Piece *p, Player *player, Player *attacker);
  void dosquares(void);
  string update(map<Coordinate*,Piece*> pieces, bool isTurn);
  int movesUpdate(string moveString);
  void outputError(string error);

};
