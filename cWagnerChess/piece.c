#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

PiecePtr initPiece(int type, char* color){
  
  PiecePtr p = (PiecePtr)malloc(sizeof(Piece));
  p->pieceType = type;
  p->color=color;
  p->getColor=&getColor;
  return p;
}

char* getColor(PiecePtr p){
  return p->color;
}
