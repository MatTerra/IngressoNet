#include "usuariodao.h"

UsuarioDAO::UsuarioDAO()
{

}

Usuario UsuarioDAO::get(std::string){
  Cartao card(99,99);
  Usuario user("a", "a", card);
  return user;
}

std::vector<Usuario> UsuarioDAO::getAll(){

}
void UsuarioDAO::save(Usuario){

}
void UsuarioDAO::update(Usuario, std::string[]){

}
void UsuarioDAO::remove(Usuario){

}
