#include "coordinate.h"

string Coordinate::toString() const{

  ostringstream oss{""};
  oss<<"\033[0;34m"<<row<<col<<"\033[0m ";
  return oss.str();
  
}

char Coordinate::getRow() const {return row;}
int Coordinate::getCol() const {return col;}
