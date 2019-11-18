#include "cidadedao.h"

CidadeDAO* CidadeDAO::instance = nullptr;
MySQLHelper* CidadeDAO::mysqlHelper = nullptr;

CidadeDAO::~CidadeDAO(){

}

Cidade CidadeDAO::get(std::string id){
  try {
    std::string query = "SELECT idCidade, nomeCidade, idEstado FROM cidade_t WHERE idCidade = '"+id+"';";
    MYSQL_RES* res = mysqlHelper->query(query);

    MYSQL_ROW row;
    if((row= mysql_fetch_row(res))) {
      int id = atoi(row[0]);
      std::string nome = row[1];
      int estado = atoi(row[2]);

      Estado e(estado, "");
      Cidade cidade(id, nome, e);

      mysql_free_result(res);
      return cidade;
    }
    else{
      Estado e(-1, "");
      Cidade cidade(-1 ,"", e);
      return cidade;
    }
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Cidade> CidadeDAO::getByProperty(std::string property, std::string value){
  std::vector<Cidade> cidades;
  if(property.compare("nomeCidade") != 0 && property.compare("idCidade") != 0 && property.compare("idEstado") != 0){
    throw new PropertyNotFoundException();
  }
  try {
    std::string query = "SELECT idCidade, nomeCidade, idEstado FROM cidade_t WHERE "+property+" = '"+value+"';";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row;
    while((row = mysql_fetch_row(res))){
        int id = atoi(row[0]);
        std::string nome = row[1];
        int estado = atoi(row[2]);

        Estado e(estado, "");
        Cidade cidade(id, nome, e);

        cidades.push_back(cidade);
    }
    if(cidades.size()==0){
      Estado e(-1, "");
      cidades.push_back(Cidade(-1,"", e));
    }
    mysql_free_result(res);
    return cidades;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Cidade> CidadeDAO::getAll(){
  std::vector<Cidade> cidades;
  try {
    std::string query = "SELECT idCidade, nomeCidade, idEstado FROM cidade_t;";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row = mysql_fetch_row(res);

    do{
      int id = atoi(row[0]);
      std::string nome = row[1];
      int estado = atoi(row[2]);

      Estado e(estado, "");
      Cidade cidade(id, nome, e);

      cidades.push_back(cidade);
    }while((row = mysql_fetch_row(res)));
    mysql_free_result(res);
    return cidades;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void CidadeDAO::save(Cidade cidade){
  try {
    std::string query = "INSERT INTO cidade_t (idEstado, nomeCidade) VALUES ('"+std::to_string(cidade.getEstado().getId())+"', '"+cidade.getNome()+"');";
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void CidadeDAO::update(Cidade cidade, std::string field, std::string value){
  try {
    std::string query;
    if(field.compare("nomeCidade")==0){
      query = "UPDATE cidade_t SET nomeCidade = '"+value+"' WHERE (idCidade = '"+std::to_string(cidade.getId())+"');";
    } else if(field.compare("idEstado")==0){
      query = "UPDATE cidade_t SET idEstado = '"+value+"' WHERE (idCidade = '"+std::to_string(cidade.getId())+"');";
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
void CidadeDAO::remove(Cidade cidade){
  try {
    std::string query = "DELETE FROM cidade_t WHERE (idCidade = '"+std::to_string(cidade.getId())+"');";
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

CidadeDAO* CidadeDAO::getInstance(){
  if(CidadeDAO::instance == nullptr){
      CidadeDAO::instance = new CidadeDAO();
      try {
        CidadeDAO::mysqlHelper = MySQLHelper::getInstance();
      } catch (NotAbleToConnectException& e) {
        CidadeDAO::instance = nullptr;
        throw e;
      }
  }
  return CidadeDAO::instance;
}
