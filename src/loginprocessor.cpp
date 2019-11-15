#include "loginprocessor.h"

LoginProcessor::LoginProcessor(QObject *parent) : QObject(parent){

}

void LoginProcessor::loginUser(QString cpf, QString senha){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Usuario user = udao->get(cpf.toStdString());
  if(user.getSenha().compare(senha.toStdString()) != 0){
    emit loginError("Senha incorreta!");
    return;
  }
  CartaoDAO* cdao = CartaoDAO::getInstance();
  Cartao c = cdao->get(std::to_string(cdao->getByProperty("cpf",user.getCPF())[0].getNumero()));
  user.setCartao(c);
  emit loginSuccessful(user);
}
