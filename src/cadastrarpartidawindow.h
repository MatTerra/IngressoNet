#ifndef CADASTRARPARTIDAWINDOW_H
#define CADASTRARPARTIDAWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include "estado.h"
#include "estadodao.h"
#include "jogo.h"
#include "jogodao.h"
#include "partida.h"
#include "partidadao.h"
#include "dashboardwindow.h"
#include "cadastrarpartidaprocessor.h"

namespace Ui {
  class CadastrarPartidaWindow;
}

class CadastrarPartidaWindow : public QWidget
{
  Q_OBJECT

public:
  explicit CadastrarPartidaWindow(QWidget *parent = nullptr);
  ~CadastrarPartidaWindow();

signals:
  void requestCadastroPartida(Partida&);

private slots:
  void on_VoltarBtn_clicked();

  void on_cancelBtn_clicked();

  void on_estadoBox_currentIndexChanged(const QString &);

  void on_cadastrarBtn_clicked();

  void onCreateError(QString);

  void onCadastroPartidaDone();

private:
  Ui::CadastrarPartidaWindow *ui;
  Session* session;
  CadastrarPartidaProcessor* processor;
  void fillEstados();
  void fillCidade(int);
};

#endif // CADASTRARPARTIDAWINDOW_H
