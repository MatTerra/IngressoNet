#ifndef USUARIODAO_H
#define USUARIODAO_H

#include <genericdao.h>
#include <usuario.h>

class UsuarioDAO : public GenericDAO<Usuario>
{
public:
  UsuarioDAO();
  virtual ~UsuarioDAO();
  Usuario get(std::string) override;
  std::vector<Usuario> getAll() override;
  void save(Usuario) override;
  void update(Usuario, std::string[]) override;
  void remove(Usuario) override;
};

#endif // USUARIODAO_H
