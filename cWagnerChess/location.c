#include <stdlib.h>
#include "location.h"

void initLocation(LocationPtr lp, int i, int j){

  lp=(LocationPtr)malloc(sizeof(Location));

  lp->col=i;
  lp->row=j;

  
}

