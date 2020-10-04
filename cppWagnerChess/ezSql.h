#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <mysql/mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <sqlException.h>

using namespace std;

class EzSql{

private:
  
  MYSQL *connector;
  string user,passwd;

  inline void verifyConnection(void);

  
 public:
  EzSql(string username,string password):user{username},passwd{password}{

    connector = mysql_init(NULL);

    if (connector == NULL){
      cout<<mysql_error(connector)<<endl;
    }

    if (mysql_real_connect(connector, "localhost", user.data(), passwd.data(), NULL, 0, "/var/run/mysql/mysql.sock", 0) == NULL) {
      cout<<mysql_error(connector)<<endl;
      mysql_close(connector);
    }  

  };

  int createDb(const string dbName);
  int selectDb(const string db);
  int createTable(const string db,const string tableName);
  int insertJsonStream(const string table, sstream& jsonStream);
  string selectElement(const string table, const string name);
  map<string,string> selectElementMap(const string table, const string name);
  int dropDb(const string dbName);
  int dropTable(const string db, const string tableName);
  void close(void);
  string status(void);

};
