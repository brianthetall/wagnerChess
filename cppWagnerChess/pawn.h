#include "piece.h"

class Pawn : public Piece{

public:
  Pawn(PieceType pt,Location* l):Piece{pt,l}{}
  ~Pawn(){}
  vector<Location> getMoves() override;  

};
