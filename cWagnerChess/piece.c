#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

PiecePtr initPiece(int type, char* color){
  
  PiecePtr p = (PiecePtr)malloc(sizeof(Piece));
  p->pieceType = type;
  p->location=0x00;
  p->color=color;
  p->getColor=&getColor;
  p->toString=&toStringPiece;
  return p;
}

char* getColor(PiecePtr p){
  return p->color;
}

char* toStringPiece(PiecePtr p){
  return "pieceTostring";
}
