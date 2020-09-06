#include "piece.h"

class Queen : public Piece{

public:
 Queen(PieceType pt,Color c,Location* l):Piece{pt,c,l}{}
  ~Queen(){}
  vector<Location*> getMoves() override;  

};
