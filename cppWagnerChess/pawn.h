#include "piece.h"

class Pawn : public Piece{

public:
  Pawn(PieceType pt):Piece{pt}{}
  ~Pawn(){}
  vector<Location> getMoves() override;  

};
