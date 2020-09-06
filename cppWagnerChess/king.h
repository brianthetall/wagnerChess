#include "piece.h"

class King : public Piece{

public:
  King(PieceType pt):Piece{pt}{}
  vector<Location> getMoves() override;  

};
