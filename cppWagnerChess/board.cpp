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

  cout<<player["white"]->toString();
  cout<<player["black"]->toString();
  
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

MoveOutcome Board::move(string l,string lnew,string color){

  Color movingColor = color=="white" ? Color::WHITE : Color::BLACK;
  Location *start,*dest;
  Piece* piece;
  Piece* temp;
  vector<Location*> destinations;
  
  try{
    start=locations[l];
    dest=locations[lnew];
    if(start==nullptr || dest==nullptr)
      throw InvalidLocation{};
  }
  catch(InvalidLocation e){
    cout<<e.print()<<endl;
    return MoveOutcome::ILLEGAL_MOVE;
  }

  try{
    piece = start->getPiece();
    if(piece==nullptr)
      throw NotYourPiece{};
    if (piece->getColor()!=movingColor)
      throw NotYourPiece{};
  }catch(NotYourPiece e){
    cout<<e.print()<<endl;
    return MoveOutcome::NOT_YOUR_PIECE;
  }

  destinations = piece->getMoves();
  for(auto& d : destinations){
    cout<<d->toString()<<endl;
    if(d==dest){
      //move the piece
      temp = dest->getPiece()==nullptr?nullptr:dest->getPiece();//backup if event of check
      dest->setPiece(piece);
      start->clearPiece();
      piece->setLocation(dest);
      piece->sex();

    }
  }
  
  //need to look for Check....
  try{
    if(isInCheck(movingColor)){
      throw InCheck{};
    }
  }catch(InCheck e){
      cout << e.print() << endl;
      start->setPiece(piece);
      dest->setPiece(temp);
      if(temp!=nullptr)
	temp->setLocation(dest);
      piece->setLocation(start);
      if(!piece->isWhore())//whore is set after the second move; it is a latch
	piece->unsex();

      return MoveOutcome::IN_CHECK;

    }
    
  return MoveOutcome::ACCEPTED;
}


bool Board::isInCheck(Color c){
  
  vector<Piece*> enemyPieces{};//max number of pieces
  Piece* king;
  Piece* p;//temp pointer
  
  for(auto& l : locations){

    if(l.second->getPiece()!=nullptr){

      p=l.second->getPiece();
      
      if ( p->getColor() != c ){
	enemyPieces.push_back( p );//store the piece in the vector
      }else if ( p->pieceType() == PieceType::KING ){
	king = p;
      }
    }
  }

  cout<<"enemy piece vector size="<<enemyPieces.size()<<endl;
  
  for(Piece* piece : enemyPieces){
    vector<Location*> moves=piece->getMoves();
    cout<<"piece===="<<piece->toString();
    for(auto& l : moves){

      if ( l == king->getLocation() )
	return true;

    }
    
  }
  cout<<"King: "<<king->toString()<<endl;

  return false;
}
