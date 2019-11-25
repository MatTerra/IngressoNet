#ifndef COMPRARINGRESSOPROCESSOR_H
#define COMPRARINGRESSOPROCESSOR_H

#include <QObject>

#include "session.h"
#include "ingresso.h"
#include "ingressodao.h"


class ComprarIngressoProcessor : public QObject
{
  Q_OBJECT
public:
  explicit ComprarIngressoProcessor(QObject *parent = nullptr);

signals:
  void purchaseError(QString);
  void purchaseDone();
public slots:
  void compraRequested(int, Partida&);
private:
  Session* session;
};

#endif // COMPRARINGRESSOPROCESSOR_H
