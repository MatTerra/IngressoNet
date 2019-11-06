#include "signupwindow.h"
#include "ui_signupwindow.h"

SignupWindow::SignupWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SignupWindow){
  ui->setupUi(this);
}

SignupWindow::~SignupWindow(){
  delete ui;
}

void SignupWindow::on_pushButton_clicked(){
  QLineEdit* cardEdit = this->findChild<QLineEdit *>("cardEdit");
  QString cardNumber = cardEdit->text();
  QLineEdit* cpfEdit = this->findChild<QLineEdit *>("cpfEdit");
  QString cpf = cpfEdit->text();
  QString senha = this->findChild<QLineEdit *>("senhaEdit")->text();
  QLineEdit* rSenhaEdit = this->findChild<QLineEdit *>("rSenhaEdit");
  QString rSenha = rSenhaEdit->text();

  if(!Usuario::isValidCPF(cpf.toStdString())){
    cpfEdit->setText("");
    cpfEdit->setPlaceholderText("CPF Inválido!");
    cpfEdit->setStyleSheet("color:red;font:bold;");
    qDebug("Invalid CPF");
  }
  qDebug("Valid CPF");
  if(senha!=rSenha){
      rSenhaEdit->setText("");
      rSenhaEdit->setPlaceholderText("As senhas não são iguais!");
      rSenhaEdit->setStyleSheet("color:red;font:bold;");
      qDebug("passwords don't match");
  }
  qDebug("passwords match");
  if(!Cartao::isValidNumber(cardNumber.toULong())){
    cardEdit->setText("");
    cardEdit->setPlaceholderText("Cartão Inválido!");
    cardEdit->setStyleSheet("color:red; font:bold;");
    qDebug("Invalid Number");
  }
  qDebug("Valid Number");
}

void SignupWindow::on_cardEdit_textEdited(const QString &arg1){
  QLineEdit* cardEdit = this->findChild<QLineEdit *>("cardEdit");
  cardEdit->setStyleSheet("color:white; font:regular;");
  cardEdit->setPlaceholderText("(Somente números)");
}

void SignupWindow::on_cpfEdit_textEdited(const QString &arg1){
  QLineEdit* cpfEdit = this->findChild<QLineEdit *>("cpfEdit");
  cpfEdit->setStyleSheet("color:white; font:regular;");
  cpfEdit->setPlaceholderText("");

}

void SignupWindow::on_rSenhaEdit_textEdited(const QString &arg1){
  QLineEdit* rSenhaEdit = this->findChild<QLineEdit *>("rSenhaEdit");
  rSenhaEdit->setStyleSheet("color:white; font:regular;");
  rSenhaEdit->setPlaceholderText("");
}
