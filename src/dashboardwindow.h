#ifndef DASHBOARDWINDOW_H
#define DASHBOARDWINDOW_H

#include <QWidget>
#include <QMainWindow>

#include "session.h"
#include "loginwindow.h"
#include "searchjogowindow.h"
#include "veringressoswindow.h"
#include "manterperfilwindow.h"
#include "cadastrarpartidawindow.h"

namespace Ui {
  class DashboardWindow;
}

class DashboardWindow : public QWidget
{
  Q_OBJECT


public:
  /** Construtor Padrão */
  explicit DashboardWindow(QWidget *parent = nullptr);

  /** Destrutor Padrão */
  ~DashboardWindow();


signals:
  void logoutRequested();


private slots:
  void on_searchJogoBtn_clicked();

  void on_logoutBtn_clicked();

  void finishLogout();

  void on_verIngressosBtn_clicked();

  void on_configButton_clicked();

  void on_cadastrarPartidaBtn_clicked();

private:
  Ui::DashboardWindow *ui; //!< Atributo de instância "ui". Representa a interface gráfica da tela de dashboard.
  Session* session;
};

#endif // DASHBOARDWINDOW_H
