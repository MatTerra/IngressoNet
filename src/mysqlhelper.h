#ifndef MYSQLHELPER_H
#define MYSQLHELPER_H

#include "persistancehelper.h"
#include "notabletoconnectexception.h"
#include "failedqueryexception.h"
#include <QDebug>
#include <mysql/mysql.h>


#define IP "172.18.0.2"
#define USER "ingressoNetAdmin"
#define PASSWORD "TP1-2019-2"
#define DB "ingressoNetDB"


class MySQLHelper : public PersistanceHelper<MYSQL_RES>{

  public:
    /** Destrutor padrão */
    virtual ~MySQLHelper();

    /** Executa uma operação no banco MySQL e retorna o resutado.
     * \param query Operação a ser executada
     * \return Resultado da operação
     */
    MYSQL_RES* query(std::string) override;

    /** Conecta a um banco de dados SQL remoto.
     */
    void connect() override;

    /** Encerra a conexão com um banco de dados SQL remoto.
     */
    void close() override;

    /** Retorna a instância da classe MySQLHelper(Singleton) ou, caso necessário, cria a instância.
     *  \return Instância válida atual
     */
    static MySQLHelper* getInstance();

    /** Deleta o construtor para garantir a arquitetura singleton da classe.
     */
    MySQLHelper(MySQLHelper const&) = delete;

    /** Deleta o operador = para garantir a arquitetura singleton da classe.
     */
    void operator=(MySQLHelper const&) = delete;


  private:
    /** Construtor privado para garantir a arquitetura Singleton da classe.
     */
    MySQLHelper(){}

    static MySQLHelper* instance; //!< Atributo de classe "instance". Representa a instância da classe.
    static MYSQL* dbconn; //!< Atributo de classe "dbconn". Representa a conexão com o banco de dados.
};

#endif // MYSQLHELPER_H
