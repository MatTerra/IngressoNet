#include "manterperfilprocessor.h"

void ManterPerfilProcessor::changeSenhaRequested(QString senha){
  qDebug("to change senha");
  try {
    UsuarioDAO* udao = UsuarioDAO::getInstance();
    udao->update(session->getUsuario(),"senha",senha.toStdString());
    session->updateSenhaUsuario(senha);
    emit changeOperationDone("Senha alterada com sucesso!");
  } catch (NotAbleToConnectException&) {
    emit maintenanceError("Nao foi possível executar a alteração no momento. Tente novamente mais tarde.\nErro 01 - NotAbleToConnect");
  } catch (FailedQueryException&) {
    emit maintenanceError("Nao foi possível executar a alteração no momento. Tente novamente mais tarde.\nErro 02 - FailedQuery");
  }
}

void ManterPerfilProcessor::changeCardRequested(unsigned long numero, unsigned int codigoDeSeguranca){
  Cartao c(numero, codigoDeSeguranca, session->getUsuario().getCPF());
  try {
    CartaoDAO* cdao = CartaoDAO::getInstance();
    cdao->update(c, "numero", std::to_string(c.getNumero()));
    cdao->update(c, "codigoDeSeguranca",std::to_string(c.getNumSeguranca()));
    session->updateCartaoUsuario(c);
    emit changeOperationDone("Cartão alterado com sucesso!");
  } catch (NotAbleToConnectException&) {
    emit maintenanceError("Nao foi possível executar a alteração no momento. Tente novamente mais tarde.\nErro 01 - NotAbleToConnect");
  } catch (FailedQueryException&) {
    emit maintenanceError("Nao foi possível executar a alteração no momento. Tente novamente mais tarde.\nErro 02 - FailedQuery");
  }
}

void ManterPerfilProcessor::onDeleteRequested(){
 try{
    UsuarioDAO* udao = UsuarioDAO::getInstance();
    CartaoDAO* cdao = CartaoDAO::getInstance();
    cdao->remove(session->getUsuario().getCartao());
    udao->remove(session->getUsuario());
    emit deleteDone();
  } catch (NotAbleToConnectException&) {
    emit maintenanceError("Nao foi possível executar a alteração no momento. Tente novamente mais tarde.\nErro 01 - NotAbleToConnect");
  } catch (FailedQueryException&) {
    emit maintenanceError("Nao foi possível executar a alteração no momento. Tente novamente mais tarde.\nErro 02 - FailedQuery");
  }
}

