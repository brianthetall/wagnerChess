#include "board.h"

BoardPtr initBoard(){

  BoardPtr b = (BoardPtr)malloc(sizeof(Board));
  b->toString=&toStringBoard;

  //INIT LOCATIONS
  int i,j=0;

  for(i=0 ; i<=H ; i++){
    for(j=0 ; j<=h ; j++){
      b->locations[i][j] = initLocation( b->locations[i][j], i, j );
    }
  }

  //INIT PLAYERS:
  b->white = initPlayer("white");
  b->black = initPlayer("black");

  printf("Players @ %s & %x\n",b->black->color,b->black);
  printf("Players @ %X & %x\n",b->black->getColor,b->black);
  
  return b;
}


char* toStringBoard(BoardPtr b){

  int i,j=0;
  char* s="";

  for(i=0 ; i<=H ; i++){
    for(j=0 ; j<=h ; j++){
      LocationPtr lp=b->locations[i][j];
      s=mystrcat(s, lp->toString(lp) );
    }
    s=mystrcat(s,"\n");
  }
  
  
  return s;

}
