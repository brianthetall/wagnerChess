#include "location.h"
#include "piece.h"

Location::Location(Coordinate* c){
  this->c=c;
  //cout << "Location@ " << this->c->toString();
}

Location& Location::setPiece(Piece* p){
  piece=p;
  //cout << "Piece Set=" << piece->toString()<<" @ "<<this->c->toString()<<'\n';
  return *this;
}

Piece* Location::getPiece(){
  return piece;
}

Location& Location::clearPiece(){
  piece=nullptr;
  return *this;
}

void Location::connectToNeighbors(unordered_map<string,Location*> locations ){

  int i=c->getCol();
  char alpha=c->getRow();
  char alphaPlus=alpha+1;
  char alphaMinus=alpha-1;
  ostringstream target{""};

  if(alpha=='A'){
    if(i==0){
      neighbors["se"]=locations["B1"];
      neighbors["e"]=locations["A1"];
      neighbors["s"]=locations["B0"];
    }else if(i<7){
      target<<alpha<<i-1;
      neighbors["w"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i-1;
      neighbors["sw"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i;
      neighbors["s"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i+1;
      neighbors["se"]=locations[target.str()]; target.str("");
      target<<alpha<<i+1;
      neighbors["e"]=locations[target.str()]; target.str("");
      
    }else{
      neighbors["w"]=locations["A6"];
      neighbors["sw"]=locations["B6"];
      neighbors["s"]=locations["B7"];
    }
  }
  else if(alpha<'H'){
    if(i==0){
      target<<alphaMinus<<i;
      neighbors["n"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i;
      neighbors["s"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i+1;
      neighbors["se"]=locations[target.str()]; target.str("");
      target<<alpha<<i+1;
      neighbors["e"]=locations[target.str()]; target.str("");
      target<<alphaMinus<<i+1;
      neighbors["ne"]=locations[target.str()]; target.str("");

    }else if(i<7){
      target<<alphaMinus<<i;
      neighbors["n"]=locations[target.str()]; target.str("");
      target<<alphaMinus<<i-1;
      neighbors["nw"]=locations[target.str()]; target.str("");
      target<<alpha<<i-1;
      neighbors["w"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i-1;
      neighbors["sw"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i;
      neighbors["s"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i+1;
      neighbors["se"]=locations[target.str()]; target.str("");
      target<<alpha<<i+1;
      neighbors["e"]=locations[target.str()]; target.str("");
      target<<alphaMinus<<i+1;
      neighbors["ne"]=locations[target.str()]; target.str("");
    }else{
      target<<alphaMinus<<i;
      neighbors["n"]=locations[target.str()]; target.str("");
      target<<alphaMinus<<i-1;
      neighbors["nw"]=locations[target.str()]; target.str("");
      target<<alpha<<i-1;
      neighbors["w"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i-1;
      neighbors["sw"]=locations[target.str()]; target.str("");
      target<<alphaPlus<<i;
      neighbors["s"]=locations[target.str()]; target.str("");
    }
  }
  else if(alpha=='H'){
    if(i==0){
      neighbors["n"]=locations["G0"];
      neighbors["ne"]=locations["G1"];
      neighbors["e"]=locations["H1"];
    }else if(i<7){
      target<<alpha<<i-1;
      neighbors["w"]=locations[target.str()]; target.str("");
      target<<alphaMinus<<i-1;
      neighbors["nw"]=locations[target.str()]; target.str("");
      target<<alphaMinus<<i;
      neighbors["n"]=locations[target.str()]; target.str("");
      target<<alphaMinus<<i+1;
      neighbors["ne"]=locations[target.str()]; target.str("");
      target<<alpha<<i+1;
      neighbors["e"]=locations[target.str()]; target.str("");
    }else{
      neighbors["n"]=locations["G7"];
      neighbors["nw"]=locations["G6"];
      neighbors["w"]=locations["H6"];
    }
  }
  
}

string Location::toString(void) const {return piece==nullptr ? c->toString() : piece->toString();}

string Location::toStringNeighbors(void) const{
  ostringstream retval{""};
  map<string,Location*>::iterator it;
  
  for( auto const& x : neighbors){
    if(x.second!=nullptr)
      retval<<x.second->toString()<<" ";
  }
  
  return retval.str();
}


					    
