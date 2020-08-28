#include <stdio.h>
#include <stdlib.h>
#include "piece.h"
#include "myString.h"

typedef struct player* PlayerPtr;
typedef struct player{

  char* color;
  PiecePtr pieces[16];
  char* (*toString)(PlayerPtr p);
  char* (*getColor)(PlayerPtr p);
  
}Player;

PlayerPtr initPlayer(char*);
char* toStringPlayer(PlayerPtr);
char* playerGetColor(PlayerPtr);
