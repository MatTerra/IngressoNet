#include "mysqlhelper.h"

MySQLHelper::MySQLHelper(){
  connect();
  instance = this;
}

MySQLHelper::~MySQLHelper(){

}

MYSQL_RES MySQLHelper::query(std::string){
  MYSQL_RES res;
  return res;
}

void MySQLHelper::connect(){
  this->dbconn = mysql_init(nullptr);
  this->dbconn = mysql_real_connect(this->dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
  if (dbconn) {
     qDebug("Connected");
  }
}

MySQLHelper* MySQLHelper::getInstance(){
  if(instance == nullptr){
      instance = new MySQLHelper();
  }
  return instance;
}


