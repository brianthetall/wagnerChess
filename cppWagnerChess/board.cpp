#include "board.h"

Board::Board(){

  player.insert( make_pair("white", Player("white") ));
  //player["white"]=Player("white");
}

string Board::toString() {

  /*
  auto white=player["white"];
  cout<<sizeof(white);
  cout << &white;
  cout << white.toString();
  */

  return "board.toString:" + player["white"].toString();
}
