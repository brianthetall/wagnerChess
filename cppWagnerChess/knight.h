#include "piece.h"

class Knight : public Piece{

public:
  Knight(PieceType pt,Location* l):Piece{pt,l}{}
  ~Knight(){}
  vector<Location> getMoves() override;  

};
