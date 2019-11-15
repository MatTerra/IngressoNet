#include "usuariodao.h"

UsuarioDAO* UsuarioDAO::instance = nullptr;
MySQLHelper* UsuarioDAO::mysqlHelper = nullptr;

UsuarioDAO::~UsuarioDAO(){

}

Usuario UsuarioDAO::get(std::string cpf){
  try {
    std::string query = "SELECT cpf, senha FROM usuario_t WHERE cpf = '"+cpf+"';";
    MYSQL_RES* res = mysqlHelper->query(query);

    MYSQL_ROW row;
    if((row= mysql_fetch_row(res))) {
      std::string senha = row[1];

      Usuario user(cpf, senha);

      mysql_free_result(res);
      return user;
    }
    else{
      Usuario user("000.000.000-00", "");
      return user;
    }
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Usuario> UsuarioDAO::getByProperty(std::string property, std::string value){
  std::vector<Usuario> usuarios;
  try {
    std::string query = "SELECT cpf FROM usuario_t WHERE ("+property+" = '"+value+"');";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row = mysql_fetch_row(res);

    do{
        std::string cpf = row[0];

        Usuario user(cpf, "");

        usuarios.push_back(user);
    }while((row = mysql_fetch_row(res)));
    mysql_free_result(res);
    return usuarios;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

std::vector<Usuario> UsuarioDAO::getAll(){
  std::vector<Usuario> usuarios;
  try {
    std::string query = "SELECT cpf FROM usuario_t;";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row = mysql_fetch_row(res);

    do{
        std::string cpf = row[0];

        Usuario user(cpf, "");

        usuarios.push_back(user);
    }while((row = mysql_fetch_row(res)));
    mysql_free_result(res);
    return usuarios;
  } catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void UsuarioDAO::save(Usuario usuario){
  try {
    std::string query = "INSERT INTO usuario_t (cpf, senha) VALUES ('"+usuario.getCPF()+"', '"+usuario.getSenha()+"');";
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

void UsuarioDAO::update(Usuario usuario, std::string field, std::string value){
  try {
    std::string query;
    if(field.compare("senha")==0){
      query = "UPDATE usuario_t SET senha = '"+value+"' WHERE (cpf = '"+usuario.getCPF()+"');";
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
void UsuarioDAO::remove(Usuario usuario){
  try {
    std::string query = "DELETE FROM usuario_t WHERE (cpf = '"+usuario.getCPF()+"');";
    mysql_free_result(mysqlHelper->query(query));
  }  catch (NotAbleToConnectException& e) {
    throw e;
  } catch (FailedQueryException& e){
    throw e;
  }
}

UsuarioDAO* UsuarioDAO::getInstance(){
  if(UsuarioDAO::instance == nullptr){
      UsuarioDAO::instance = new UsuarioDAO();
      try {
        UsuarioDAO::mysqlHelper = MySQLHelper::getInstance();
      } catch (NotAbleToConnectException& e) {
        UsuarioDAO::instance = nullptr;
        throw e;
      }
  }
  return UsuarioDAO::instance;
}
