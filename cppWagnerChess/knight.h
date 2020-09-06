#include "piece.h"

class Knight : public Piece{

public:
  Knight(PieceType pt):Piece{pt}{}
  ~Knight(){}
  vector<Location> getMoves() override;  

};
