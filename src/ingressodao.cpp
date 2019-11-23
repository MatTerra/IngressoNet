#include "ingressodao.h"

IngressoDAO* IngressoDAO::instance = nullptr;
MySQLHelper* IngressoDAO::mysqlHelper = nullptr;

IngressoDAO::~IngressoDAO(){

}

Ingresso IngressoDAO::get(std::string codigo){
	try{
	  std::string query = "SELECT idIngresso, cpf, idPartida FROM ingresso_t WHERE idIngresso = '"+codigo+"';";
	  MYSQL_RES* res = mysqlHelper->query(query);

          MYSQL_ROW row;
          if((row = mysql_fetch_row(res))){
            int cod = atoi(row[0]);
            Usuario u = UsuarioDAO::getInstance()->get(row[1]);
            u.setSenha("");
            Partida p = PartidaDAO::getInstance()->get(row[2]);
            Ingresso ingresso(cod, p, u);
            mysql_free_result(res);
            return ingresso;
          }
          else{
            Usuario usuario("","");
            Estado e(-1,"");
            Cidade cidade(-1,"", e);
            Jogo jogo(-1,"",Jogo::Tipo(0));
            Partida partida(-1, cidade,-1,-1,usuario,QDateTime(),jogo);
            Ingresso ingresso(-1, partida, usuario);
            return ingresso;
          }
        } catch(NotAbleToConnectException& e) {
          throw e;
        } catch (FailedQueryException& e){
          throw e;
    	}
}

std::vector<Ingresso> IngressoDAO::getByProperty(std::string property, std::string value){
	std::vector<Ingresso> ingressos;
	if(property.compare("idIngresso") != 0 && property.compare("cpf") != 0 && property.compare("idPartida") != 0){
	  throw new PropertyNotFoundException();
	}
	try{
	  std::string query = "SELECT idIngresso, cpf, idPartida FROM ingresso_t WHERE "+property+" = '"+value+"';";
	  MYSQL_RES* res = mysqlHelper->query(query);
	  MYSQL_ROW row;
	  while((row = mysql_fetch_row(res))){
	    int cod = atoi(row[0]);
	    Usuario u = UsuarioDAO::getInstance()->get(row[1]);
	    u.setSenha("");
	    Partida p = PartidaDAO::getInstance()->get(row[2]);
	    Ingresso ingresso(cod, p, u);
	    ingressos.push_back(ingresso);
	  }
	  if(ingressos.size()==0){
	    Usuario usuario("","");
	    Estado e(-1,"");
	    Cidade cidade(-1,"", e);
	    Jogo jogo(-1,"",Jogo::Tipo(0));
	    Partida partida(-1, cidade,-1,-1,usuario,QDateTime(),jogo);
	    Ingresso ingresso(-1, partida, usuario);
	    ingressos.push_back(ingresso);
	  }
	  mysql_free_result(res);
	  return ingressos;
	} catch (NotAbleToConnectException& e) {
    	throw e;
  	} catch (FailedQueryException& e){
   		throw e;
	}
}

std::vector<Ingresso> IngressoDAO::getAll(){
	std::vector<Ingresso> ingressos;
	try {
	  std::string query = "SELECT idIngresso, cpf, idPartida FROM ingresso_t;";
	  MYSQL_RES* res = mysqlHelper->query(query);
	  MYSQL_ROW row = mysql_fetch_row(res);

	  while((row = mysql_fetch_row(res))){
	    int cod = atoi(row[0]);
	    Usuario u = UsuarioDAO::getInstance()->get(row[1]);
	    u.setSenha("");
	    Partida p = PartidaDAO::getInstance()->get(row[2]);
	    Ingresso ingresso(cod, p, u);
	    ingressos.push_back(ingresso);
	  }
	  if(ingressos.size()==0){
	    Usuario usuario("","");
	    Estado e(-1,"");
	    Cidade cidade(-1,"", e);
	    Jogo jogo(-1,"",Jogo::Tipo(0));
	    Partida partida(-1, cidade,-1,-1,usuario,QDateTime(),jogo);
	    Ingresso ingresso(-1, partida, usuario);
	    ingressos.push_back(ingresso);
	  }
	  mysql_free_result(res);
	  return ingressos;
	} catch (NotAbleToConnectException& e) {
		throw e;
	} catch (FailedQueryException& e){
		throw e;
	}
}

void IngressoDAO::save(Ingresso ingresso){
	try {
		std::string query = "INSERT INTO ingresso_t (idIngresso, cpf, idPartida) VALUES ('"+std::to_string(ingresso.getCodigo())+"', '"+ingresso.getUsuario().getCPF()+"', '"+std::to_string(ingresso.getPartida().getCodigo())+"';";
		mysql_free_result(mysqlHelper->query(query));
	} catch (NotAbleToConnectException& e) {
		throw e;
	} catch (FailedQueryException& e){
		throw e;
	}
}

void IngressoDAO::update(Ingresso ingresso, std::string field, std::string value){
	try {
	  if(field.compare("idIngresso") != 0 && field.compare("cpf") != 0 && field.compare("idPartida") != 0){
	    throw new PropertyNotFoundException();
	  }
	  std::string query = "UPDATE ingresso_t SET "+field+" = '"+value+"' WHERE idIngresso = '"+std::to_string(ingresso.getCodigo())+"';";
	  mysql_free_result(mysqlHelper->query(query));
	} catch (NotAbleToConnectException& e) {
		throw e;
	} catch (FailedQueryException& e){
		throw e;
	}
}

void IngressoDAO::remove(Ingresso ingresso){
	try {
	  std::string query = "DELETE FROM ingresso_t WHERE (idIngresso = '"+std::to_string(ingresso.getCodigo())+"');";
	  mysql_free_result(mysqlHelper->query(query));
	} catch (NotAbleToConnectException& e) {
	  throw e;
	} catch (FailedQueryException& e){
	  throw e;
	}
}

IngressoDAO* IngressoDAO::getInstance(){
  if(IngressoDAO::instance == nullptr){
    IngressoDAO::instance = new IngressoDAO();
    try {
      IngressoDAO::mysqlHelper = MySQLHelper::getInstance();
    } catch (NotAbleToConnectException& e) {
      IngressoDAO::instance = nullptr;
      throw e;
    }
  }
  return IngressoDAO::instance;
}
