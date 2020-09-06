#include "piece.h"

class Queen : public Piece{

public:
  Queen(PieceType pt):Piece{pt}{}
  ~Queen(){}
  vector<Location> getMoves() override;  

};
