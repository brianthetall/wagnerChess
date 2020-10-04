#include "ezSql.h"

int EzSql::createDb(const string dbName){

  verifyConnection();
  stringstream ss{""};
  ss<<"CREATE DATABASE "<<dbName;
  //cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    return 1;
    //cout<<mysql_error(connector)<<endl;
  }
  return 0;
}

int EzSql::selectDb(const string db){

  verifyConnection();
  stringstream ss{""};
  ss<<"USE "<<db<<";"<<endl;

  if (mysql_query(connector, ss.str().data() )){
    return 1;
    //cout<<mysql_error(connector)<<endl;
  }
  return 0;
}

//creats a table of JSON elements with varchar names
int EzSql::createTable(const string db, const string tableName){

  selectDb(db);
  
  verifyConnection();  
  stringstream ss{""};
  ss.str("");
  ss<<"CREATE TABLE "<<tableName<<"(";
  ss<<"element JSON,";
  ss<<"name VARCHAR(128) primary key";
  ss<<");";
  
  cout<<ss.str().data()<<"<br>"<<endl;
  if (mysql_query(connector, ss.str().data() )){
    return 1;
    //cout<<mysql_error(connector)<<endl;
  }
  return 0;
}

//insert entry into a JSON table
//insert into partsTable(name,element) values('levelSensor0','{"name":"levelSensor0","level":70,"power":24}');
//expects the caller to:  std::ifstream jsonFile(fileName);
//or std::istringstream
int EzSql::insertJsonStream(const string table, sstream& jsonStream){

  using boost::property_tree::ptree;

  string temp{""};

  cout<<jsonStream.str()<<"<br>"<<endl;
 
  bool first=true;
  std::string name,insertCmd;

  std::stringstream ss{""},ss2{""},nameStream{""};
  
  ptree pt;
  read_json(jsonStream, pt);
    
  for (auto & array_element: pt) {

    ss<<"INSERT INTO "<<table<<" (name,element) VALUES('";
    
    for (auto & property: array_element.second) {

      cout << "1st prop="<<property.first<<"<br>";
      
      if(first)
	ss2<<"\""<<property.first<<"\":\""<<property.second.get_value < std::string > ()<<"\"";
      else
	ss2<<",\""<<property.first<<"\":\""<<property.second.get_value < std::string > ()<<"\"";
      
      if(property.first == "name"){
	nameStream<<property.second.get_value < std::string > ();
	name=nameStream.str();
	nameStream.str("");
      }
      first=false;

    }
    
    ss<<name<<"','{"<<ss2.str()<<"}');";

    cout<<ss.str()<<"<br>"<<endl;
    
    insertCmd=ss.str();
    ss.str("");
    ss2.str("");
    nameStream.str("");
    first=true;

    if (mysql_query(connector, insertCmd.data() ))
      return 1;
      //cout<<mysql_error(connector)<<endl;
      
  }

  return 0;
}

string EzSql::selectElement(const string table,const string name){

  stringstream ss{""};
  ss<<"select * from "<<table<<" where name='"<<name<<"';";

  if (mysql_query(connector, ss.str().data() ))
    throw sqlException(string{mysql_error(connector)});
      
  MYSQL_RES *result=mysql_store_result(connector);
  MYSQL_ROW row;

  row=mysql_fetch_row(result);
  return row[0];
}

map<string,string> EzSql::selectElementMap(const string table,const string name){

  stringstream ss{""};
  ss<<this->selectElement(table,name);
  //cout<<"debug="<<ss.str()<<endl;
  
  boost::property_tree::ptree pt;
  read_json(ss,pt);

  map<string,string> retval{};
  //define the map by traversing the ptree:
  for(auto& array_element : pt)
    retval[array_element.first]=array_element.second.get_value < std::string > ();

  /*
  for(auto& s : retval)
    cout<<s.first<<":"<<s.second<<endl;
  */

  return retval;
  
}

int EzSql::dropDb(const string dbName){

  verifyConnection();
  stringstream ss{""};
  ss<<"DROP DATABASE "<<dbName;
  //  cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    //cout<<mysql_error(connector)<<endl;
    return 1;
  }
  return 0;
}

int EzSql::dropTable(const string db,const string tableName){

  selectDb(db);
  
  verifyConnection();
  stringstream ss{""};
  ss<<"DROP TABLE "<<tableName;
  //cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    //cout<<mysql_error(connector)<<endl;
    return 1;
  }  
  return 0;
}

void EzSql::close(void){
  mysql_close(connector);
}

string EzSql::status(void){
  string retval{ mysql_stat(connector) };
  return retval;
}

inline void EzSql::verifyConnection(void){
  //ping the db, if fail, reconnect
  if(mysql_ping(connector))
    mariadb_reconnect(connector);
}

/*
https://mariadb.com/kb/en/mysql_query/
*/
