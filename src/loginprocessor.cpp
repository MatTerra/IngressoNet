#include "loginprocessor.h"

LoginProcessor::LoginProcessor(QObject *parent) : QObject(parent){

}

void LoginProcessor::loginUser(QString cpf, QString senha){
  try {
    UsuarioDAO* udao = UsuarioDAO::getInstance();
    Usuario user = udao->get(cpf.toStdString());
    if(user.getCPF().compare("")==0){
      emit loginError("Usuário não cadastrado");
      return;
    }
    if(user.getSenha().compare(senha.toStdString()) != 0){
      emit loginError("Senha incorreta!");
      return;
    }
    CartaoDAO* cdao = CartaoDAO::getInstance();
    Cartao c = cdao->get(user.getCPF());
    user.setCartao(c);
    emit loginSuccessful(user);
  }  catch (NotAbleToConnectException&) {
    emit loginError("Não foi possível fazer o login no momento. Tente novamente mais tarde.\nErro 01 - No Connection to DB");
  } catch (FailedQueryException&){
    emit loginError("Não foi possível fazer o login no momento. Tente novamente mais tarde.\nErro 02 - Query Error");
  }
}
