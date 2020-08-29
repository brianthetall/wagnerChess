#include "board.h"

BoardPtr initBoard(){

  BoardPtr b = (BoardPtr)malloc(sizeof(Board));
  b->toString=&toStringBoard;
  b->move=&move;

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

  PiecePtr* blacks = b->black->pieces;
  PiecePtr* whites = b->white->pieces;

  b->locations[B][7]->setPiece(b->locations[B][7],blacks[KING]);
  b->locations[A][6]->setPiece(b->locations[A][6],blacks[QUEEN]);
  b->locations[A][5]->setPiece(b->locations[A][5],blacks[BISHOP]);
  b->locations[A][4]->setPiece(b->locations[A][4],blacks[KNIGHT]);
  b->locations[A][3]->setPiece(b->locations[A][3],blacks[ROOK]);
  b->locations[A][7]->setPiece(b->locations[A][7],blacks[PAWN1]);
  b->locations[C][6]->setPiece(b->locations[C][6],blacks[PAWN2]);
  b->locations[B][5]->setPiece(b->locations[B][5],blacks[PAWN3]);
  b->locations[B][4]->setPiece(b->locations[B][4],blacks[PAWN4]);
  b->locations[C][5]->setPiece(b->locations[C][5],blacks[PAWN5]);
  b->locations[D][4]->setPiece(b->locations[D][4],blacks[PAWN6]);
  b->locations[B][6]->setPiece(b->locations[B][6],blacks[PAWN7]);
  b->locations[D][6]->setPiece(b->locations[D][6],blacks[PAWN8]);
  b->locations[C][7]->setPiece(b->locations[C][7],blacks[BISHOP2]);
  b->locations[D][7]->setPiece(b->locations[D][7],blacks[KNIGHT2]);
  b->locations[E][7]->setPiece(b->locations[E][7],blacks[ROOK2]);
  
  //WHITES
  b->locations[H][1]->setPiece(b->locations[H][1],whites[KING]);
  b->locations[G][0]->setPiece(b->locations[G][0],whites[QUEEN]);
  b->locations[H][2]->setPiece(b->locations[H][2],whites[BISHOP]);
  b->locations[H][3]->setPiece(b->locations[H][3],whites[KNIGHT]);
  b->locations[H][4]->setPiece(b->locations[H][4],whites[ROOK]);
  b->locations[H][0]->setPiece(b->locations[H][0],whites[PAWN1]);
  b->locations[F][1]->setPiece(b->locations[F][1],whites[PAWN2]);
  b->locations[G][2]->setPiece(b->locations[G][2],whites[PAWN3]);
  b->locations[E][3]->setPiece(b->locations[E][3],whites[PAWN4]);
  b->locations[F][2]->setPiece(b->locations[F][2],whites[PAWN5]);
  b->locations[G][3]->setPiece(b->locations[G][3],whites[PAWN6]);
  b->locations[G][1]->setPiece(b->locations[G][1],whites[PAWN7]);
  b->locations[E][1]->setPiece(b->locations[E][1],whites[PAWN8]);
  b->locations[F][0]->setPiece(b->locations[F][0],whites[BISHOP2]);
  b->locations[E][0]->setPiece(b->locations[E][0],whites[KNIGHT2]);
  b->locations[D][0]->setPiece(b->locations[D][0],whites[ROOK2]);
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

int move(BoardPtr b, char* loc, char* locNew,char* color){
  PiecePtr p=b->locations[getCol(loc)][getRow(loc)]->getPiece(b->locations[getCol(loc)][getRow(loc)]);
  printf("Piece @ %d%d?\n",getCol(loc),getRow(loc));
  printf("DestLocation @ %d%d\n",getCol(locNew),getRow(locNew));

  if (p!=NULL)
    printf("%s\n",p->toString(p));
  
  return NOT_YOUR_PIECE;
  return ILLEGAL_MOVE_EXCEPTION;
  return IN_CHECK_EXCEPTION;
  return LEGAL_MOVE;
}

int getCol(char* loc){
  switch(loc[0]){
  case 'A':
    return 0;
  case 'B':
    return 1;
  case 'C':
    return 2;
  case 'D':
    return 3;
  case 'E':
    return 4;
  case 'F':
    return 5;
  case 'G':
    return 6;
  case 'H':
    return 7;
  }
}

int getRow(char* loc){
  return atoi(&loc[1]);
}
