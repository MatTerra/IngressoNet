#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::LoginWindow)
{
  ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
  delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
    mw->setCentralWidget(new SignupWindow(mw));
    this->destroy();
}
