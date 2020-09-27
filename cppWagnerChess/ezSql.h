#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include <mariadb/mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

class EzSql{

  MYSQL *connector;
  string user,passwd;

  void verifyConnection(void);

 public:
  EzSql(string username,string password):user{username},passwd{password}{

    connector = mysql_init(NULL);

    if (connector == NULL){
      cout<<mysql_error(connector)<<endl;
    }

    if (mysql_real_connect(connector, "localhost", "user", "passwd", NULL, 0, NULL, 0) == NULL) {
      cout<<mysql_error(connector)<<endl;
      mysql_close(connector);
    }  

  };

  void createDb(string dbName);
  void createTable(string db,string tableName);
  void insertJsonFile(string fileName);
  string selectElement(string name);
  map<string,string> selectElementMap(string name);
  void dropDb(string dbName);
  void dropTable(string tableName);
  void close(void);
  string status(void);

};
