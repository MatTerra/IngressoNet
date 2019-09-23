#ifndef MYSQLHELPER_H
#define MYSQLHELPER_H

#include <persistancehelper.h>
#include <mysql/mysql.h>
#include <QDebug>

#define IP "127.0.0.1"
#define USER "root"
#define PASSWORD ""
#define DB "ingressoNetDb"



class MySQLHelper : public PersistanceHelper<MYSQL_RES>{
public:
  /** Default constructor */
  MySQLHelper();

  /** Default constructor */
  virtual ~MySQLHelper() override;

  /** Execute query on database and return result
   * \param query query to be executed
   */
  MYSQL_RES query(std::string) override;

  /** Connect to remote(or local) database
   */
  void connect() override;

  /** Get instance if available or create new if necessary
   *  \return valid current instance
   */
  static MySQLHelper* getInstance();
private:
  static MySQLHelper* instance; //!< Member variable "instance"
  static MYSQL* dbconn; //!< Member variable "dbconn"
};

#endif // MYSQLHELPER_H
