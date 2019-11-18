#include "estadodao.h"


EstadoDAO* EstadoDAO::instance = nullptr;
MySQLHelper* EstadoDAO::mysqlHelper = nullptr;

EstadoDAO::~EstadoDAO(){

}

Estado EstadoDAO::get(std::string id){
  try {
    std::string query = "SELECT idEstado, siglaEstado FROM estado_t WHERE idEstado = '"+id+"';";
    MYSQL_RES* res = mysqlHelper->query(query);

    MYSQL_ROW row;
    if((row= mysql_fetch_row(res))) {
      std::string sigla = row[1];

      Estado estado(atoi(id.c_str()), sigla);

      mysql_free_result(res);
      return estado;
    }
    else{
      Estado estado(-1, "");
      return estado;
    }
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Estado> EstadoDAO::getByProperty(std::string property, std::string value){
  std::vector<Estado> estados;
  if(property.compare("idEstado") != 0 && property.compare("siglaEstado") != 0){
    throw new PropertyNotFoundException();
  }
  try {
    std::string query = "SELECT idEstado, siglaEstado FROM estado_t WHERE ("+property+" = '"+value+"');";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row;

    while((row = mysql_fetch_row(res))){
      std::string id = row[0];
      std::string sigla = row[1];

      Estado estado(atoi(id.c_str()), sigla);

      estados.push_back(estado);
    }
    if(estados.size()){
      estados.push_back(Estado(-1,""));
    }
    mysql_free_result(res);
    return estados;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Estado> EstadoDAO::getAll(){
  std::vector<Estado> estados;
  try {
    std::string query = "SELECT idEstado, siglaEstado FROM estado_t ORDER BY idEstado;";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row = mysql_fetch_row(res);

    do{
        std::string id = row[0];
        std::string sigla = row[1];

        Estado estado(atoi(id.c_str()), sigla);

        estados.push_back(estado);
    }while((row = mysql_fetch_row(res)));
    mysql_free_result(res);
    return estados;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void EstadoDAO::save(Estado estado){
  try {
    std::string query = "INSERT INTO estado_t (siglaEstado) VALUES ('"+estado.getSigla()+"');";
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void EstadoDAO::update(Estado estado, std::string field, std::string value){
  try {
    std::string query;
    if(field.compare("siglaEstado")==0){
      query = "UPDATE estado_t SET siglaEstado = '"+value+"' WHERE (idEstado = '"+std::to_string(estado.getId())+"');";
    } else{
      throw PropertyNotFoundException();
    }
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}
void EstadoDAO::remove(Estado estado){
  try {
    std::string query = "DELETE FROM estado_t WHERE (idEstado = '"+std::to_string(estado.getId())+"');";
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

EstadoDAO* EstadoDAO::getInstance(){
  if(EstadoDAO::instance == nullptr){
      EstadoDAO::instance = new EstadoDAO();
      try {
        EstadoDAO::mysqlHelper = MySQLHelper::getInstance();
      } catch (NotAbleToConnectException& e) {
        EstadoDAO::instance = nullptr;
        throw e;
      }
  }
  return EstadoDAO::instance;
}
