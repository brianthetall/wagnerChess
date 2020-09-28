#include "board.h"

Board::Board():player{2},locations{64}{

  string user,passwd;
  ifstream passwdFile;
  passwdFile.open("/usr/home/user/gitRepos/games/cppWagnerChess/password.file");//need full path as CGI will be executing in another path
  getline(passwdFile,user);
  getline(passwdFile,passwd);
  passwdFile.close();

  //Game must now rely on SQL for state data; CGI
  sql=new EzSql{user,passwd};
  //clear out anything from a previous game:
  sql->dropTable("chess","board");
  sql->dropTable("chess","graveyard");
  sql->dropTable("chess","moves");
  //create new tables:
  sql->createTable("chess","board");
  sql->createTable("chess","graveyard");
  sql->createTable("chess","moves");
  
  //Create Coordinates:
  int i=0;
  char alpha='A';
  ostringstream oss{""};//,ios::ate to write at end

  for( ; alpha <= 'H' ; alpha++){
    for(i=0 ; i <= H ; i++){
      oss<<alpha<<i;
      locations[ oss.str() ]={new Location{new Coordinate{alpha,i}}};

      //populate the DB with locations:
      stringstream ss{""};
      ss<<"{name:"<<oss.str()<<",piece:null,color,null}";
      sql->insertJsonStream("board",static_cast<iostream&>(ss));
	
      oss.str("");//clear the stream
    }
  }

  
  //Interconnect the locations
  for(alpha='A' ; alpha <= 'H' ; alpha++){
    for(i=0 ; i <= H ; i++){
      oss<<alpha<<i;
      locations[ oss.str() ]->connectToNeighbors(locations);
      //      cout<<locations[ oss.str() ]->toString()<<":"<< locations[ oss.str() ]->toStringNeighbors()<<"\n";
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
  char row='A';//increment every row & print

  oss<<"   ";//put numbers at top
  for(i=0;i<8;i++)
    oss<<i<<"  ";
  oss<<endl;
  
  for( alpha='A' ; alpha <= 'H' ; alpha++){
    oss<<row<<"  ";//put letter at left side
    for(i=0 ; i <= H ; i++){
      oss2<<alpha<<i;
      oss << locations[ oss2.str() ]->toString();
      oss2.str("");//clear the stream
    }
    oss<<" "<<row<<endl;//put Letter at right side
    row++;
  }

  oss<<"   ";//put numbers at bottom
  for(i=0;i<8;i++)
    oss<<i<<"  ";
  oss<<endl;
  
  return oss.str();
}

MoveOutcome Board::move(string l,string lnew,string color,string moveString){

  Color movingColor = color=="white" ? Color::WHITE : Color::BLACK;
  Color enemyColor = color=="black" ? Color::WHITE : Color::BLACK;
  Location *start,*dest;
  Piece* piece;
  Piece* temp;
  vector<Location*> destinations;
  
  try{
    start=locations.at(l);//use map::at else a default constructed element will be added is the key doesn't already exist..... wtf C++
    dest=locations.at(lnew);
    if(start==nullptr || dest==nullptr)
      throw InvalidLocation{};
  }
  catch(InvalidLocation e){
    cout<<e.print()<<endl;
    //gui->outputError(e.print());
    return MoveOutcome::ILLEGAL_MOVE;
  }catch(...){
    //gui->outputError("Illegal Input or Move");
    return MoveOutcome::ILLEGAL_MOVE;
  }
  
  try{
    piece = start->getPiece();
    if(piece==nullptr)
      throw NotYourPiece{};
    if (piece->getColor()!=movingColor)
      throw NotYourPiece{};
  }catch(NotYourPiece e){
    //gui->outputError(e.print());
    cout<<e.print()<<endl;
    return MoveOutcome::NOT_YOUR_PIECE;
  }
  
  destinations = piece->getMoves();

  try{
    if (find(destinations.begin(), destinations.end(), dest)!=destinations.end()){
      //move the piece
      temp = dest->getPiece()==nullptr?nullptr:dest->getPiece();//backup if event of check
      dest->setPiece(piece);
      start->clearPiece();
      piece->setLocation(dest);
      piece->sex();
      
    }
    else{
      //throw exception
      throw InvalidLocation{};
    }
  }catch(InvalidLocation e){
    cout << e.print() << endl;
    //gui->outputError(e.print());
    return MoveOutcome::ILLEGAL_MOVE;
  }
  
  //need to look for Check....
  try{
    if(isInCheck(movingColor)){
      throw InCheck{};
    }
  }catch(InCheck e){
    //cout << e.print() << endl;
    //gui->outputError(e.print());//output to the GUI
    start->setPiece(piece);
    dest->setPiece(temp);
    if(temp!=nullptr)
      temp->setLocation(dest);
    piece->setLocation(start);
    if(!piece->isWhore())//whore is set after the second move; it is a latch
      piece->unsex();
    
    return MoveOutcome::IN_CHECK;
    
  }

  Player *playerLosingPiece = enemyColor==Color::WHITE ? player["white"] : player["black"];
  Player *attacker = enemyColor==Color::BLACK ? player["white"] : player["black"];

  /*
  gui->graveyard( temp,playerLosingPiece,attacker );//safe to send nullptr for temp
  gui->movesUpdate(moveString);//passed as parameter from main()
  gui->outputError("");
  */
  
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
  
  for(Piece* piece : enemyPieces){
    vector<Location*> moves=piece->getMoves();

    for(auto& l : moves){
      
      if ( l == king->getLocation() )
	return true;

    }
    
  }

  return false;
}
