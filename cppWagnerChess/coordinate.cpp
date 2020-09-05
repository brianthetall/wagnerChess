#include "coordinate.h"


Coordinate::Coordinate(){
  row='A';
  col=0;
}

Coordinate::Coordinate(char row,int col){
  this->row=row;
  this->col=col;
}
