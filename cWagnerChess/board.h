#include "player.h"
#include "location.h"
#include <stdlib.h>
#include "myString.h"

#define KING 0
#define QUEEN 1
#define BISHOP 2
#define KNIGHT 3
#define ROOK 4
#define PAWN1 5
#define PAWN2 6
#define PAWN3 7
#define PAWN4 8
#define PAWN5 9
#define PAWN6 10
#define PAWN7 11
#define PAWN8 12
#define BISHOP2 13
#define KNIGHT2 14
#define ROOK2 15

#define LEGAL_MOVE 0
#define NOT_YOUR_PIECE 1
#define ILLEGAL_MOVE_EXCEPTION 2
#define IN_CHECK_EXCEPTION 3
#define INVALID_INPUT_EXCEPTION 0
#define LEGAL_INPUT 1

typedef struct board* BoardPtr;
typedef struct board{
  PlayerPtr white;
  PlayerPtr black;
  LocationPtr locations[8][8];
  char* (*toString)(BoardPtr b);
  int (*move)(BoardPtr b,char* loc,char* locNew,char* color);
  
} Board;

BoardPtr initBoard();
void interconnectLocations(BoardPtr);
char* toStringBoard(BoardPtr);
int move(BoardPtr,char*,char*,char*);
int getCol(char*);
int getRow(char*);
void clearLinkedList(BoardPtr);
int inCheck(BoardPtr,char*);//char* is color
