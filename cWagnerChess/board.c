#include "player.h"

typedef struct board* BoardPtr;
typedef struct board{
  PlayerPtr white;
  PlayerPtr black;

} Board;

BoardPtr initBoard(){

  BoardPtr b = (BoardPtr)malloc(sizeof(Board));

  return b;
}
