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
  lp->toStringPlain=&toStringPlain;
  lp->setPiece=&setPiece;
  lp->clearPiece=&clearPiece;
  lp->getPiece=&getPiece;
  lp->memory=&printInterconnections;
  lp->isMoveLegal=&isMoveLegal;
  lp->possibleMoves=&possibleMoves;

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
    sprintf(retval, ANSI_COLOR_BLUE "%c%d" ANSI_COLOR_RESET,lp->col+65,lp->row);
  else{
    if( strcmp( lp->piece->getColor(lp->piece), "black" ) == 0  )
      sprintf(retval, ANSI_COLOR_RED "%s" ANSI_COLOR_RESET,lp->piece->toString(lp->piece));
    else
      sprintf(retval, ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET,lp->piece->toString(lp->piece));
  }
  return retval;
}


char* toStringPlain(LocationPtr lp){

  char* retval = (char*) calloc(sizeof(char),64);
  if(lp->piece==NULL)
    sprintf(retval,"%c%d",lp->col+65,lp->row);
  else{
    if( strcmp( lp->piece->getColor(lp->piece), "black" ) == 0  )
      sprintf(retval,"%s",lp->piece->toString(lp->piece));
    else
      sprintf(retval,"%s",lp->piece->toString(lp->piece));
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
LocationPtr isMoveLegal(PiecePtr p, LocationPtr location, LocationPtr locationNext){

  //printf("isMoveLegal:\n");
  LocationPtr legalMovesLinkedList;

  
  int type=p->type(p);
  switch(type){
  case ROOK:
    //printf("rook:\n");
    legalMovesLinkedList=rookMoves(p,location);
    break;
    
  case BISHOP:
    //printf("bishop\n");
    legalMovesLinkedList=bishopMoves(p,location);
    break;

  
  case KNIGHT:
    //printf("knight\n");
    legalMovesLinkedList=knightMoves(p,location);
    break;

  case QUEEN:
    //printf("queen\n");
    legalMovesLinkedList=queenMoves(p,location);
    break;

  case KING:
    //printf("king\n");
    legalMovesLinkedList=kingMoves(p,location);
    break;

  case PAWN:
    //printf("pawn\n");
    legalMovesLinkedList=pawnMoves(p,location);
    break;

  }
    
  LocationPtr temp=legalMovesLinkedList;
  while(temp != NULL){
    //printf("isMoveLegal: %s\n",temp->toString(temp));
    temp = temp->nextLocation;
  }

  
  //traverse the linked list, see if 'locationNext' is one of them
  while(1){
    if(locationNext==legalMovesLinkedList)
      return legalMovesLinkedList;
    if(legalMovesLinkedList==NULL)
      return NULL;
    legalMovesLinkedList = legalMovesLinkedList->nextLocation;
  }
  
  
  return 0;

}

//NEW: used for CHECK checking:
LocationPtr possibleMoves(PiecePtr p, LocationPtr location, LocationPtr locationNext){

  //printf("isMoveLegal:\n");
  LocationPtr legalMovesLinkedList;

  
  int type=p->type(p);
  switch(type){
  case ROOK:
    //printf("rook:\n");
    legalMovesLinkedList=rookMoves(p,location);
    break;
    
  case BISHOP:
    //printf("bishop\n");
    legalMovesLinkedList=bishopMoves(p,location);
    break;

  
  case KNIGHT:
    //printf("knight\n");
    legalMovesLinkedList=knightMoves(p,location);
    break;

  case QUEEN:
    //printf("queen\n");
    legalMovesLinkedList=queenMoves(p,location);
    break;

  case KING:
    //printf("king\n");
    legalMovesLinkedList=kingMoves(p,location);
    break;

  case PAWN:
    //printf("pawn\n");
    legalMovesLinkedList=pawnMoves(p,location);
    break;

  }
    
  LocationPtr temp=legalMovesLinkedList;
  while(temp != NULL){
    //printf("isMoveLegal: %s\n",temp->toString(temp));
    temp = temp->nextLocation;
  }

  return legalMovesLinkedList;
}


LocationPtr pawnMoves(PiecePtr p, LocationPtr lp){//return a list of LocationPtr linked
//head is the last added to the linked list
  LocationPtr retval=NULL,head=NULL,current=lp,temp=NULL;
  PiecePtr potentialEnemy=NULL;

  //printf("pawnMoves:\n");
  if( strcmp( p->getColor(p) , "white") == 0){

    //move NE
    current = current->ne==NULL ? NULL:current->ne;
    temp=checkLocation(current,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }

    //possibly take the second jump:
    if( temp != NULL && p->hasMoved(p)==VIRGIN ){
      temp = temp->ne==NULL ? NULL:temp->ne;
      temp=checkLocation(temp,p->getColor(p));
      if (retval==NULL && temp!=NULL){
	retval=temp;
	head=temp;
      }
      else if(temp!=NULL){
	head->nextLocation=temp;
	head=temp;
      }
    }
    
    
    //look for attack options N,E
    current=lp;
    temp=NULL;
    if(current->n!=NULL){
      potentialEnemy = current->n->getPiece(current->n);
      temp = potentialEnemy!=NULL && 0!=strcmp(p->getColor(p),potentialEnemy->getColor(potentialEnemy)) ? current->n : NULL;

      if (retval==NULL && temp!=NULL){
	retval=temp;
	head=temp;
      }
      else if(temp!=NULL){
	head->nextLocation=temp;
	head=temp;
      }
    }//END NORTH
    //attack east?
    current=lp;
    temp=NULL;
    if(current->e!=NULL){
      potentialEnemy = current->e->getPiece(current->e);
      temp = potentialEnemy!=NULL && 0!=strcmp(p->getColor(p),potentialEnemy->getColor(potentialEnemy)) ? current->e : NULL;

      if (retval==NULL && temp!=NULL){
	retval=temp;
	head=temp;
      }
      else if(temp!=NULL){
	head->nextLocation=temp;
	head=temp;
      }
    }//END EAST

    
  }
  else{//black
    //move SW
    current = current->sw==NULL ? NULL:current->sw;
    temp=checkLocation(current,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }

    //possibly take the second jump:
    if( temp != NULL && p->hasMoved(p)==VIRGIN ){
      temp = temp->sw==NULL ? NULL:temp->sw;
      temp=checkLocation(temp,p->getColor(p));
      if (retval==NULL && temp!=NULL){
	retval=temp;
	head=temp;
      }
      else if(temp!=NULL){
	head->nextLocation=temp;
	head=temp;
      }
    }

    
    //look for attack options S,W
    current=lp;
    temp=NULL;
    if(current->s!=NULL){
      potentialEnemy = current->s->getPiece(current->s);
      temp = potentialEnemy!=NULL && 0!=strcmp(p->getColor(p),potentialEnemy->getColor(potentialEnemy)) ? current->s : NULL;

      if (retval==NULL && temp!=NULL){
	retval=temp;
	head=temp;
      }
      else if(temp!=NULL){
	head->nextLocation=temp;
	head=temp;
      }
    }//END south
    //attack west?
    current=lp;
    temp=NULL;
    if(current->w!=NULL){
      potentialEnemy = current->w->getPiece(current->w);
      temp = potentialEnemy!=NULL && 0!=strcmp(p->getColor(p),potentialEnemy->getColor(potentialEnemy)) ? current->w : NULL;

      if (retval==NULL && temp!=NULL){
	retval=temp;
	head=temp;
      }
      else if(temp!=NULL){
	head->nextLocation=temp;
	head=temp;
      }
    }//END west
  }

  return retval;
}

LocationPtr rookMoves(PiecePtr p, LocationPtr lp){//return a list of LocationPtr linked

  //head is the last added to the linked list
  LocationPtr retval=NULL,head=NULL,current=lp,temp=NULL;

  //printf("rookMoves:\n");
  
  //check NORTH
  while(1){
    if( current->n == NULL )
      break;
    
    temp=checkLocation(current->n,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }
  }

  
  //check WEST
  current=lp;
  while(1){
    if( current->w == NULL )
      break;
    
    temp=checkLocation(current->w,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }

  }

  //check SOUTH
  current=lp;
  while(1){
    if( current->s == NULL )
      break;
    
    temp=checkLocation(current->s,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }
  }

  //CHECK EAST
  current=lp;
  while(1){
    if( current->e == NULL )
      break;
    
    temp=checkLocation(current->e,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }


  }
  
  
  return retval;
}

//change to bishop:
LocationPtr bishopMoves(PiecePtr p, LocationPtr lp){//return a list of LocationPtr linked

  //head is the last added to the linked list
  LocationPtr retval=NULL,head=NULL,current=lp,temp=NULL;

  //printf("bishopMoves:\n");
  
  //check NORTHW
  while(1){
    //printf("bishopMoves:while\n");
    if( current->nw == NULL )
      break;
    
    temp=checkLocation(current->nw,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }
  }

  
  //check SouthW
  current=lp;
  while(1){
    if( current->sw == NULL )
      break;
    
    temp=checkLocation(current->sw,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }

  }

  //check SOUTHEast
  current=lp;
  while(1){
    if( current->se == NULL )
      break;
    
    temp=checkLocation(current->se,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }
  }

  //CHECK NorthEAST
  current=lp;
  while(1){
    if( current->ne == NULL )
      break;
    
    temp=checkLocation(current->ne,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }


  }
    
  return retval;
}

//change to QUEEN:
LocationPtr queenMoves(PiecePtr p, LocationPtr lp){//return a list of LocationPtr linked

  //head is the last added to the linked list
  LocationPtr retval=NULL,head=NULL,current=lp,temp=NULL;

  //printf("queenMoves:\n");
  
  //check NORTH
  while(1){
    //printf("queenMoves:while\n");
    if( current->n == NULL )
      break;
    
    temp=checkLocation(current->n,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }
  }

  
  //check WEST
  current=lp;
  while(1){
    if( current->w == NULL )
      break;
    
    temp=checkLocation(current->w,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }

  }

  //check SOUTH
  current=lp;
  while(1){
    if( current->s == NULL )
      break;
    
    temp=checkLocation(current->s,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }
  }

  //CHECK EAST
  current=lp;
  while(1){
    if( current->e == NULL )
      break;
    
    temp=checkLocation(current->e,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }


  }
  
  
  //check NORTHW
  while(1){
    //printf("bishopMoves:while\n");
    if( current->nw == NULL )
      break;
    
    temp=checkLocation(current->nw,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }
  }

  
  //check SouthW
  current=lp;
  while(1){
    if( current->sw == NULL )
      break;
    
    temp=checkLocation(current->sw,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }

  }

  //check SOUTHEast
  current=lp;
  while(1){
    if( current->se == NULL )
      break;
    
    temp=checkLocation(current->se,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }
  }

  //CHECK NorthEAST
  current=lp;
  while(1){
    if( current->ne == NULL )
      break;
    
    temp=checkLocation(current->ne,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    else{//temp==NULL
      break;
    }

    if(head->getPiece(head)==NULL){
      current=head;
    }else{
      break;//there is a piece @ head; we cannot go through it
    }


  }
  
  return retval;
}

//change to king;
LocationPtr kingMoves(PiecePtr p, LocationPtr lp){//return a list of LocationPtr linked

  //head is the last added to the linked list
  LocationPtr retval=NULL,head=NULL,current=NULL,temp=NULL;

  //printf("kingMoves:\n");
  
  //check NORTH
  current=lp;

  if( current->n != NULL ){    
    temp=checkLocation(current->n,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    
  }
  
  //check WEST
  current=lp;

  if( current->w != NULL ){    
    temp=checkLocation(current->w,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    
  }
  
  //SOUTH
  current=lp;

  if( current->s != NULL ){    
    temp=checkLocation(current->s,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    
  }
  
  //EAST
  current=lp;

  if( current->e != NULL ){    
    temp=checkLocation(current->e,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    
  }
  
  //NW
  current=lp;

  if( current->nw != NULL ){    
    temp=checkLocation(current->nw,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    
  }
  
  //SW
  current=lp;

  if( current->sw != NULL ){    
    temp=checkLocation(current->sw,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    
  }
  
  //SE
  current=lp;

  if( current->se != NULL ){    
    temp=checkLocation(current->se,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    
  }
  
  //NE
  current=lp;

  if( current->ne != NULL ){    
    temp=checkLocation(current->ne,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    }
    
  }
  
  return retval;
}

LocationPtr knightMoves(PiecePtr p, LocationPtr lp){//return a list of LocationPtr linked

  //head is the last added to the linked list
  LocationPtr retval=NULL,head=NULL,current=lp,temp=NULL,left=NULL,right=NULL;

  //printf("knightMoves:\n");

  //check NORTH
  current=lp;
  left=right=NULL;
  current = current->n==NULL ? NULL : current->n;
  if(current!=NULL)
    current = current->n==NULL ? NULL : current->n;
  if(current!=NULL)
    left = current->w==NULL ? NULL : current->w;
  if(current!=NULL)
    right = current->e==NULL ? NULL : current->e;
  
  if (left!=NULL){
    temp=checkLocation(left,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    } 
  }//end left
  if (right!=NULL){
    temp=checkLocation(right,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    } 
  }//end right

  //EAST
  current=lp;
  left=right=NULL;
  current = current->e==NULL ? NULL : current->e;
  if(current!=NULL)
    current = current->e==NULL ? NULL : current->e;
  if(current!=NULL)
    left = current->s==NULL ? NULL : current->s;
  if(current!=NULL)
    right = current->n==NULL ? NULL : current->n;

  if (left!=NULL){
    temp=checkLocation(left,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    } 
  }//end left
  if (right!=NULL){
    temp=checkLocation(right,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    } 
  }//end right
  
  //SOUTH
  current=lp;
  left=right=NULL;
  current = current->s==NULL ? NULL : current->s;
  if(current!=NULL)
    current = current->s==NULL ? NULL : current->s;
  if(current!=NULL)
    left = current->e==NULL ? NULL : current->e;
  if(current!=NULL)
    right = current->w==NULL ? NULL : current->w;

  if (left!=NULL){
    temp=checkLocation(left,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    } 
  }//end left
  if (right!=NULL){
    temp=checkLocation(right,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    } 
  }//end right
  
  //WEST
  current=lp;
  left=right=NULL;
  current = current->w==NULL ? NULL : current->w;
  if(current!=NULL)
    current = current->w==NULL ? NULL : current->w;
  if(current!=NULL)
    left = current->s==NULL ? NULL : current->s;
  if(current!=NULL)
    right = current->n==NULL ? NULL : current->n;

  if (left!=NULL){
    temp=checkLocation(left,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    } 
  }//end left
  if (right!=NULL){
    temp=checkLocation(right,p->getColor(p));
    if (retval==NULL && temp!=NULL){
      retval=temp;
      head=temp;
    }
    else if(temp!=NULL){
      head->nextLocation=temp;
      head=temp;
    } 
  }//end right

  return retval;
}


//return NULL if same color piece or if 
LocationPtr checkLocation(LocationPtr lp,char *color){
  if(lp->getPiece(lp) == NULL)
    return lp;//empty location
  if( 0== strcmp(lp->getPiece(lp)->getColor(lp->getPiece(lp)) , color))
    return NULL;
  else
    return lp;//enemy piece is there
}
