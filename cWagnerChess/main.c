#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "piece.h"
//#include "location.h"
#include "board.h"

#define PORT 2599

int checkInput(char*);

int checkInput(char* location){

  //printf("CheckInput: %d<=%d<=%d %d<=%d<=%d\n", 'A',location[0],'H','0',location[1],'7');
  if ('A' <= location[0] && location[0] <= 'H' && '0' <= location[1] && location[1]<= '7'){
    return 1;
  }
  return INVALID_INPUT_EXCEPTION;
}

int main(int argc,char** argv){

  int moveResult=0;
  char* input=(char*)malloc(10);
  char* loc=(char*)malloc(4);//for user input via scanf
  char* locNew=(char*)malloc(4);//for user input via scanf
  
  BoardPtr board=initBoard();

  //printf("%s\n", board->black->toString(board->black) );
  //printf("%s\n", board->white->toString(board->white) );
  

  //CONNECTION FSM STUFF:

  if(argc==1){
    printf("Must specify (c)lient or (s)erver. If client, must also provide IP address of server.\n");
    //return -1;
  }
  else if (argc==2 && *++argv=="s"){
    //setup Server socket
  }
  else if(argc==3 && *++argv=="c"){
    char *serverIP=*++argv;
    //open socket connection to server
  }
  else{
    printf("Try Again...\n");
    //return -2;
  }

  while(1){
    while(1){
      printf("%s",board->toString(board));
      printf("White Move:");
      scanf("%s",input);
      loc=strtok(input,",");
      locNew=strtok(NULL,",");

      if(loc==NULL || locNew==NULL){
	printf("INVALID_INPUT_EXCEPTION\n");
	continue;
      }
      
      if(checkInput(loc)==LEGAL_INPUT && checkInput(locNew)==LEGAL_INPUT)
	printf("LegalInput\n");
      else{
	printf("INVALID_INPUT_EXCEPTION\n");
	continue;
      }
      
      //printf("Main: %s %s\n",loc,locNew);
      
      moveResult=board->move(board,loc,locNew,"white");
      
      if (moveResult!=LEGAL_MOVE){
	if (moveResult==NOT_YOUR_PIECE){
	  printf("\nNOT_YOUR_PIECE\n");
	  continue;
	}else if(moveResult==ILLEGAL_MOVE_EXCEPTION){
	  printf("\nILLEGAL_MOVE_EXCEPTION\n");
	  continue;
	}else if(moveResult==IN_CHECK_EXCEPTION){
	  printf("\nIN_CHECK_EXCEPTION\n");
	  continue;
	}else{
	  printf("\nException\n");
	  continue;
	}
      }
      break;//all good
    }

    while(1){
      printf("%s",board->toString(board));
      printf("Black Move:");
      scanf("%s",input);
      loc=strtok(input,",");
      locNew=strtok(NULL,",");
    
      printf("%s %s",loc,locNew);
      moveResult=board->move(board,loc,locNew,"black");
      if (moveResult!=0){
	if (moveResult==NOT_YOUR_PIECE){
	  printf("NOT YOUR PIECE\n");
	  continue;
	}else if(moveResult==ILLEGAL_MOVE_EXCEPTION){
	  printf("ILLEGAL_MOVE_EXCEPTION\n");
	  continue;
	}else if(moveResult==IN_CHECK_EXCEPTION){
	  printf("IN_CHECK_EXCEPTION\n");
	  continue;
	}else{
	  printf("Exception\n");
	  continue;
	}
      }
      break;//all good

    }

  }
  
  return 0;
}
