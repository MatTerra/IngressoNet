#include "cartaodao.h"

Cartao CartaoDAO::get(std::string numero){
  try {
    std::string query = "SELECT a.senha, b.numero, b.codigoDeSeguranca FROM usuario_t a, cartao_t b WHERE a.cpf = b.cpf AND a.cpf = '"+cpf+"';";
    MYSQL_RES* res = mysqlHelper->query(query);

    MYSQL_ROW row;
    if((row= mysql_fetch_row(res))) {
      std::string senha = row[0];
      unsigned long numeroCartao = strtoul(row[1], nullptr, 10);
      unsigned int numSeguranca = static_cast<unsigned int>(atoi(row[2]));

      Cartao card(numeroCartao, numSeguranca);
      Usuario user(cpf, senha, card);

      mysql_free_result(res);
      return user;
    }
    else{
      Cartao card(0, 0);
      Usuario user("000.000.000-00", "0", card);
      return user;
    }
  } catch (NotAbleToConnectException& e) {
    throw e;
  }
}
