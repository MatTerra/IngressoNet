#include "cartaodao.h"

CartaoDAO* CartaoDAO::instance = nullptr;
MySQLHelper* CartaoDAO::mysqlHelper = nullptr;

Cartao CartaoDAO::get(std::string numero){
  try {
    std::string query = "SELECT codigoDeSeguranca FROM cartao_t WHERE numero="+numero+";";
    MYSQL_RES* res = mysqlHelper->query(query);

    MYSQL_ROW row;
    if((row= mysql_fetch_row(res))) {
      unsigned int numSeguranca = static_cast<unsigned int>(atoi(row[0]));

      Cartao card(strtoul(numero.c_str(), nullptr, 10), numSeguranca);

      mysql_free_result(res);
      return card;
    }
    else{
      Cartao card(0, 0);
      return card;
    }
  } catch (NotAbleToConnectException& e) {
    throw e;
  }
}

//TODO implementar funções
