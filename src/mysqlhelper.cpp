#include "mysqlhelper.h"

MySQLHelper* MySQLHelper::instance=nullptr;
MYSQL* MySQLHelper::dbconn = nullptr;

MySQLHelper::~MySQLHelper(){

}

MYSQL_RES* MySQLHelper::query(std::string query){
  MYSQL_RES* res;
  if(MySQLHelper::dbconn){
      int qstate = mysql_query(MySQLHelper::dbconn, query.c_str());
      if(!qstate){
          res = mysql_store_result(MySQLHelper::dbconn);
        } else {
          // TODO add exception for failed query
          // Some error on query
          return nullptr;
        }
      return res;
  }
  // Not connected
  // TODO add exception for connection failed
  return nullptr;
}

void MySQLHelper::connect(){
  if(!MySQLHelper::dbconn){
      MySQLHelper::dbconn = mysql_init(nullptr);
      MySQLHelper::dbconn = mysql_real_connect(MySQLHelper::dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
      if (MySQLHelper::dbconn) {
          qDebug("Connected");
          return;
      }
      throw NotAbleToConnectException();
    } else{
      //TODO connection already set
    }
}

MySQLHelper* MySQLHelper::getInstance(){
  if(MySQLHelper::instance == nullptr){
      MySQLHelper::instance = new MySQLHelper();
      try {
        MySQLHelper::instance->connect();
      } catch (NotAbleToConnectException& e) {
        qDebug(e.what());
        MySQLHelper::instance = nullptr;
      }
  }
  return MySQLHelper::instance;
}


