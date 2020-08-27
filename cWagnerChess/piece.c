#include <stdio.h>
#include <stdlib.h>
#include "location.h"

enum {KING=1,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};

PiecePtr initPiece(int, LocPtr, char*);//locPtr

PiecePtr initPiece(int type, LocPtr loc, char* color){
  
  PiecePtr p = (PiecePtr)malloc(sizeof(Piece));
  p->pieceType = type;
  p->location=loc;
  p->color=color;

  return p;
}
