#ifndef PIECE
#define PIECE

enum {KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};
enum {VIRGIN,SCREWED};

typedef struct piece* PiecePtr;

typedef struct piece{

  int virgin;
  int pieceType;
  void* location;//LocPtr
  char* color;

  char* (*getColor)(PiecePtr p);
  char* (*toString)(PiecePtr p);
  char* (*getType)(PiecePtr p);
  int (*type)(PiecePtr P);
  void (*sex)(PiecePtr P);
  void (*unsex)(PiecePtr P);
  int (*hasMoved)(PiecePtr P);
  
} Piece;

#endif

PiecePtr initPiece(int, char*);//the only w/o reference to self!
char* getColor(PiecePtr);
char* toStringPiece(PiecePtr);
char* getType(PiecePtr);
int getEnumType(PiecePtr);
void sex(PiecePtr);
void unsex(PiecePtr);
int hasMoved(PiecePtr);
