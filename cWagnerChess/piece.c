#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piece.h"

PiecePtr initPiece(int type, char* color){
  
  PiecePtr p = (PiecePtr)malloc(sizeof(Piece));
  p->pieceType = type;
  p->location=0x00;
  p->color=color;
  p->getColor=&getColor;
  p->toString=&toStringPiece;
  p->getType=getType;
  
  return p;
}

char* getType(PiecePtr p){
  switch(p->pieceType){
  case KING:
    return "king";
  case QUEEN:
    return "queen";
  case BISHOP:
    return "bishop";
  case KNIGHT:
    return "knight";
  case ROOK:
    return "rook";
  case PAWN:
    return "pawn";
  default:
    return "wtf";
  }
    
}

char* getColor(PiecePtr p){
  return p->color;
}

char* toStringPiece(PiecePtr p){

  char* s=(char*)malloc(50);
  strcat(s,p->color);
  
  return s;
}
