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
  p->getType=&getType;
  p->type=&getEnumType;
  
  return p;
}

int getEnumType(PiecePtr p){
  return p->pieceType;
}

char* getType(PiecePtr p){
  switch(p->pieceType){
  case KING:
    return "K ";
  case QUEEN:
    return "Q ";
  case BISHOP:
    return "B ";
  case KNIGHT:
    return "N ";
  case ROOK:
    return "R ";
  case PAWN:
    return "p ";
  default:
    return "wtf";
  }
    
}

char* getColor(PiecePtr p){
  return p->color;
}

char* toStringPiece(PiecePtr p){
  return p->getType(p);
}

char* toStringPieceLong(PiecePtr p){

  char* s=(char*)malloc(50);
  strcat(s,p->getColor(p));
  strcat(s," ");
  strcat(s,p->getType(p));
  
  return s;
}
