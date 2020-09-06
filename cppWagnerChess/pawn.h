#include "piece.h"

class Pawn : public Piece{

public:
 Pawn(PieceType pt,Color c,Location* l):Piece{pt,c,l}{}
  ~Pawn(){}
  vector<Location> getMoves() override;  

};
