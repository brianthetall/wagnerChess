#include <iostream>
#include <sstream>
#include <ezSql.h>

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

  EzSql *sql=getDb();
  sql->selectDb("chess");//use chess;
  //open a json file that describes the initial locations of the pieces
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
