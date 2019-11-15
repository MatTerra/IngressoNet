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
      emit registrationError("O usuário já está cadastro em nosso banco de dados.");
      return;
    }
    emit userDoesntExist(usuario);
    return;
  } catch (NotAbleToConnectException&) {
    emit registrationError("Não foi possível realizar o cadastro no momento. Tente novamente mais tarde.\nErro 01 - No Connection to DB");
  } catch (FailedQueryException&){
    emit registrationError("Não foi possível realizar o cadastro no momento. Tente novamente mais tarde.\nErro 02 - Query Error");
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
    emit userRegistered();
  }  catch (NotAbleToConnectException&) {
    emit registrationError("Não foi possível realizar o cadastro no momento. Tente novamente mais tarde.\nErro 01 - No Connection to DB");
  } catch (FailedQueryException&){
    emit registrationError("Não foi possível realizar o cadastro no momento. Tente novamente mais tarde.\nErro 02 - Query Error");
  }
}



