#ifndef CADASTRARPARTIDAPROCESSOR_H
#define CADASTRARPARTIDAPROCESSOR_H

#include <QObject>

#include "partida.h"
#include "partidadao.h"
#include "jogo.h"
#include "jogodao.h"

class CadastrarPartidaProcessor : public QObject
{
  Q_OBJECT
public:
  explicit CadastrarPartidaProcessor(QObject *parent = nullptr);

signals:
  void createError(QString);
  void cadastroPartidaDone();

public slots:
  void cadastroPartidaRequested(Partida&);
};

#endif // CADASTRARPARTIDAPROCESSOR_H
