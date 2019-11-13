#include "signupwindow.h"
#include "ui_signupwindow.h"

SignupWindow::SignupWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SignupWindow){
  ui->setupUi(this);
  cardEdit = this->findChild<QLineEdit *>("cardEdit");
  cpfEdit = this->findChild<QLineEdit *>("cpfEdit");
  senhaEdit = this->findChild<QLineEdit *>("senhaEdit");
  rSenhaEdit = this->findChild<QLineEdit *>("rSenhaEdit");
  numSecEdit = this->findChild<QLineEdit *>("numSecEdit");
  processor = new SignupProcessor(nullptr);

  QRegExp re("^[0-9]{3}\.[0-9]{3}\.[0-9]{3}-[0-9]{2}$");
  QRegExpValidator *validator = new QRegExpValidator(re, this);
  cpfEdit->setValidator(validator);

  connect(this, SIGNAL(validSignupData()), processor, SLOT(verifyExistingUser()));
  connect(this,SIGNAL(validationNeeded()), this, SLOT(validateData()));
}

SignupWindow::~SignupWindow(){
  delete ui;
}

void SignupWindow::on_pushButton_clicked(){

  QString cardNumber = cardEdit->text();
  QString cpf = cpfEdit->text();
  QString senha = senhaEdit->text();
  QString rSenha = rSenhaEdit->text();
  QString numSec = numSecEdit->text();

  Cartao cartao(cardNumber.toULong(), numSec.toUInt());
  Usuario user(cpf.toStdString(),senha.toStdString(),cartao);

  emit validationNeeded(user, rSenha);
}

void SignupWindow::validateData(Usuario& usuario, QString rSenha){
  bool validData=true;
  if(usuario.getSenha() != rSenha.toStdString()){
      rSenhaEdit->setText("");
      rSenhaEdit->setPlaceholderText("As senhas não são iguais!");
      rSenhaEdit->setStyleSheet("color:red;font:bold;");
      qDebug("passwords don't match");
      validData=false;
  }
  if(!Usuario::isValidCPF(usuario.getCPF())){
    cpfEdit->setText("");
    cpfEdit->setPlaceholderText("CPF Inválido!");
    cpfEdit->setStyleSheet("color:red;font:bold;");
    qDebug("Invalid CPF");
    validData=false;
  }
  qDebug("Valid CPF");
  if(usuario.getSenha().length()<6){
      senhaEdit->setText("");
      senhaEdit->setPlaceholderText("A senha deve ter ao menos 6 dígitos!");
      senhaEdit->setStyleSheet("color:red;font:bold;");
      qDebug("password to short");
      validData=false;
  }

  qDebug("passwords match");
  if(!Cartao::isValidNumber(usuario.getCartao().getNumero())){
    cardEdit->setText("");
    cardEdit->setPlaceholderText("Cartão Inválido!");
    cardEdit->setStyleSheet("color:red; font:bold;");
    qDebug("Invalid Number");
    validData=false;
  }
  qDebug("Valid Number");
  if(usuario.getCartao().getNumSeguranca()<100){
      numSecEdit->setText("");
      numSecEdit->setPlaceholderText("Número de Segurança Inválido!");
      numSecEdit->setStyleSheet("color:red; font:bold;");
      qDebug("Invalid Security Number");
      validData=false;
  }
  if(validData){
    emit validSignupData(usuario);
  }
}

void SignupWindow::on_cardEdit_textEdited(const QString &arg1){
  qDebug("%s", arg1.toStdString().c_str());
  cardEdit->setStyleSheet("color:white; font:regular;");
  cardEdit->setPlaceholderText("(Somente números)");
}

void SignupWindow::on_cpfEdit_textEdited(const QString &arg1){
  qDebug("%s", arg1.toStdString().c_str());
  QString text = arg1;
  int pos;
  if(cpfEdit->validator()->validate(text, pos)!=QValidator::Acceptable){
      cpfEdit->setStyleSheet("color:red;");
    } else{
      cpfEdit->setStyleSheet("color:white; font:regular;");
      cpfEdit->setPlaceholderText("xxx.xxx.xxx-xx");
    }
}

void SignupWindow::on_rSenhaEdit_textEdited(const QString &arg1){
  qDebug("%s", arg1.toStdString().c_str());
  rSenhaEdit->setStyleSheet("color:white; font:regular;");
  rSenhaEdit->setPlaceholderText("");
}

void SignupWindow::on_senhaEdit_textEdited(const QString &arg1){
  qDebug("%s", arg1.toStdString().c_str());
  senhaEdit->setStyleSheet("color:white; font:regular;");
  senhaEdit->setPlaceholderText("");
}

void SignupWindow::on_numSecEdit_textEdited(const QString &arg1){
  qDebug("%s", arg1.toStdString().c_str());
  numSecEdit->setStyleSheet("color:white; font:regular;");
  numSecEdit->setPlaceholderText("");
}
