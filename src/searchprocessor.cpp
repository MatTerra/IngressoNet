#include "searchprocessor.h"

SearchProcessor::SearchProcessor(QObject *parent) : QObject(parent){

}

void SearchProcessor::searchGame(QDateTime data, QString cidade, QString estado){
  try{
    PartidaDAO* pdao = PartidaDAO::getInstance();
    std::vector<Partida> partidas = pdao->getByProperty("data", data.toString("yyyy-MM-dd hh:mm:ss").toStdString());
    QVector<Partida> partidasFiltradas;
    partidasFiltradas = this->filterByEstado(QVector<Partida>::fromStdVector(partidas), estado);
    qDebug("Filtradas por Estado: %d", partidasFiltradas.size());
    partidasFiltradas = this->filterByCidade(partidasFiltradas, cidade, estado);
    qDebug("Filtradas por Cidade: %d", partidasFiltradas.size());
    emit gameResultsReady(partidasFiltradas);
  } catch(NotAbleToConnectException&){
    emit searchError("Não foi possível realizar a busca no momento, tente novamente mais tarde.");
  } catch(FailedQueryException&){
    emit searchError("Não foi possível realizar a busca, há dados incorretos.");
  } catch(PropertyNotFoundException&){
    qDebug("Property Error");
  }
}

QVector<Partida> SearchProcessor::filterByCidade(QVector<Partida> partidas, QString cidade, QString estado){
  qDebug("Cidade: %s\nEstado: %s",cidade.toStdString().c_str(), estado.toStdString().c_str());
  if(cidade=="Todos" || cidade=="0"){

    return partidas;
  }
  QVector<Partida> partidasFiltradas;
  CidadeDAO* cdao = CidadeDAO::getInstance();
  if (estado == "Todos"){
    Cidade c = cdao->get(cidade.toStdString());
    foreach(Partida p, partidas){
      if(p.getCidade().getId() == c.getId()){
        partidasFiltradas.append(p);
      }
    }
    return partidasFiltradas;
  } else {
    std::vector<Cidade> cidades = cdao->getByProperty("idEstado", std::to_string(partidas[0].getCidade().getEstado().getId()));
    unsigned long i=0;
    while(i<(cidades.size()-1) && cidades[i].getNome().compare(cidade.toStdString())!= 0);
    if(i>=cidades.size()){
        emit searchError("Cidade Inexistente");
    }
    foreach(Partida p, partidas){
      if(p.getCidade().getId() == cidades[i].getId()){
        partidasFiltradas.append(p);
      }
    }
    return partidasFiltradas;
  }
}

QVector<Partida> SearchProcessor::filterByEstado(QVector<Partida> partidas, QString estado){
  if(estado == "Todos"){
    return partidas;
  }
  EstadoDAO* edao = EstadoDAO::getInstance();
  Estado e = edao->getByProperty("siglaEstado", estado.toStdString())[0];
  QVector<Partida> partidasFiltradas;
  foreach(Partida p, partidas){
    if(p.getCidade().getEstado().getId() == e.getId()){
        partidasFiltradas.append(p);
    }
  }
  return partidasFiltradas;
}
