#include "location.h"

void initLocation(LocationPtr lp, int i, int j){

  lp=(LocationPtr)malloc(sizeof(Location));

  lp->col=i;
  lp->row=j;

  lp->toString=&toStringLocation;
  
}

char* toStringLocation(LocationPtr lp){
  char* retval = (char*) malloc(sizeof(char)*4);
  sprintf(retval,"|%d%d|",lp->col,lp->row);
  return retval;
}
