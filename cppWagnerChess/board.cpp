#include "board.h"

Board::Board():player{2},locations{64}{

  //Create Coordinates:
  int i=0;
  char alpha='A';
  ostringstream oss{""};//,ios::ate to write at end

  for( ; alpha <= 'H' ; alpha++){
    for(i=0 ; i <= H ; i++){
      oss<<alpha<<i;
      locations[ oss.str() ]={new Location{new Coordinate{alpha,i}}};
      oss.str("");//clear the stream
    }
  }

  
  //Interconnect the locations
  for(alpha='A' ; alpha <= 'H' ; alpha++){
    for(i=0 ; i <= H ; i++){
      oss<<alpha<<i;
      locations[ oss.str() ]->connectToNeighbors(locations);
      cout<<locations[ oss.str() ]->toString()<<":"<< locations[ oss.str() ]->toStringNeighbors()<<"\n";
      oss.str("");
    }
  }

  
  player["white"]=new Player("white",locations);
  player["black"]=new Player("black",locations);
  
}

string Board::toString() {

  ostringstream oss{""},oss2{""};
  oss << "board.toString:\n";
  int i;
  char alpha;
  for( alpha='A' ; alpha <= 'H' ; alpha++){
    for(i=0 ; i <= H ; i++){
      oss2<<alpha<<i;
      oss << locations[ oss2.str() ]->toString();
      oss2.str("");//clear the stream
    }
    oss<<'\n';
  }

  
  return oss.str();
}
