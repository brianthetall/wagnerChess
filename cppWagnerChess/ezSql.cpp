#include "ezSql.h"

void EzSql::createDb(string dbName){

  verifyConnection();
  stringstream ss{""};
  ss<<"CREATE DATABASE "<<dbName;
  cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    cout<<mysql_error(connector)<<endl;
  }
  
}

//creats a table of JSON elements with varchar names
void EzSql::createTable(string db, string tableName){

  verifyConnection();
  stringstream ss{""};
  ss<<"USE "<<db<<";"<<endl;

  cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    cout<<mysql_error(connector)<<endl;
  }

  ss.str("");
  ss<<"CREATE TABLE "<<tableName<<"(";
  ss<<"element JSON,";
  ss<<"name VARCHAR(128) primary key";
  ss<<");";
  
  cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    cout<<mysql_error(connector)<<endl;
  }

}

//insert entry into a JSON table
//insert into partsTable(name,element) values('levelSensor0','{"name":"levelSensor0","level":70,"power":24}');
void EzSql::insertJsonFile(string fileName){

  using boost::property_tree::ptree;

  bool first=true;
  std::string name,insertCmd;
  std::ifstream jsonFile(fileName);
  std::stringstream ss{""},ss2{""},nameStream{""};
  
  ptree pt;
  read_json(jsonFile, pt);
    
  for (auto & array_element: pt) {

    ss<<"INSERT INTO partsTable(name,element) VALUES('";
    
    for (auto & property: array_element.second) {

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
    cout<<ss.str()<<endl;
    insertCmd=ss.str();
    ss.str("");
    ss2.str("");
    nameStream.str("");
    first=true;

    if (mysql_query(connector, insertCmd.data() ))
      cout<<mysql_error(connector)<<endl;
      
  }

    
}

//can i return a json object instead?
string EzSql::selectElement(string name){

  stringstream ss{""};
  ss<<"select * from partsTable where name='"<<name<<"';";
  if (mysql_query(connector, ss.str().data() ))
    cout<<mysql_error(connector)<<endl;

  MYSQL_RES *result=mysql_store_result(connector);
  MYSQL_ROW row;

  row=mysql_fetch_row(result);
  return row[0];
}

map<string,string> EzSql::selectElementMap(string name){

  stringstream ss{""};
  ss<<this->selectElement(name);
  cout<<"debug="<<ss.str()<<endl;
  
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

void EzSql::dropDb(string dbName){

  verifyConnection();
  stringstream ss{""};
  ss<<"DROP DATABASE "<<dbName;
  cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    cout<<mysql_error(connector)<<endl;
  }
  
}

void EzSql::dropTable(string tableName){

  verifyConnection();
  stringstream ss{""};
  ss<<"DROP TABLE "<<tableName;
  cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    cout<<mysql_error(connector)<<endl;
  }  

}

void EzSql::close(void){
  mysql_close(connector);
}

string EzSql::status(void){
  string retval{ mysql_stat(connector) };
  return retval;
}

void EzSql::verifyConnection(void){
  //ping the db, if fail, reconnect
  if(mysql_ping(connector))
    mariadb_reconnect(connector);
}

/*

https://mariadb.com/kb/en/mysql_query/

*/
