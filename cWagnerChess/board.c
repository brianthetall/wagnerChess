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
      //printf("%d,%d@%X\n",i,j,b->locations[i][j]);
    }
  }

  interconnectLocations(b);

  /*
  for(i=0 ; i<=H ; i++){
    for(j=0 ; j<=h ; j++){
      printf("Memory[%d][%d]: %s\n",i,j,b->locations[i][j]->memory(b->locations[i][j]));
    }
  }
  */
  
  //INIT PLAYERS:
  b->white = initPlayer("white");
  b->black = initPlayer("black");

  PiecePtr* blacks = b->black->pieces;
  PiecePtr* whites = b->white->pieces;

  //BLACKS
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
    return A;
  case 'B':
    return B;
  case 'C':
    return C;
  case 'D':
    return D;
  case 'E':
    return E;
  case 'F':
    return F;
  case 'G':
    return G;
  case 'H':
    return H;
  }
}

int getRow(char* loc){
  return atoi(&loc[1]);
}

void interconnectLocations(BoardPtr bp){
  int col,row;
  LocationPtr lp;
  
  for(col=A;col<=H;col++){
    //printf("Col=%d\n",col);
    for(row=a;row<=h;row++){
      //printf("Row=%d\n",row);
      lp=bp->locations[col][row];
      if(col==A){
	if(row==a){
	  lp->se = bp->locations[col+1][row+1];
	  lp->e = bp->locations[col][row+1];
	  lp->s = bp->locations[col+1][row];
	  
	}else if(row<h){//if not H
	  lp->w = bp->locations[col][row-1];
	  lp->sw = bp->locations[col+1][row-1];
	  lp->s = bp->locations[col+1][row];
	  lp->se = bp->locations[col+1][row+1];
	  lp->e = bp->locations[col][row+1];
	  
	}else{//if h
	  lp->w = bp->locations[col][row-1];
	  lp->sw = bp->locations[col+1][row-1];
	  lp->s = bp->locations[col+1][row];
	}
      }//end if A

      else if(col<H){
	if(row==a){
	  lp->n = bp->locations[col-1][row];
	  lp->s = bp->locations[col+1][row];
	  lp->se = bp->locations[col+1][row+1];
	  lp->e = bp->locations[col][row+1];
	  lp->ne = bp->locations[col-1][row+1];

	}else if(row<h){
	  lp->n = bp->locations[col-1][row];
	  lp->nw = bp->locations[col-1][row-1];
	  lp->w = bp->locations[col][row-1];
	  lp->sw = bp->locations[col+1][row-1];
	  lp->s = bp->locations[col+1][row];
	  lp->se = bp->locations[col+1][row+1];
	  lp->e = bp->locations[col][row+1];
	  lp->ne = bp->locations[col-1][row+1];
	  
	}else{
	  lp->n = bp->locations[col-1][row];
	  lp->nw = bp->locations[col-1][row-1];
	  lp->w = bp->locations[col][row-1];
	  lp->sw = bp->locations[col+1][row-1];
	  lp->s = bp->locations[col+1][row];
	  
	}
      }

      else if(col==H){
	if(row==a){
	  lp->n = bp->locations[col-1][row];
	  lp->ne = bp->locations[col-1][row+1];
	  lp->e = bp->locations[col][row+1];
	  
	}else if(row<h){
	  lp->w = bp->locations[col][row-1];
	  lp->nw = bp->locations[col-1][row-1];
	  lp->n = bp->locations[col-1][row];
	  lp->ne = bp->locations[col-1][row+1];
	  lp->e = bp->locations[col][row+1];
	  
	}else{
	  lp->n = bp->locations[col-1][row];
	  lp->nw = bp->locations[col-1][row-1];
	  lp->w = bp->locations[col][row-1];
	  
	}

      }
    }
  }
}
