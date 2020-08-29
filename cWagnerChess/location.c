#include "location.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


LocationPtr initLocation(LocationPtr lp, int i, int j){

  lp=(LocationPtr)malloc(sizeof(Location));

  lp->col=i;
  lp->row=j;

  lp->toString=&toStringLocation;
  lp->setPiece=setPiece;
  lp->clearPiece=clearPiece;
  lp->getPiece=&getPiece;
  
  //printf("Location: %s@%x\n",lp->toString(lp),lp);

  return lp;
  
}

char* toStringLocation(LocationPtr lp){

  char* retval = (char*) calloc(sizeof(char),64);
  if(lp->piece==NULL)
    sprintf(retval,"|" ANSI_COLOR_BLUE "%c%d" ANSI_COLOR_RESET,lp->col+65,lp->row);
  else{
    if( strcmp( lp->piece->getColor(lp->piece), "black" ) == 0  )
      sprintf(retval,"|" ANSI_COLOR_RED "%s" ANSI_COLOR_RESET,lp->piece->toString(lp->piece));
    else
      sprintf(retval,"|" ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET,lp->piece->toString(lp->piece));
  }
  return retval;
}

void setPiece(LocationPtr lp,PiecePtr p){
  lp->piece=p;
}

void clearPiece(LocationPtr lp){
  lp->piece=NULL;
}

PiecePtr getPiece(LocationPtr lp){
  return lp->piece;
}
