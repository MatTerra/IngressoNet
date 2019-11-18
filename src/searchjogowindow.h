#ifndef SEARCHJOGOWINDOW_H
#define SEARCHJOGOWINDOW_H

#include <QWidget>
#include <QListView>
#include <QMainWindow>

#include <vector>

#include "session.h"
#include "estado.h"
#include "estadodao.h"
#include "cidade.h"
#include "cidadedao.h"
#include "dashboardwindow.h"

namespace Ui {
  class SearchJogoWindow;
}

class SearchJogoWindow : public QWidget
{
  Q_OBJECT

public:
  explicit SearchJogoWindow(QWidget *parent = nullptr);
  ~SearchJogoWindow();

private slots:
  void on_estadoBox_currentIndexChanged(const QString &arg1);

  void on_voltarBtn_clicked();

private:
  Ui::SearchJogoWindow *ui;
  Session* session;
  void fillEstados();
};

#endif // SEARCHJOGOWINDOW_H
