#include "manterperfilprocessor.h"

void ManterPerfilProcessor::changeSenhaRequested(QString senha){
  qDebug("to change senha");
  try {
    UsuarioDAO* udao = UsuarioDAO::getInstance();
    udao->update(session->getUsuario(),"senha",senha.toStdString());
  } catch (NotAbleToConnectException&) {
    emit maintenanceFailed("Nao foi possível executar a alteração no momento. Tente novamente mais tarde.\nErro 01 - NotAbleToConnect");
  } catch (FailedQueryException&) {
    emit maintenanceFailed("Nao foi possível executar a alteração no momento. Tente novamente mais tarde.\nErro 02 - FailedQuery");
  }
}
