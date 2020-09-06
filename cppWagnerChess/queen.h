#include "piece.h"

class Queen : public Piece{

public:
  Queen(PieceType pt,Location* l):Piece{pt,l}{}
  ~Queen(){}
  vector<Location> getMoves() override;  

};
