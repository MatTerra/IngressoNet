#ifndef SEARCHPROCESSOR_H
#define SEARCHPROCESSOR_H

#include <QObject>
#include <QDateTime>
#include <QVector>

#include "partidadao.h"
#include "estadodao.h"
#include "cidadedao.h"
#include "cidade.h"
#include "estado.h"
#include "partida.h"
#include "failedqueryexception.h"
#include "notabletoconnectexception.h"

#include <vector>

class SearchProcessor : public QObject
{
  Q_OBJECT
public:
  explicit SearchProcessor(QObject *parent = nullptr);

signals:
  void gameResultsReady(QVector<Partida>);
  void searchError(QString);

public slots:
  void searchGame(QDateTime, QString, QString);

private:
  QVector<Partida> filterByCidade(QVector<Partida>, QString, QString);
  QVector<Partida> filterByEstado(QVector<Partida>, QString);
};

#endif // SEARCHPROCESSOR_H
