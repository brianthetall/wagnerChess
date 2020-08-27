enum {KING=1,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};


typedef struct piece* PiecePtr;

typedef struct piece{
  int pieceType;//undefined
  void* location;//LocPtr
  char* color;

  char* (*getColor)(PiecePtr p);
} Piece;


PiecePtr initPiece(int, char*);//the only w/o reference to self!
char* getColor(PiecePtr);


