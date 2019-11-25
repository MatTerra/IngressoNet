#include "jogodao.h"

JogoDAO* JogoDAO::instance = nullptr;
MySQLHelper* JogoDAO::mysqlHelper = nullptr;

JogoDAO::~JogoDAO(){

}

Jogo JogoDAO::get(std::string codigo){
  try {
    std::string query = "SELECT idJogo, idTipo, nomeJogo FROM jogo_t WHERE idJogo = '"+codigo+"';";
    MYSQL_RES* res = mysqlHelper->query(query);

    MYSQL_ROW row;
    if((row= mysql_fetch_row(res))) {
      int idJogo = atoi(row[0]);
      int idTipo = atoi(row[1]);
      std::string nome = row[2];
      Jogo jogo(idJogo, nome, Jogo::Tipo(idTipo));

      mysql_free_result(res);
      return jogo;
    }
    else{
      Jogo jogo(-1,"",Jogo::Tipo(0));
      return jogo;
    }
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Jogo> JogoDAO::getByProperty(std::string property, std::string value){
  std::vector<Jogo> jogos;
  if(property.compare("idJogo") != 0 && property.compare("idTipo") != 0 && property.compare("nomeJogo") != 0){
    throw new PropertyNotFoundException();
  }
  try {
    std::string query = "SELECT idJogo, idTipo, nomeJogo FROM jogo_t WHERE "+property+" = '"+value+"';";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row;
    while((row = mysql_fetch_row(res))){
        int idJogo = atoi(row[0]);
        int idTipo = atoi(row[1]);
        std::string nome = row[2];
        Jogo jogo(idJogo, nome, Jogo::Tipo(idTipo));

        jogos.push_back(jogo);
    }
    if(jogos.size()==0){
      jogos.push_back(Jogo(-1,"", Jogo::Tipo(0)));
    }
    mysql_free_result(res);
    return jogos;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Jogo> JogoDAO::getAll(){
  std::vector<Jogo> jogos;
  try {
    std::string query = "SELECT idJogo, idTipo, nomeJogo FROM jogo_t ";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row = mysql_fetch_row(res);

    do{
        int idJogo = atoi(row[0]);
        int idTipo = atoi(row[1]);
        std::string nome = row[2];
        Jogo jogo(idJogo, nome, Jogo::Tipo(idTipo));

        jogos.push_back(jogo);
    }while((row = mysql_fetch_row(res)));
    mysql_free_result(res);
    return jogos;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void JogoDAO::save(Jogo jogo){
  try {
    std::string query = "INSERT INTO jogo_t (idTipo, nomeJogo) VALUES ('"+std::to_string(jogo.getTipo())+"', '"+jogo.getNome()+"');";
    qDebug("%s", query.c_str());
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void JogoDAO::update(Jogo jogo, std::string field, std::string value){
  try {
    std::string query;
    if(field.compare("idTipo")==0){
      query =  "UPDATE jogo_t SET idTipo = '"+value+"' WHERE (idJogo = '"+std::to_string(jogo.getCodigo())+"');";
    } else if (field.compare("nomeJogo")==0){
      query = "UPDATE jogo_t SET nomeJogo = '"+value+"' WHERE (idJogo = '"+std::to_string(jogo.getCodigo())+"');";
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
void JogoDAO::remove(Jogo jogo){
  try {
    std::string query = "DELETE FROM jogo_t WHERE (idJogo = '"+std::to_string(jogo.getCodigo())+"');";
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

JogoDAO* JogoDAO::getInstance(){
  if(JogoDAO::instance == nullptr){
      JogoDAO::instance = new JogoDAO();
      try {
        JogoDAO::mysqlHelper = MySQLHelper::getInstance();
      } catch (NotAbleToConnectException& e) {
        JogoDAO::instance = nullptr;
        throw e;
      }
  }
  return JogoDAO::instance;
}
