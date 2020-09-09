#include "knight.h"
#include "location.h"

using namespace std;

vector<Location*>Knight::getMoves(){

  Location *current,*currentBackup;
  Piece *p;
  vector<Location*> moves{};

  map<string,vector<string>> dirs;
  vector<string> ns={"n","s"};
  vector<string> ew={"e","w"};

  dirs["n"]=ew;
  dirs["s"]=ew;
  dirs["e"]=ns;
  dirs["w"]=ns;

  for(auto& dir : dirs){
    //cout<<"\nfirst="<<dir.first;
    //cout<<" second="<<dir.second[0]<<","<<dir.second[1]<<endl;
    current=location;
    current=location->neighbors[dir.first];
    if (current!=nullptr){
      current=current->neighbors[dir.first];
      
      if (current!=nullptr){
	
	currentBackup=current;
	current=current->neighbors[dir.second[0]];
	currentBackup=currentBackup->neighbors[dir.second[1]];

	current=checkIfValid(current);
	currentBackup=checkIfValid(currentBackup);

	if(current!=nullptr){ moves.push_back(current); }
	if(currentBackup!=nullptr){ moves.push_back(currentBackup); }

      }
    }
  }

  return moves;

}
