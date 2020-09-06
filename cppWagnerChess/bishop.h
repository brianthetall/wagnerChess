#include "piece.h"

class Bishop : public Piece{

public:
 Bishop(PieceType pt,Color c,Location* l):Piece{pt,c,l}{}
  ~Bishop(){}
  vector<Location*> getMoves() override;  

};
