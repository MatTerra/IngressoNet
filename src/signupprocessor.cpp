#include "signupprocessor.h"

SignupProcessor::SignupProcessor(QObject *parent) : QObject(parent){
  connect(this, SIGNAL(userDoesntExist(Usuario&)), this, SLOT(signupUser(Usuario&)));
}

void SignupProcessor::verifyExistingUser(Usuario& usuario){
  qDebug("Verifying if user exist.");
  try {
    UsuarioDAO* udao = UsuarioDAO::getInstance();
    Usuario existant = udao->get(usuario.getCPF());
    if(existant.getCPF() == usuario.getCPF()){
      qDebug("Existing user");
      emit userExist();
      return;
    }
    qDebug("Registering");
    emit userDoesntExist(usuario);
    return;
  }  catch (NotAbleToConnectException& e) {
    qDebug("Failed to verify existance");
    emit registrationError();
  }
}

void SignupProcessor::signupUser(Usuario& usuario){
  qDebug("Registration Started");
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  CartaoDAO* cdao = CartaoDAO::getInstance();
  try {
    udao->save(usuario);
    cdao->save(usuario.getCartao());
    cdao->update(usuario.getCartao(), "cpf", usuario.getCPF());
    qDebug("Registered");
    emit userRegistered();
  }  catch (NotAbleToConnectException& e) {
    qDebug("Connection Error");
    emit registrationError();
  }
}



