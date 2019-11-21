#include "signupwindow.h"
#include "ui_signupwindow.h"

SignupWindow::SignupWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SignupWindow){
  ui->setupUi(this);

  processor = new SignupProcessor(nullptr);

  setupValidators();
  connectSignals();
}

void SignupWindow::setupValidators(){
  QRegExp reCpf("^[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}-[0-9]{2}$");
  QRegExpValidator *validatorCpf = new QRegExpValidator(reCpf, this);
  ui->cpfEdit->setValidator(validatorCpf);

  QRegExp reCartao("^[0-9]{14,16}$");
  QRegExpValidator *validatorCartao = new QRegExpValidator(reCartao, this);
  ui->cardEdit->setValidator(validatorCartao);

  QRegExp reNumSec("^[0-9]{3,4}$");
  QRegExpValidator *validatorNumSec= new QRegExpValidator(reNumSec, this);
  ui->numSecEdit->setValidator(validatorNumSec);

  QRegExp reSenha("^[0-9]{6,}$");
  QRegExpValidator *validatorSenha = new QRegExpValidator(reSenha, this);
  ui->senhaEdit->setValidator(validatorSenha);
  ui->rSenhaEdit->setValidator(validatorSenha);
}

void SignupWindow::connectSignals(){
  connect(this, SIGNAL(validSignupData(Usuario&)), processor, SLOT(verifyExistingUser(Usuario&)));
  connect(processor, SIGNAL(registrationError(QString)), this, SLOT(onSignupError(QString)));
  connect(this,SIGNAL(validationNeeded(Usuario&, QString)), this, SLOT(validateData(Usuario&, QString)));
  connect(processor, SIGNAL(userRegistered()), this, SLOT(signupEnded()));
}

SignupWindow::~SignupWindow(){
  delete ui;
  delete processor;
}

void SignupWindow::validateData(Usuario& usuario, QString rSenha){
  bool validData=true;
  if(usuario.getSenha() != rSenha.toStdString()){
    setErrorMessage(ui->rSenhaEdit, "As senhas não são iguais!");
    validData=false;
  }
  if(!Usuario::isValidCPF(usuario.getCPF())){
    setErrorMessage(ui->cpfEdit, "CPF Inválido!");
    validData=false;
  }
  if(usuario.getSenha().length() < 6){
    setErrorMessage(ui->senhaEdit, "A senha deve ter ao menos 6 dígitos!");
    validData=false;
  }
  if(!Cartao::isValidNumber(usuario.getCartao().getNumero())){
    setErrorMessage(ui->cardEdit, "Cartão Inválido!");
    validData=false;
  }
  if(usuario.getCartao().getNumSeguranca() < 100 || usuario.getCartao().getNumSeguranca() > 9999){
    setErrorMessage(ui->numSecEdit, "Número de Segurança Inválido!");
    validData=false;
  }
  if(validData){
    emit validSignupData(usuario);
  }
}

void SignupWindow::setErrorMessage(QLineEdit* lEdit, QString message){
  lEdit->setText("");
  lEdit->setPlaceholderText(message);
  lEdit->setStyleSheet("color:red; font:bold;");
}

void SignupWindow::onSignupError(QString message){
  QMessageBox::warning(this, "Erro no Cadastro", message);
}

void SignupWindow::signupEnded(){
  QMessageBox::warning(this, "Cadastro efetuado", "Cadastro efetuado com sucesso!");
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new LoginWindow(mw));
  this->destroy();
}

void SignupWindow::on_signupBtn_clicked(){

  QString cardNumber = ui->cardEdit->text();
  QString cpf = ui->cpfEdit->text();
  QString senha = ui->senhaEdit->text();
  QString rSenha = ui->rSenhaEdit->text();
  QString numSec = ui->numSecEdit->text();

  Cartao cartao(cardNumber.toULong(), numSec.toUInt(), cpf.toStdString());
  Usuario user(cpf.toStdString(),senha.toStdString(),cartao);
  emit validationNeeded(user, rSenha);
}

void SignupWindow::validate(QLineEdit* lEdit, QString placeholder){
  QString text = lEdit->text();
  int pos;
  if(lEdit->validator()->validate(text, pos) != QValidator::Acceptable){
      lEdit->setStyleSheet("color:red;");
  } else{
      lEdit->setStyleSheet("color:white; font:regular;");
      lEdit->setPlaceholderText(placeholder);
  }
}

void SignupWindow::on_cardEdit_textEdited(const QString&){
  validate(ui->cardEdit, "(Somente números)");
}

void SignupWindow::on_cpfEdit_textEdited(const QString &arg1){
  validate(ui->cpfEdit, "xxx.xxx.xxx-xx");
  if(arg1.length() == 3 || arg1.length() == 7){
    ui->cpfEdit->insert(".");
  }
  if(arg1.length() == 11){
    ui->cpfEdit->insert("-");
  }
}

void SignupWindow::on_rSenhaEdit_textEdited(const QString&){
  validate(ui->rSenhaEdit, "");
}

void SignupWindow::on_senhaEdit_textEdited(const QString&){
  validate(ui->senhaEdit, ">6 números");
}

void SignupWindow::on_numSecEdit_textEdited(const QString&){
  validate(ui->numSecEdit, "");
}

void SignupWindow::on_voltarBtn_clicked(){
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new LoginWindow(mw));
  this->destroy();
}
