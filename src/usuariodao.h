#ifndef USUARIODAO_H
#define USUARIODAO_H

#include "mysqlhelper.h"
#include "genericdao.h"
#include "usuario.h"
#include "cartao.h"
#include "notabletoconnectexception.h"

#include <mysql/mysql.h>

class UsuarioDAO : public GenericDAO<Usuario>{

public:
  /** Default destructor */
  virtual ~UsuarioDAO();

  /** Get an user instance from database
   *  \param cpf to look for in db
   *  \return user with cpf
   */
  Usuario get(std::string) override;

  /** Get all users in database
   * \return usuarios vector of users in database
   */
  std::vector<Usuario> getAll() override;

  void save(Usuario) override;
  void update(Usuario, std::string[]) override;
  void remove(Usuario) override;
  static UsuarioDAO* getInstance();
private:
  static UsuarioDAO* instance;
  static MySQLHelper* mysqlHelper;
};

#endif // USUARIODAO_H
