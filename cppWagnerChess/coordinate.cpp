#include "coordinate.h"

string Coordinate::toString() const{

  ostringstream oss{""};
  oss<<"Row: "<<row<<" Column: "<<col<<'\n';
  return oss.str();
  
}
