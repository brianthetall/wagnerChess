#include <bits/unique_ptr.h>
#include <string>

using namespace std;

class Location;

class Piece{
  string name;
  unique_ptr<Location> l;
public:
  Piece(string name);
  string toString() const;
};
