#ifndef VERINGRESSOSWINDOW_H
#define VERINGRESSOSWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include "session.h"
#include "dashboardwindow.h"
#include "ingresso.h"
#include "ingressodao.h"

namespace Ui {
  class VerIngressosWindow;
}

class VerIngressosWindow : public QWidget
{
  Q_OBJECT

public:
  explicit VerIngressosWindow(QWidget *parent = nullptr);
  ~VerIngressosWindow();

private slots:
  void on_voltarBtn_clicked();

private:
  Ui::VerIngressosWindow *ui;
  Session* session;
  QStandardItemModel* model;
  void setupTable();
  void fillTable();
  QList<QStandardItem*> createRow(Ingresso&);
};

#endif // VERINGRESSOSWINDOW_H
