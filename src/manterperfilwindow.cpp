#include "manterperfilwindow.h"
#include "ui_manterperfilwindow.h"

ManterPerfilWindow::ManterPerfilWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ManterPerfilWindow)
{
  ui->setupUi(this);
  session = Session::getInstance();
  processor = new ManterPerfilProcessor(session);
  ui->title->setText(session->getUsuario().getCPF().c_str());
  ui->numCardEdit->setText(std::to_string(session->getUsuario().getCartao().getNumero()).c_str());
  ui->numSegEdit->setText(std::to_string(session->getUsuario().getCartao().getNumSeguranca()).c_str());
  QRegExp reSenha("^[0-9]{6,}$");
  QRegExpValidator *validatorSenha = new QRegExpValidator(reSenha, this);
  ui->oldSenhaEdit->setValidator(validatorSenha);
  ui->senhaEdit->setValidator(validatorSenha);
  ui->confSenhaEdit->setValidator(validatorSenha);
  connect(this, SIGNAL(changeSenhaValidationNeeded(QString, QString, QString)), this, SLOT(validateChangeSenhaData(QString,QString,QString)));
  connect(this, SIGNAL(changeSenhaValidData(QString)), processor, SLOT(changeSenhaRequested(QString)));
}

ManterPerfilWindow::~ManterPerfilWindow()
{
  delete ui;
}

void ManterPerfilWindow::on_numCardEdit_textEdited(const QString &arg1){
  checkCardDataChanged(arg1, ui->numSegEdit->text());
}

void ManterPerfilWindow::on_numSegEdit_textEdited(const QString &arg1){
  checkCardDataChanged(ui->numCardEdit->text(), arg1);
}

void ManterPerfilWindow::checkCardDataChanged(QString numCard, QString numSeg){
  QString oldNumCard = std::to_string(session->getUsuario().getCartao().getNumero()).c_str();
  QString oldNumSeg = std::to_string(session->getUsuario().getCartao().getNumSeguranca()).c_str();
  if(oldNumCard==numCard && oldNumSeg==numSeg){
    ui->salvarBtn->setEnabled(false);
  } else {
    ui->salvarBtn->setEnabled(true);
  }
}

void ManterPerfilWindow::on_voltarBtn_clicked(){
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new DashboardWindow(mw));
  this->destroy();
}

void ManterPerfilWindow::validateChangeSenhaData(QString oldSenha, QString senha, QString confSenha){
  QString oldSenhaUser = session->getUsuario().getSenha().c_str();
  if(oldSenha == oldSenhaUser && senha == confSenha){
      emit changeSenhaValidData(senha);
  }
  else {
    if(oldSenha!=oldSenhaUser){
      emit maintenanceError("Senha incorreta!");
    } else {
      emit maintenanceError("As senhas fornecidas não são iguais!");
    }

  }
}

void ManterPerfilWindow::on_changeSenhaBtn_clicked(){
    emit changeSenhaValidationNeeded(ui->oldSenhaEdit->text(), ui->senhaEdit->text(), ui->confSenhaEdit->text());
}

void ManterPerfilWindow::checkSenhaLen(){
  if(ui->senhaEdit->text() < 6 | ui->oldSenhaEdit->text() < 6 | ui->confSenhaEdit->text() < 6){
    ui->changeSenhaBtn->setEnabled(false);
  } else {
    ui->changeSenhaBtn->setEnabled(true);
  }
}

void ManterPerfilWindow::on_oldSenhaEdit_textEdited(const QString &){
    checkSenhaLen();
}

void ManterPerfilWindow::on_senhaEdit_textEdited(const QString &){
    checkSenhaLen();
}

void ManterPerfilWindow::on_confSenhaEdit_textEdited(const QString &){
    checkSenhaLen();
}
