#include "coordinate.h"

Coordinate::Coordinate(char row,int col){
  this->row=row;
  this->col=col;
}

Coordinate::Coordinate(){
  row='A';
  col=0;
}
