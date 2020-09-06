#include "piece.h"

class Rook : public Piece{

public:
 Rook(PieceType pt,Color c,Location* l):Piece{pt,c,l}{}
  ~Rook(){}
  vector<Location*> getMoves() override;  

};
