#include "partidadao.h"

PartidaDAO* PartidaDAO::instance = nullptr;
MySQLHelper* PartidaDAO::mysqlHelper = nullptr;

PartidaDAO::~PartidaDAO(){

}

Partida PartidaDAO::get(std::string id){
  try {
    std::string query = "SELECT a.idPartida, a.cpf, a.idJogo, a.idCidade, a.data, a.preco, a.disponibilidade, b.nomeCidade, b.idEstado, c.siglaEstado, d.nomeJogo, d.idTipo FROM partida_t a, cidade_t b, estado_t c, jogo_t d WHERE d.idJogo = a.idJogo AND c.idEstado = b.idEstado AND b.idCidade = a.idCidade AND a.idPartida = '"+id+"';";
    MYSQL_RES* res = mysqlHelper->query(query);

    MYSQL_ROW row;
    if((row= mysql_fetch_row(res))) {
      int idPartida = atoi(row[0]);
      std::string cpf = row[1];
      int idJogo = atoi(row[2]);
      int idCidade = atoi(row[3]);
      QDateTime data = QDateTime::fromString(row[4], "yyyy-MM-dd hh:mm:ss");
      int preco = atoi(row[5]);
      int disponibilidade = atoi(row[6]);
      std::string nomeCidade = row[7];
      int idEstado = atoi(row[8]);
      std::string siglaEstado = row[9];
      std::string nomeJogo = row[10];
      int tipoJogo = atoi(row[11]);

      Estado estado(idEstado, siglaEstado);
      Cidade cidade(idCidade, nomeCidade, estado);
      Usuario u(cpf,"");
      Jogo j(idJogo, nomeJogo, Jogo::Tipo(tipoJogo));

      Partida partida(idPartida, cidade, preco, disponibilidade, u, data, j);

      mysql_free_result(res);
      return partida;
    }
    else{
      Estado e(-1,"");
      Cidade c(-1,"",e);
      Usuario u("","");
      Jogo j(-1,"",Jogo::Tipo(0));

      Partida partida(-1,c,0,0,u,QDateTime(),j);
      return partida;
    }
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Partida> PartidaDAO::getByProperty(std::string property, std::string value){
  std::vector<Partida> partidas;
  if(property.compare("idPartida") != 0 && property.compare("cpf") != 0 && property.compare("idJogo") != 0 && property.compare("idCidade") != 0 && property.compare("data") != 0 && property.compare("preco") != 0 && property.compare("disponibilidade") != 0){
    throw new PropertyNotFoundException();
  }
  try {
    std::string query;
    if(property.compare("data")==0){
      query = "SELECT a.idPartida, a.cpf, a.idJogo, a.idCidade, a.data, a.preco, a.disponibilidade, b.nomeCidade, b.idEstado, c.siglaEstado, d.nomeJogo, d.idTipo FROM partida_t a, cidade_t b, estado_t c, jogo_t d WHERE d.idJogo = a.idJogo AND c.idEstado = b.idEstado AND b.idCidade = a.idCidade AND a.`data` >= date_format('"+value+"', \"%Y-%c-%e %T\");";
    } else {
      query = "SELECT a.idPartida, a.cpf, a.idJogo, a.idCidade, a.data, a.preco, a.disponibilidade, b.nomeCidade, b.idEstado, c.siglaEstado, d.nomeJogo, d.idTipo FROM partida_t a, cidade_t b, estado_t c, jogo_t d WHERE d.idJogo = a.idJogo AND c.idEstado = b.idEstado AND b.idCidade = a.idCidade AND a."+property+" = '"+value+"';";
    }
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row;
    while((row = mysql_fetch_row(res))){
        int idPartida = atoi(row[0]);
        std::string cpf = row[1];
        int idJogo = atoi(row[2]);
        int idCidade = atoi(row[3]);
        QDateTime data = QDateTime::fromString(row[4], "yyyy-MM-dd hh:mm:ss");
        int preco = atoi(row[5]);
        int disponibilidade = atoi(row[6]);
        std::string nomeCidade = row[7];
        int idEstado = atoi(row[8]);
        std::string siglaEstado = row[9];
        std::string nomeJogo = row[10];
        int tipoJogo = atoi(row[11]);

        Estado estado(idEstado, siglaEstado);
        Cidade cidade(idCidade, nomeCidade, estado);
        Usuario u(cpf,"");
        Jogo j(idJogo, nomeJogo, Jogo::Tipo(tipoJogo));

        Partida partida(idPartida, cidade, preco, disponibilidade, u, data, j);

        partidas.push_back(partida);
    }
    if(partidas.size()==0){
        Estado e(-1,"");
        Cidade c(-1,"",e);
        Usuario u("","");
        Jogo j(-1,"",Jogo::Tipo(0));

        Partida partida(-1,c,0,0,u,QDateTime(),j);
        partidas.push_back(partida);
    }
    mysql_free_result(res);
    return partidas;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Partida> PartidaDAO::getAll(){
  std::vector<Partida> partidas;
  try {
    std::string query = "SELECT a.idPartida, a.cpf, a.idJogo, a.idCidade, a.data, a.preco, a.disponibilidade, b.nomeCidade, b.idEstado, c.siglaEstado, d.nomeJogo, d.idTipo FROM partida_t a, cidade_t b, estado_t c, jogo_t d WHERE d.idJogo = a.idJogo AND c.idEstado = b.idEstado AND b.idCidade = a.idCidade;";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row = mysql_fetch_row(res);

    while((row = mysql_fetch_row(res))){
        int idPartida = atoi(row[0]);
        std::string cpf = row[1];
        int idJogo = atoi(row[2]);
        int idCidade = atoi(row[3]);
        QDateTime data = QDateTime::fromString(row[4], "yyyy-MM-dd hh:mm:ss");
        int preco = atoi(row[5]);
        int disponibilidade = atoi(row[6]);
        std::string nomeCidade = row[7];
        int idEstado = atoi(row[8]);
        std::string siglaEstado = row[9];
        std::string nomeJogo = row[10];
        int tipoJogo = atoi(row[11]);

        Estado estado(idEstado, siglaEstado);
        Cidade cidade(idCidade, nomeCidade, estado);
        Usuario u(cpf,"");
        Jogo j(idJogo, nomeJogo, Jogo::Tipo(tipoJogo));

        Partida partida(idPartida, cidade, preco, disponibilidade, u, data, j);

        partidas.push_back(partida);
    }
    if(partidas.size()==0){
        Estado e(-1,"");
        Cidade c(-1,"",e);
        Usuario u("","");
        Jogo j(-1,"",Jogo::Tipo(0));

        Partida partida(-1,c,0,0,u,QDateTime(),j);
        partidas.push_back(partida);
    }
    mysql_free_result(res);
    return partidas;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void PartidaDAO::save(Partida partida){
  try {
    std::string query = "INSERT INTO partida_t (cpf, idJogo, idCidade, `data`, preco, disponibilidade) values ('"+partida.getResponsavel().getCPF()+"', "+std::to_string(partida.getJogo().getCodigo())+", "+std::to_string(partida.getCidade().getId())+", date_format(\""+partida.getData().toString("yyyy-MM-dd hh:mm:ss").toStdString()+"\", \"%Y-%c-%e %T\"), "+std::to_string(partida.getPreco())+", "+std::to_string(partida.getDisponibilidade())+");";
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void PartidaDAO::update(Partida partida, std::string field, std::string value){
  try {
    std::string query;
    if(field.compare("idPartida") != 0 && field.compare("cpf") != 0 && field.compare("idJogo") != 0 && field.compare("idCidade") != 0 && field.compare("data") != 0 && field.compare("preco") != 0 && field.compare("disponibilidade") != 0){
      throw new PropertyNotFoundException();
    } else if(field.compare("data") != 0){
      query = "UPDATE partida_t SET "+field+" = '"+value+"' WHERE (idPartida = "+std::to_string(partida.getCodigo())+");";
    } else {
      query = "UPDATE partida_t SET `data` = date_format(\""+value+"\", \"%Y-%c-%e %T\") WHERE (idPartida = "+std::to_string(partida.getCodigo())+");";
    }
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}
void PartidaDAO::remove(Partida partida){
  try {
    std::string query = "DELETE FROM partida_t WHERE (idPartida = '"+std::to_string(partida.getCodigo())+"');";
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

PartidaDAO* PartidaDAO::getInstance(){
  if(PartidaDAO::instance == nullptr){
      PartidaDAO::instance = new PartidaDAO();
      try {
        PartidaDAO::mysqlHelper = MySQLHelper::getInstance();
      } catch (NotAbleToConnectException& e) {
        PartidaDAO::instance = nullptr;
        throw e;
      }
  }
  return PartidaDAO::instance;
}
