#include "board.h"

Board::Board(){

  //Create Coordinates:
  int i=0;
  char alpha='A', digit[2];
  ostringstream oss{""};//,ios::ate to write at end
  
  for( ; alpha <= 'H' ; alpha++){
    for(i=0 ; i <= H ; i++){
      oss<<alpha<<i;
      locations[ oss.str() ]={Location{Coordinate{alpha,i}}};
      oss.str("");//clear the stream
    }
  }

  //Interconnect the locations
  for(alpha='A' ; alpha <= 'H' ; alpha++){
    for(i=0 ; i <= H ; i++){
      oss<<alpha<<i;
      locations[ oss.str() ].connectToNeighbors(locations);
    }
  }

  
  player["white"]=Player("white",locations);
  player["black"]=Player("black",locations);

}

string Board::toString() {

  return "board.toString:" + player["white"].toString() + " " + player["black"].toString() + '\n';
}
