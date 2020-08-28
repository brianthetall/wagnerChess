#include "player.h"

PlayerPtr initPlayer(char* color){
  PlayerPtr p = (PlayerPtr)malloc(sizeof(Player));
  p->color=color;
  p->toString=toStringPlayer;
  p->getColor=playerGetColor;

  p->pieces[KING] = initPiece(KING,color);
  p->pieces[QUEEN] = initPiece(QUEEN,color);
  p->pieces[BISHOP] = initPiece(BISHOP,color);
  p->pieces[KNIGHT] = initPiece(KNIGHT,color);
  p->pieces[ROOK] = initPiece(ROOK,color);
  p->pieces[PAWN] = initPiece(PAWN,color);
  p->pieces[PAWN+1] = initPiece(PAWN,color);
  p->pieces[PAWN+2] = initPiece(PAWN,color);
  p->pieces[PAWN+3] = initPiece(PAWN,color);
  p->pieces[PAWN+4] = initPiece(PAWN,color);
  p->pieces[PAWN+5] = initPiece(PAWN,color);
  p->pieces[PAWN+6] = initPiece(PAWN,color);
  p->pieces[PAWN+7] = initPiece(PAWN,color);
  //
  p->pieces[PAWN+8] = initPiece(BISHOP,color);
  p->pieces[PAWN+9] = initPiece(KNIGHT,color);
  p->pieces[PAWN+10] = initPiece(ROOK,color);
  return p;

}

char* toStringPlayer(PlayerPtr p){

  int i=0;
  for(i=0; i<= PAWN+10 ; i++){
    printf("%s %s\n",p->pieces[i]->toString(p->pieces[i]),
	   p->pieces[i]->getType(p->pieces[i]));
  }

  return "";
}

char* playerGetColor(PlayerPtr p){
  return p->color;
}
