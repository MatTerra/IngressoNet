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
          throw FailedQueryException();
          return nullptr;
        }
      return res;
  }
  throw NotAbleToConnectException();
}

void MySQLHelper::connect(){
  if(!MySQLHelper::dbconn){
      MySQLHelper::dbconn = mysql_init(nullptr);
      MySQLHelper::dbconn = mysql_real_connect(MySQLHelper::dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
      if (MySQLHelper::dbconn) {
          return;
      }
      throw NotAbleToConnectException();
    } else{
      return;
    }
}

void MySQLHelper::close(){
  mysql_close(MySQLHelper::dbconn);
  MySQLHelper::instance->~MySQLHelper();
}

MySQLHelper* MySQLHelper::getInstance(){
  if(MySQLHelper::instance == nullptr){
      MySQLHelper::instance = new MySQLHelper();
      try {
        MySQLHelper::instance->connect();
      } catch (NotAbleToConnectException& e) {
        MySQLHelper::instance = nullptr;
        throw e;
      }
  }
  return MySQLHelper::instance;
}


