#include <stdlib.h>
#include <stdio.h>

enum cols {A,B,C,D,E,F,G,H};
enum rows {a,b,c,d,e,f,g,h};


typedef struct location* LocationPtr;


typedef struct location{
  void* piece;
  LocationPtr n;
  LocationPtr nw;
  LocationPtr w;
  LocationPtr sw;
  LocationPtr s;
  LocationPtr se;
  LocationPtr e;
  LocationPtr ne;

  enum cols col;
  enum rows row;

  char* (*toString)(LocationPtr lp);
  
} Location;

void initLocation(LocationPtr,int,int);
char* toStringLocation(LocationPtr);
