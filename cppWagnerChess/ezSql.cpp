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
int EzSql::insertJsonStream(const string table, stringstream& jsonStream){

  using boost::property_tree::ptree;
 
  bool first=true;

  std::stringstream ss{""},ss2{""};
  
  ptree pt;
  read_json(jsonStream, pt);

  //insert into board (name,element) values('test1','{"ass":"hat"}');
  ss<<"INSERT INTO "<<table<<" (name,element) VALUES('";
  for (auto & array_element: pt) {

    if(array_element.first=="name"){
      ss<<array_element.second.get_value <std::string>()<<"','{";
    }else{
      if(first)
	ss2<<"\""<<array_element.first<<"\":\""<<array_element.second.get_value < std::string > ()<<"\"";
      else
	ss2<<",\""<<array_element.first<<"\":\""<<array_element.second.get_value < std::string > ()<<"\"";
      first=false;  
    }
    
    //cout <<"debug:"<< array_element.first << "  " << array_element.second.get_value <std::string>() << "<br>"<<endl;
  }

  ss<<ss2.str()<<"}');"<<endl;
  cout << "DEBUG:" << ss.str() <<"<br>"<<endl;
  
  if (mysql_query(connector, ss.str().data() )){
    cout<<mysql_error(connector)<<"<br>"<<endl;
    return 1;
    
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
