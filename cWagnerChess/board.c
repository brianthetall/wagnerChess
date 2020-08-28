#include "board.h"

BoardPtr initBoard(){

  BoardPtr b = (BoardPtr)malloc(sizeof(Board));
  b->toString=&toStringBoard;

  int i,j=0;

  for(i=0 ; i<=H ; i++){
    for(j=0 ; j<=h ; j++){
      b->locations[i][j] = initLocation( b->locations[i][j], i, j );
    }
  }
  
  return b;
}


char* toStringBoard(BoardPtr b){

  int i,j=0;
  char* s="Board:\n\n";

  for(i=0 ; i<=H ; i++){
    for(j=0 ; j<=h ; j++){
      LocationPtr lp=b->locations[i][j];
      s=mystrcat(s, lp->toString(lp) );
    }
    s=mystrcat(s,"\n");
  }
  
  
  return s;

}
