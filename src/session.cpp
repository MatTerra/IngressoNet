#include "session.h"

Session* Session::instance = nullptr;

Session* Session::getInstance(){
  if(Session::instance==nullptr){
    return new Session(Usuario("",""));
  }
  return Session::instance;
}

Session::~Session(){
  Session::instance=nullptr;
}

void Session::loginDone(Usuario& usuario){
  if(Session::getInstance()->getUsuario().getCPF()==""){
    Session::setInstance(usuario);
  }
}

void Session::logout(){
  Session::instance->usuario=Usuario("","");
  emit logoutDone();
}

void Session::setInstance(Usuario& usuario){
  Session::instance = new Session(usuario);
}

void Session::updateSenhaUsuario(QString senha){
  usuario.setSenha(senha.toStdString());
}

void Session::updateCartaoUsuario(Cartao c){
  usuario.setCartao(c);
}
