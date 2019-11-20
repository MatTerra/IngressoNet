#ifndef SEARCHJOGOWINDOW_H
#define SEARCHJOGOWINDOW_H

#include <QWidget>
#include <QListView>
#include <QMainWindow>
#include <QDateTime>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QVector>

#include <vector>

#include "session.h"
#include "estado.h"
#include "estadodao.h"
#include "cidade.h"
#include "cidadedao.h"
#include "dashboardwindow.h"
#include "searchprocessor.h"

namespace Ui {
  class SearchJogoWindow;
}

class SearchJogoWindow : public QWidget
{
  Q_OBJECT

public:
  explicit SearchJogoWindow(QWidget *parent = nullptr);
  ~SearchJogoWindow();

signals:
  void requestSearchResults(QDateTime, QString, QString);

private slots:
  void on_estadoBox_currentIndexChanged(const QString &arg1);

  void on_voltarBtn_clicked();

  void on_pesquisarBtn_clicked();

  void displayGameResults(QVector<Partida>);

private:
  Ui::SearchJogoWindow *ui;
  Session* session;
  SearchProcessor* processor;
  QStandardItemModel* model;
  void fillEstados();
  void setupTable();
};

#endif // SEARCHJOGOWINDOW_H
