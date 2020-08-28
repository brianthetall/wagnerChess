#include "location.h"

LocationPtr initLocation(LocationPtr lp, int i, int j){

  lp=(LocationPtr)malloc(sizeof(Location));

  lp->col=i;
  lp->row=j;

  lp->toString=&toStringLocation;

  //printf("Location: %s@%x\n",lp->toString(lp),lp);

  return lp;
  
}

char* toStringLocation(LocationPtr lp){

  char* retval = (char*) calloc(sizeof(char),4);
  sprintf(retval,"|%d%d|",lp->col,lp->row);
  return retval;
}
