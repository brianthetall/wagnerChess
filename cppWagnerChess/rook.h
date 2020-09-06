#include "piece.h"

class Rook : public Piece{

public:
  Rook(PieceType pt):Piece{pt}{}
  ~Rook(){}
  vector<Location> getMoves() override;  

};
