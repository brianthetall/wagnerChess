#pragma once

#include "piece.h"

class King : public Piece{

public:
 King(PieceType pt,Color c,Location* l):Piece{pt,c,l}{}
  ~King(){}
  vector<Location*> getMoves() override;  

};
