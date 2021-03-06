#ifndef LOC
#define LOC

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "piece.h"

enum cols {A,B,C,D,E,F,G,H};
enum rows {a,b,c,d,e,f,g,h};


typedef struct location* LocationPtr;


typedef struct location{
  PiecePtr piece;
  LocationPtr n;
  LocationPtr nw;
  LocationPtr w;
  LocationPtr sw;
  LocationPtr s;
  LocationPtr se;
  LocationPtr e;
  LocationPtr ne;

  LocationPtr nextLocation;

  enum cols col;
  enum rows row;

  char* (*toString)(LocationPtr lp);
  char* (*toStringPlain)(LocationPtr lp);
  void (*setPiece)(LocationPtr lp,PiecePtr p);
  void (*clearPiece)(LocationPtr lp);
  PiecePtr (*getPiece)(LocationPtr lp);
  char* (*memory)(LocationPtr lp);
  LocationPtr (*isMoveLegal)(PiecePtr p, LocationPtr location, LocationPtr locationNext);
  LocationPtr (*possibleMoves)(PiecePtr p, LocationPtr location, LocationPtr locationNext);
  
} Location;

#endif

LocationPtr initLocation(LocationPtr,int,int);
char* toStringLocation(LocationPtr);
char* toStringPlain(LocationPtr);
void setPiece(LocationPtr,PiecePtr);
void clearPiece(LocationPtr);
PiecePtr getPiece(LocationPtr);
char* printInterconnections(LocationPtr);
LocationPtr isMoveLegal(PiecePtr,LocationPtr,LocationPtr);
LocationPtr possibleMoves(PiecePtr, LocationPtr, LocationPtr);
LocationPtr rookMoves(PiecePtr,LocationPtr);//return a list of LocationPtr linked
LocationPtr bishopMoves(PiecePtr,LocationPtr);
LocationPtr knightMoves(PiecePtr,LocationPtr);
LocationPtr kingMoves(PiecePtr,LocationPtr);
LocationPtr queenMoves(PiecePtr,LocationPtr);
LocationPtr pawnMoves(PiecePtr,LocationPtr);
LocationPtr checkLocation(LocationPtr,char*);

