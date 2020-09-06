#include "piece.h"

class Bishop : public Piece{

public:
  Bishop(PieceType pt,Location& l):Piece{pt,l}{}
  ~Bishop(){}
  vector<Location> getMoves() override;  

};
