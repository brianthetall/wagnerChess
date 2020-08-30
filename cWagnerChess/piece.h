#ifndef PIECE
#define PIECE

enum {KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};


typedef struct piece* PiecePtr;

typedef struct piece{

  int pieceType;
  void* location;//LocPtr
  char* color;

  char* (*getColor)(PiecePtr p);
  char* (*toString)(PiecePtr p);
  char* (*getType)(PiecePtr p);
  int (*type)(PiecePtr P);
  
} Piece;

#endif

PiecePtr initPiece(int, char*);//the only w/o reference to self!
char* getColor(PiecePtr);
char* toStringPiece(PiecePtr);
char* getType(PiecePtr);
int getEnumType(PiecePtr);
