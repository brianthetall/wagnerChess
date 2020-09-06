#pragma once

#include "piece.h"

class King : public Piece{

public:
  King(PieceType pt):Piece{pt}{}
  ~King(){}
  vector<Location> getMoves() override;  

};
