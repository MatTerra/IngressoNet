#include "ingressodao.h"

IngressoDAO* IngressoDAO::instance = nullptr;
MySQLHelper* IngressoDAO::mysqlHelper = nullptr;

IngressoDAO::~CidadeDAO(){

}

Ingresso IngressoDAO::get(std::string codigo){
	try{
		std::string query = "SELECT codIngresso, codPartida, usuarioIngresso FROM ingresso_t WHERE codIngresso = '"+cod+"';";
		MYSQL_RES* res = mysqlHelper->query(query);

		MYSQL_ROW row;
		if((row = mysql_fetch_row(res))){
			int cod = atoi(row[0]);
			int codPartida = atoi(row[1]);
			std::string nomeUsuario = row[2];

			Partida partida(codPartida, cidade, preco, disponibilidade, responsavel, daata, jogo);
			Cartao cartao(numCartao, codSeguranca);
			Usuario usuario(cpf, senha, cartao);
			Ingresso ingresso(cod, partida, usuario); //n sei como pegar os dados para criar os objetos para partida e usuário

			mysql_free_result(res);
			return ingresso;
		}
		else{
			Estado e(-1, "");
			Cartao cartao(-1, -1);
      		Cidade cidade(-1 ,"", e);
      		Usuario responsavel(-1, -1, cartao);
      		Jogo jogo(-1, "", tipo);
			Partida partida(-1, cidade, -1, -1, responsavel, data, jogo);
			Usuário usuario(-1, -1, cartao);
			Ingresso ingresso(-1, partida, usuário);
		}
	}	catch(NotAbleToConnectException& e) {
    		throw e;
		} catch (FailedQueryException& e){
    		throw e;
    	}
}

std::vector<Ingresso> IngrssoDAO::getByProperty(std::string property, std::string value){
	std::vector<Ingresso> ingressos;
	if(property.compare("codIngresso") != 0 && property.compare("codPartida") != 0 && property.compare("idUsuario") != 0){
		throw new PropertyNotFoundException();
	}
	try{
		std::string query = "SELECT codIngresso, codPartida, idUsuario FROM ingresso_t WHERE "+property+" = '"+value+"';";
		MYSQL_RES* res = mysqlHelper->query(query);
		MYSQL_ROW row;
		while((row = mysql_fetch_row(res))){
			int cod = atoi(row[0]);
			int codPartida = atoi(row[1]);
			std::string nomeUsuario = row[2];

			Partida partida(codPartida, cidade, preco, disponibilidade, responsavel, daata, jogo);
			Cartao cartao(numCartao, codSeguranca);
			Usuario usuario(cpf, senha, cartao);
			Ingresso ingresso(cod, partida, usuario); //n sei como pegar os dados para criar os objetos para partida e usuário

			ingressos.push_back(ingresso);
		}
		if(ingressos.size()==0){
			Estado e(-1, "");
			Cartao cartao(-1, -1);
      		Cidade cidade(-1 ,"", e);
      		Usuario responsavel(-1, -1, cartao);
      		Jogo jogo(-1, "", tipo);
			Partida partida(-1, cidade, -1, -1, responsavel, data, jogo);
			Usuário usuario(-1, -1, cartao);

			ingressos.push_back(Ingresso ingresso(-1, partida, usuário));
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
		std::string query = "SELECT codIngresso, codPartida, idUsuario FROM ingresso_t;";
		MYSQL_RES* res = mysqlHelper->query(query);
		MYSQL_ROW row = mysql_fetch_row(res);

		do{
			int cod = atoi(row[0]);
			int codPartida = atoi(row[1]);
			std::string nomeUsuario = row[2];

			Partida partida(codPartida, cidade, preco, disponibilidade, responsavel, daata, jogo);
			Cartao cartao(numCartao, codSeguranca);
			Usuario usuario(cpf, senha, cartao);
			Ingresso ingresso(cod, partida, usuario); //n sei como pegar os dados para criar os objetos para partida e usuário

			ingressos.push_back(ingresso);
		}while((row = mysql_fetch_row(res)));
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
		std::string query = "INSERT INTO ingresso_t (codIngresso, codPartida, idUsuario) VALUES ('"+std::to_string(ingresso.getCodigo())+"', '"+std::to_string(ingresso.getPartida().getCodigo())+"', '"+ingresso.getUsuario().getCPF()+"';";
		mysql_free_result(mysqlHelper->query(query));
	} catch (NotAbleToConnectException& e) {
		throw e;
	} catch (FailedQueryException& e){
		throw e;
	}
}

void IngressoDAO::update(Ingresso ingresso, std::string field, std::string value){
	try {
		std::string query;
		if(field.compare("codPartida")==0){
			query = "UPDATE ingresso_t SET codPartida = '"+value+"' WHERE (codIngresso = '"+std::to_string(ingresso.getCodigo())+"');";
		} else if(field.compare("idUsuario")==0){
			query = "UPDATE cidade_t SET idUsuario = '"+value+"' WHERE (codIngresso = '"+std::to_string(cidade.getCodigo())+"');";
		} else{
			throw PropertyNotFoundException();
		}
		mysql_free_result(mysqlHelper->query(query));
	} catch (NotAbleToConnectException& e) {
		throw e;
	} catch (FailedQueryException& e){
		throw e;
	}
}

void IngressoDAO::remove(Ingresso ingresso){
	try {
		std::string query = "DELETE FROM ingresso_t WHERE (codIngresso = '"+std::to_string(ingresso.getCodigo())+"');";
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
