#include <stdio.h>
#include <stdlib.h>
#include "myString.h"

typedef struct player* PlayerPtr;
typedef struct player{

  char* color;
  //pieces
  char* (*toString)(PlayerPtr p);
  
}Player;

PlayerPtr initPlayer(char*);
char* toStringPlayer(PlayerPtr);
