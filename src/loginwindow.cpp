#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::LoginWindow){
  ui->setupUi(this);

  QRegExp reCpf("^[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}-[0-9]{2}$");
  QRegExpValidator *validatorCpf = new QRegExpValidator(reCpf, this);
  ui->cpfEdit->setValidator(validatorCpf);

  QRegExp reSenha("^[0-9]{6,}$");
  QRegExpValidator *validatorSenha = new QRegExpValidator(reSenha, this);
  ui->senhaEdit->setValidator(validatorSenha);

  ui->errorLabel->setStyleSheet("color:red;");

  connect(this, SIGNAL(loginDataValidationNeeded(QString, QString)), this, SLOT(validateData(QString, QString)));
}

LoginWindow::~LoginWindow()
{
  delete ui;
}

void LoginWindow::on_signupBtn_clicked(){
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new SignupWindow(mw));
  this->destroy();
}

void LoginWindow::on_loginBtn_clicked(){
  QString cpf = ui->cpfEdit->text();
  QString senha = ui->senhaEdit->text();
  emit loginDataValidationNeeded(cpf, senha);
}

void LoginWindow::validateData(QString cpf, QString senha){
  if(!Usuario::isValidCPF(cpf.toStdString())){
    ui->errorLabel->setText("CPF inválido!");
    return;
  }
  if(senha.length()<6){
    if(ui->errorLabel->text() == ""){
      ui->errorLabel->setText("Senha inválida!");
    }
    return;
  }
  emit validData(cpf, senha);
}

void LoginWindow::on_cpfEdit_textEdited(const QString &arg1){
  if(ui->errorLabel->text() == "CPF inválido!"){
    ui->errorLabel->setText("");
  }
  if(arg1.length() == 3 || arg1.length() == 7){
    ui->cpfEdit->insert(".");
  }
  if(arg1.length() == 11){
    ui->cpfEdit->insert("-");
  }
}

void LoginWindow::on_senhaEdit_textEdited(const QString &arg1){
  if(ui->errorLabel->text() == "Senha inválida!"){
    ui->errorLabel->setText("");
  }
}
