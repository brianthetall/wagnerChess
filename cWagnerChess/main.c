#include <stdio.h>
//#include "piece.h"
//#include "location.h"
#include "board.h"

#define PORT 2599

int main(int argc,char** argv){

  BoardPtr board=initBoard();
  printf("Board.toString:\n");
  printf("%s",board->toString(board));
  printf("%s\n", board->black->toString(board->black) );
  printf("%s\n", board->white->toString(board->white) );
  
  if(argc==1){
    printf("Must specify (c)lient or (s)erver. If client, must also provide IP address of server.\n");
    return -1;
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
    return -2;
  }
  
  return 0;
}
