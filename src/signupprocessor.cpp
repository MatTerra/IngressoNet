#include "signupprocessor.h"

SignupProcessor::SignupProcessor(QObject *parent) : QObject(parent){
  connect(this, SIGNAL(userDoesntExist()), this, SLOT(signupUser()));
}

void SignupProcessor::verifyExistingUser(Usuario& usuario){
  qDebug("Verifying if user exist.");
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Usuario existant = udao->get(usuario.getCPF());
  if(existant.getCPF() == usuario.getCPF()){
    emit userExist();
  }
  emit userDoesntExist(usuario);
}

void SignupProcessor::signupUser(Usuario& usuario){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  CartaoDAO* cdao = CartaoDAO::getInstance();
  try {
    udao->save(usuario);
    cdao->save(usuario.getCartao());
    cdao->update(usuario.getCartao(), "cpf", usuario.getCPF());
    emit userRegistered();
  }  catch (NotAbleToConnectException& e) {
    emit registrationError();
  }
}



