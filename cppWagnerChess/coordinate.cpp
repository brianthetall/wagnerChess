#include "coordinate.h"

string Coordinate::toString() const{

  ostringstream oss{""};
  oss<<""<<row<<col<<" ";//doesn't work w/o the leading pair of ""... wtf
  return oss.str();
  
}
