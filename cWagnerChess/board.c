#include "player.h"
#include "location.h"
#include <stdlib.h>

typedef struct board* BoardPtr;
typedef struct board{
  PlayerPtr white;
  PlayerPtr black;
  LocationPtr locations[8][8];
  
} Board;

BoardPtr initBoard(){

  BoardPtr b = (BoardPtr)malloc(sizeof(Board));

  for(int i=0;i<8;i++){
    for(int j=0;j<H;j++){
      initLocation( b->locations[i][j], i, j );
    }
  }
  
  return b;
}
