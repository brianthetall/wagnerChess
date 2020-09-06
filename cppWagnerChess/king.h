#pragma once

#include "piece.h"

class King : public Piece{

public:
  King(PieceType pt,Location* l):Piece{pt,l}{}
  ~King(){}
  vector<Location> getMoves() override;  

};
