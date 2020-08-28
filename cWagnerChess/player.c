#include "player.h"

PlayerPtr initPlayer(char* color){
  PlayerPtr p = (PlayerPtr)malloc(sizeof(PlayerPtr));
  p->color=color;
  p->toString=&toStringPlayer;

  
  return p;

}

char* toStringPlayer(PlayerPtr p){

  printf("toStringPlayer, ptr=%X",p);
  char* s="";

  return s;
}
