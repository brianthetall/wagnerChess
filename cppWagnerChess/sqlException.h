#include <string>

using namespace std;

class sqlException{
  string message;

public:
  sqlException(string m):message{m}{}
  string print(){return message;}
};
