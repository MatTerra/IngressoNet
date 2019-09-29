#include "usuariodao.h"

UsuarioDAO* UsuarioDAO::instance = nullptr;
MySQLHelper* UsuarioDAO::mysqlHelper = nullptr;

UsuarioDAO::~UsuarioDAO(){

}

Usuario UsuarioDAO::get(std::string cpf){
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

std::vector<Usuario> UsuarioDAO::getAll(){
  std::vector<Usuario> usuarios;
  try {
    std::string query = "SELECT a.cpf, a.senha, b.numero, b.codigoDeSeguranca FROM usuario_t a, cartao_t b WHERE a.cpf = b.cpf;";
    MYSQL_RES* res = mysqlHelper->query(query);
    MYSQL_ROW row = mysql_fetch_row(res);

    do{
        std::string cpf = row[0];
        std::string senha = row[1];
        unsigned long numeroCartao = strtoul(row[2], nullptr, 10);
        unsigned int numSeguranca = static_cast<unsigned int>(atoi(row[3]));

        Cartao card(numeroCartao, numSeguranca);
        Usuario user(cpf, senha, card);

        usuarios.push_back(user);
    }while((row = mysql_fetch_row(res)));
    mysql_free_result(res);
    return usuarios;
  } catch (NotAbleToConnectException& e) {
    throw e;
  }
}

void UsuarioDAO::save(Usuario usuario){
  std::string query = "INSERT INTO usuario_t (cpf, senha) VALUES ('"+usuario.getCPF()+"', '"+usuario.getSenha()+"');";
  std::string query2 = "INSERT INTO cartao_t (numero, cpf, codigoDeSeguranca) VALUES ("+std::to_string(usuario.getCartao().getNumero())+", '"+usuario.getCPF()+"', "+std::to_string(usuario.getCartao().getNumSeguranca())+");";

  mysql_free_result(mysqlHelper->query(query));
  mysql_free_result(mysqlHelper->query(query2));
}

void UsuarioDAO::update(Usuario usuario, std::string field, std::string value){
  std::string query;
  if(field.compare("senha")==0){
    query = "UPDATE usuario_t SET senha = '"+value+"' WHERE (cpf = '"+usuario.getCPF()+"');";
  } else{
    // TODO erro propriedade não encontrada
    qDebug("propriedade não encontrada");
  }
  mysql_free_result(mysqlHelper->query(query));
}
void UsuarioDAO::remove(Usuario usuario){
  std::string query = "DELETE FROM cartao_t WHERE (cpf = '"+usuario.getCPF()+"');";
  mysql_free_result(mysqlHelper->query(query));
  query = "DELETE FROM usuario_t WHERE (cpf = '"+usuario.getCPF()+"');";
  mysql_free_result(mysqlHelper->query(query));
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
