#ifndef COMPRARINGRESSOWINDOW_H
#define COMPRARINGRESSOWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>

#include "partida.h"
#include "session.h"
#include "searchjogowindow.h"
#include "dashboardwindow.h"
#include "compraringressoprocessor.h"
#include "veringressoswindow.h"

namespace Ui {
  class ComprarIngressoWindow;
}

class ComprarIngressoWindow : public QWidget
{
  Q_OBJECT

public:
  explicit ComprarIngressoWindow(Partida partida, QWidget *parent = nullptr);
  ~ComprarIngressoWindow();

signals:
  void compraRequest(int, Partida&);

private slots:
  void on_spinBox_valueChanged(int arg1);

  void on_voltarBtn_clicked();

  void on_cancelBtn_clicked();

  void on_comprarBtn_clicked();

  void onPurchaseError(QString);

  void onPurchaseDone();

private:
  Ui::ComprarIngressoWindow *ui;
  Partida partida;
  Session* session;
  ComprarIngressoProcessor* processor;
  void setupLabels();

};

#endif // COMPRARINGRESSOWINDOW_H
