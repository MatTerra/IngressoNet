#ifndef VERINGRESSOSWINDOW_H
#define VERINGRESSOSWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include "session.h"
#include "dashboardwindow.h"

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
};

#endif // VERINGRESSOSWINDOW_H
