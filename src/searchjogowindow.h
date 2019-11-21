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
#include "compraritem.h"
#include "compraringressowindow.h"

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
  void requestCompraIngresso(Partida&);

private slots:
  void on_estadoBox_currentIndexChanged(const QString &arg1);

  void on_voltarBtn_clicked();

  void on_pesquisarBtn_clicked();

  void displayGameResults(QVector<Partida>);

  void proccedToCompraIngresso(Partida&);

  void on_resultadoTable_clicked(const QModelIndex &index);

private:
  Ui::SearchJogoWindow *ui;
  Session* session;
  SearchProcessor* processor;
  QStandardItemModel* model;
  void fillEstados();
  void setupLayout();
  void setupTable();
  void connectSignals();
  QList<QStandardItem*> createRow(Partida&);
};

#endif // SEARCHJOGOWINDOW_H
