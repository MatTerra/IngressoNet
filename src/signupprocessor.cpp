#include "signupprocessor.h"

SignupProcessor::SignupProcessor(QObject *parent) : QObject(parent){
}

void SignupProcessor::verifyExistingUser(Usuario& usuario){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Usuario existant = udao->get(usuario.getCPF());
  if(existant.getCPF() == usuario.getCPF()){
    emit userExist();
  }
  emit userDoesntExist(usuario);
}

void SignupProcessor::signupUser(Usuario& usuario){

}


