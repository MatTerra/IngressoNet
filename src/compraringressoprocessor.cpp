#include "compraringressoprocessor.h"

ComprarIngressoProcessor::ComprarIngressoProcessor(QObject *parent) : QObject(parent){
  session=Session::getInstance();
}

void ComprarIngressoProcessor::compraRequested(int quant, Partida& partida){
  try {
    IngressoDAO* idao = IngressoDAO::getInstance();
    for(; quant > 0 ; quant-- ){
      Ingresso i(quant, partida, session->getUsuario());
      idao->save(i);
    }
    emit purchaseDone();
  } catch (NotAbleToConnectException&) {
    emit purchaseError("Não foi possível realizar a compra no momento. Tente novamente mais tarde.\nErro 01 - No Connection to DB");
  } catch (FailedQueryException&){
    emit purchaseError("Não foi possível realizar a compra no momento. Tente novamente mais tarde.\nErro 02 - Query Error");
  }
}
