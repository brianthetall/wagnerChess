#include "player.h"
#include "location.h"
#include <stdlib.h>
#include "myString.h"

typedef struct board* BoardPtr;
typedef struct board{
  PlayerPtr white;
  PlayerPtr black;
  LocationPtr locations[8][8];
  char* (*toString)(BoardPtr b);
  
} Board;

BoardPtr initBoard();
char* toStringBoard(BoardPtr);
