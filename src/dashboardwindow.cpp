#include "dashboardwindow.h"
#include "ui_dashboardwindow.h"

DashboardWindow::DashboardWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::DashboardWindow){
  ui->setupUi(this);

  session = Session::getInstance();
  ui->usrLabel->setText(session->getUsuario().getCPF().c_str());

  connect(this, SIGNAL(logoutRequested()), session, SLOT(logout()));
  connect(session, SIGNAL(logoutDone()), this, SLOT(finishLogout()));
}

DashboardWindow::~DashboardWindow(){
  delete ui;
}

void DashboardWindow::on_searchJogoBtn_clicked(){
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new SearchJogoWindow(mw));
  this->destroy();
}

void DashboardWindow::on_logoutBtn_clicked(){
  emit logoutRequested();
}

void DashboardWindow::finishLogout(){
  delete session;
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new LoginWindow(mw));
  qDebug("Logouting");
  this->destroy();
}
