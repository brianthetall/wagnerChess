#include "piece.h"

class Rook : public Piece{

public:
  Rook(PieceType pt,Location& l):Piece{pt,l}{}
  ~Rook(){}
  vector<Location> getMoves() override;  

};
