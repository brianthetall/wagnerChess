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
  lp->memory=&printInterconnections;

  lp->n=NULL;
  lp->nw=NULL;
  lp->w=NULL;
  lp->sw=NULL;
  lp->s=NULL;
  lp->se=NULL;
  lp->e=NULL;
  lp->ne=NULL;

  lp->nextLocation=NULL;//linked list for returning arbitrary # of locations
  
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

char* printInterconnections(LocationPtr lp){
  char* ret=(char*)malloc(1024);
  strcat(ret,"ret");
  
  char* n=lp->n==NULL ? "n":lp->n->toString(lp->n);
  printf("\n>%s<\n",n);
  
  char* nw=lp->nw==NULL ? "nw":lp->nw->toString(lp->nw);
  printf(">%s<\n",nw);
  
  char* w=lp->w==NULL ? "w":lp->w->toString(lp->w);
  printf(">%s<\n",w);
  
  char* sw=lp->sw==NULL ? "sw":lp->sw->toString(lp->sw);
  printf(">%s<\n",sw);
  
  char* s=lp->s==NULL ? "s":lp->s->toString(lp->s);
  printf(">%s<\n",s);
  
  char* se=lp->se==NULL ? "se":lp->se->toString(lp->se);
  printf(">%s<\n",se);
  
  char* e=lp->e==NULL ? "e":lp->e->toString(lp->e);
  printf(">%s<\n",e);
   
  char* ne=lp->ne==NULL ? "ne":lp->ne->toString(lp->ne);
  printf(">%s<\n",ne);

  
  printf("%X %X %X %X %X %X %X %X\n",lp->n,lp->nw,lp->w,lp->sw,lp->s,lp->se,lp->e,lp->ne);
  //  sprintf(ret,"%s %s %s %s %s %s %s %s",n,nw,w,sw,s,se,e,ne);
  
  return ret;
}

//0false ;; 1true
int isMoveLegal(PiecePtr p, LocationPtr location, LocationPtr locationNext){

  int type=p->getType(p);
  
  
  switch(type){
  case ROOK:
    LocationPtr legalMovesLinkedList=rookMoves(p,location);
    break;
  }

  //traverse the linked list, see if 'locationNext' is one of them
  while(1){
    if(locationNext==legalMovesLinkedList)
      return 1;
    if(legalMovesLinkedList==NULL)
      return 0;
    legalMovesLinkedList = legalMovesLinkedList->nextLocation;
  }

  return 0;

}

LocationPtr rookMoves(PiecePtr p, LocationPtr lp){//return a list of LocationPtr linked

  LocationPtr retval=NULL,head=NULL;//head is the last added to the linked list

  //check NORTH
  while(1){
    if( lp->n == NULL )
      break;
    

  }

  //check WEST
  while(1){

  }

  //check SOUTH

  //CHECK EAST

  return retval;

}

//return NULL if same color piece or if 
LocationPtr checkLocation(LocationPtr lp){

}
