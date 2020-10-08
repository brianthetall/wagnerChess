#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <ezSql.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;
enum rows{A,B,C,D,E,F,G,H};

EzSql* getDb(void){

  string user,passwd;
  ifstream passwdFile;
  passwdFile.open("/usr/home/user/gitRepos/games/cppWagnerChess/password.file");//need full path as CGI will be executing in another path
  getline(passwdFile,user);
  getline(passwdFile,passwd);
  passwdFile.close();

  //Game must now rely on SQL for state data; CGI
  return new EzSql{user,passwd};
  
}

void createTables(void){

  EzSql *sql=getDb();

  //clear out anything from a previous game:
  sql->dropTable("chess","board");
  sql->dropTable("chess","graveyard");
  sql->dropTable("chess","moves");
  //create new tables:
  sql->createTable("chess","board");
  sql->createTable("chess","graveyard");
  sql->createTable("chess","moves");

  sql->close();

}

void createLocations(void){

  EzSql *sql=getDb();
  sql->selectDb("chess");//use chess;
  ostringstream oss{""};
  char alpha='A';
  int i;
  
  for( ; alpha <= 'H' ; alpha++){
    for(i=0 ; i <= H ; i++){

      oss<<alpha<<i;
      //populate the DB with locations:
      stringstream ss{""};
      ss<<"{\"name\":\""<<oss.str()<<"\",\"piece\":\"null\",\"color\":\"null\"}";
      if(sql->insertJsonStream("board",ss))
	cout << "error writing to SQL <br>"<<endl;
      //cout<<"\nInserted?: "<<ss.str()<<"<br>"<<endl;
      oss.str("");//clear the stream
    }
  }

  sql->close();

}

void placePieces(void){

  using boost::property_tree::ptree;
  
  EzSql *sql=getDb();
  sql->selectDb("chess");//use chess;
  //open a json file that describes the initial locations of the pieces
  ifstream pieceLocationJson;
  pieceLocationJson.open("/usr/home/user/gitRepos/games/cppWagnerChess/initPieceLocations.json");

  //parse JSON
  /*
    name:A2
    piece:null
    color:null
    name:A3
    piece:rook1
    color:black
  */
  ptree pt;
  read_json(pieceLocationJson, pt);
  for(auto& dict:pt){

    string name;
    map<string,string> props{};
    
    for(auto& entry:dict.second){
      //cout<<entry.first<<":"<<entry.second.get_value <std::string>() <<"<br>";

      if(entry.first=="name")
	name=entry.second.get_value <string>();
      else if(entry.first=="piece")
	props["piece"]=entry.second.get_value <string>();
      else if(entry.first=="color")
	props["color"]=entry.second.get_value <string>();
      
    }

    //update SQL entry @ `name`
    sql->updateJsonEntry("board",name,props);
  }

  pieceLocationJson.close();
  sql->close();
}

int main(void){

  
  cout << "Content-type:text/html\r\n\r\n";
  cout << "<html>\n";
  cout << "<head>\n";
  cout << "<title>CGI Wagner Chess</title>\n";
  cout << "</head>\n";
  cout << "<body>\n";
  cout << "New Game!<br>Making Board...<br>";

  createTables();
  createLocations();
  placePieces();

}
