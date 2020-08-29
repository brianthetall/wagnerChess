#include "location.h"

LocationPtr initLocation(LocationPtr lp, int i, int j){

  lp=(LocationPtr)malloc(sizeof(Location));

  lp->col=i;
  lp->row=j;

  lp->toString=&toStringLocation;
  lp->setPiece=setPiece;
  lp->clearPiece=clearPiece;

  //printf("Location: %s@%x\n",lp->toString(lp),lp);

  return lp;
  
}

char* toStringLocation(LocationPtr lp){

  char* retval = (char*) calloc(sizeof(char),4);
  if(lp->piece==NULL)
    sprintf(retval,"|%c%d|",lp->col+65,lp->row);
  else
    sprintf(retval,"|%s|",lp->piece->toString(lp->piece));
  return retval;
}

void setPiece(LocationPtr lp,PiecePtr p){
  lp->piece=p;
}

void clearPiece(LocationPtr lp){
  lp->piece=NULL;
}

