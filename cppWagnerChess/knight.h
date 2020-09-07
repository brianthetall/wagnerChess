#include "piece.h"
#include <map>
#include <string>
#include <vector>

class Knight : public Piece{

public:
  Knight(PieceType pt,Color c,Location* l):Piece{pt,c,l}{}
  ~Knight(){}
  vector<Location*> getMoves() override;  

};
