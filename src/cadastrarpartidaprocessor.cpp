#include "cadastrarpartidaprocessor.h"

CadastrarPartidaProcessor::CadastrarPartidaProcessor(QObject *parent) : QObject(parent){

}

void CadastrarPartidaProcessor::cadastroPartidaRequested(Partida& partida){
  try {
    qDebug("Starting partida registration...");
    JogoDAO* jdao = JogoDAO::getInstance();
    jdao->save(partida.getJogo());
    qDebug("Jogo registrado!");
    std::vector<Jogo> jogos = jdao->getByProperty("nomeJogo", partida.getJogo().getNome());
    foreach(Jogo j, jogos){
      if(j.getTipo() == partida.getJogo().getTipo()){
        partida.setJogo(j);
      }
    }
    qDebug("Id Jogo localizado!");
    PartidaDAO* pdao = PartidaDAO::getInstance();
    pdao->save(partida);
    qDebug("Partida Salva");
    emit cadastroPartidaDone();
  } catch (NotAbleToConnectException&) {
    emit createError("Não foi possível cadastrar a partida no momento. Tente novamente mais tarde.\nErro 01 - No Connection to DB");
  } catch (FailedQueryException&){
    emit createError("Não foi possível cadastrar a partida no momento. Tente novamente mais tarde.\nErro 02 - Query Error");
  }
}
