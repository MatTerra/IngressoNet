#ifndef MYSQLHELPER_H
#define MYSQLHELPER_H

#include "persistancehelper.h"
#include "notabletoconnectexception.h"
#include <QDebug>
#include <mysql/mysql.h>


#define IP "172.18.0.2"
#define USER "ingressoNetAdmin"
#define PASSWORD "TP1-2019-2"
#define DB "ingressoNetDB"



class MySQLHelper : public PersistanceHelper<MYSQL_RES>{
public:

  /** Default destructor */
  virtual ~MySQLHelper();

  /** Execute query on database and return result
   * \param query query to be executed
   */
  MYSQL_RES* query(std::string) override;

  /** Connect to remote(or local) database
   */
  void connect() override;

  /** Get instance if available or create new if necessary
   *  \return valid current instance
   */
  static MySQLHelper* getInstance();

  MySQLHelper(MySQLHelper const&) = delete;
  void operator=(MySQLHelper const&) = delete;
private:
  MySQLHelper(){}
  static MySQLHelper* instance; //!< Member variable "instance"
  static MYSQL* dbconn; //!< Member variable "dbconn"
};

#endif // MYSQLHELPER_H
