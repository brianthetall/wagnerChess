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
  void (*setPiece)(LocationPtr lp,PiecePtr p);
  void (*clearPiece)(LocationPtr lp);
  PiecePtr (*getPiece)(LocationPtr lp);
  char* (*memory)(LocationPtr lp);
  int (*isMoveLegal)(PiecePtr p, LocationPtr location, LocationPtr locationNext);
  
} Location;

#endif

LocationPtr initLocation(LocationPtr,int,int);
char* toStringLocation(LocationPtr);
void setPiece(LocationPtr,PiecePtr);
void clearPiece(LocationPtr);
PiecePtr getPiece(LocationPtr);
char* printInterconnections(LocationPtr);
int isMoveLegal(PiecePtr,LocationPtr,LocationPtr);
LocationPtr rookMoves(PiecePtr,LocationPtr);//return a list of LocationPtr linked
LocationPtr checkLocation(LocationPtr,char*);

