#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow){
    ui->setupUi(this);
    QString style="QMainWindow{border-image: url(:/res/bkg.jpg) 0 0 0 0 stretch stretch;}\nQLabel, QLineEdit{color:white;}";
    this->setStyleSheet(style);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_btnEntrar_clicked()
{
    emit loginSolicitado("Q", "t");
}
