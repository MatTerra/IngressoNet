#include "cartaodao.h"

CartaoDAO* CartaoDAO::instance = nullptr;
MySQLHelper* CartaoDAO::mysqlHelper = nullptr;

CartaoDAO::~CartaoDAO(){

}

Cartao CartaoDAO::get(std::string cpf){
  try {
    std::string query = "SELECT numero, cpf, codigoDeSeguranca FROM cartao_t WHERE cpf='"+cpf+"';";
    qDebug("%s", query.c_str());
    MYSQL_RES* res = mysqlHelper->query(query);

    MYSQL_ROW row;
    if((row= mysql_fetch_row(res))) {
      unsigned long numero = strtoul(row[0], nullptr, 10);

      unsigned int numSeguranca = static_cast<unsigned int>(atoi(row[2]));

      Cartao card(numero, numSeguranca, cpf);

      mysql_free_result(res);
      return card;
    }
    else{
      Cartao card(0, 0);
      return card;
    }
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Cartao> CartaoDAO::getByProperty(std::string property, std::string value){
  std::vector<Cartao> cartoes;
  if(property.compare("numero") != 0 && property.compare("cpf") != 0 && property.compare("codigoDeSeguranca") != 0){
    throw new PropertyNotFoundException();
  }
  try {
    std::string query = "SELECT numero, cpf FROM cartao_t WHERE ("+property+" = '"+value+"');";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row;
    while((row= mysql_fetch_row(res))){
      unsigned long numero = strtoul(row[0], nullptr, 10);
      std::string cpf = row[1];

      Cartao card(numero, 0, cpf);
      cartoes.push_back(card);
    }
    if(cartoes.size()==0){
      cartoes.push_back(Cartao(0,0));
    }
    mysql_free_result(res);
    return cartoes;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Cartao> CartaoDAO::getAll(){
  std::vector<Cartao> cartoes;
  try {
    std::string query = "SELECT numero, cpf FROM cartao_t;";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row = mysql_fetch_row(res);
    do{
      unsigned long numero = strtoul(row[0], nullptr, 10);
      std::string cpf = row[1];

      Cartao card(numero, 0, cpf);
      cartoes.push_back(card);
    }while((row= mysql_fetch_row(res)));
    mysql_free_result(res);
    return cartoes;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void CartaoDAO::save(Cartao cartao){
  qDebug("%lu\t%u", cartao.getNumero(), cartao.getNumSeguranca());
  try {
    std::string query = "INSERT INTO cartao_t (numero, cpf, codigoDeSeguranca) VALUES ("+std::to_string(cartao.getNumero())+", '"+cartao.getCPF()+"', "+std::to_string(cartao.getNumSeguranca())+");";
    qDebug("%s", query.c_str());
    mysql_free_result(mysqlHelper->query(query));
  } catch (NotAbleToConnectException& e) {
    qDebug("no conn");
    throw e;
  } catch (FailedQueryException& e){
    qDebug("failed query");
    throw e;
  }
}

void CartaoDAO::update(Cartao cartao, std::string field, std::string value){
  try {
    std::string query;
    if(field.compare("numero") != 0 && field.compare("cpf") != 0 && field.compare("codigoDeSeguranca") != 0){
      throw new PropertyNotFoundException();
    }
    query="UPDATE cartao_t SET "+field+" = '"+value+"' WHERE (cpf = '"+cartao.getCPF()+"');";
    qDebug("%s", query.c_str());
    mysql_free_result(mysqlHelper->query(query));
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void CartaoDAO::updateByCpf(Cartao cartao, std::string cpf){
  try {
    std::string query = "UPDATE cartao_t SET numero = '"+std::to_string(cartao.getNumero())+"', codigoDeSeguranca = '"+std::to_string(cartao.getNumSeguranca())+"' WHERE (cpf = '"+cpf+"');";
    mysql_free_result(mysqlHelper->query(query));
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void CartaoDAO::remove(Cartao cartao){
  std::string query = "DELETE FROM cartao_t WHERE (numero = '"+std::to_string(cartao.getNumero())+"' AND cpf='"+cartao.getCPF()+"');";
  mysql_free_result(mysqlHelper->query(query));
}

CartaoDAO* CartaoDAO::getInstance(){
  if(CartaoDAO::instance == nullptr){
      CartaoDAO::instance = new CartaoDAO();
      try {
        CartaoDAO::mysqlHelper = MySQLHelper::getInstance();
      } catch (NotAbleToConnectException& e) {
        CartaoDAO::instance = nullptr;
        throw e;
      }
  }
  return CartaoDAO::instance;
}
