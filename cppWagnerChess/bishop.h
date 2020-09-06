#include "piece.h"

class Bishop : public Piece{

public:
  Bishop(PieceType pt):Piece{pt}{}
  ~Bishop(){}
  vector<Location> getMoves() override;  

};
