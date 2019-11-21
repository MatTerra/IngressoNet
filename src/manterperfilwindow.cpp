#include "manterperfilwindow.h"
#include "ui_manterperfilwindow.h"

ManterPerfilWindow::ManterPerfilWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ManterPerfilWindow)
{
  ui->setupUi(this);
  session = Session::getInstance();
  processor = new ManterPerfilProcessor(session);
  setupLayout();
  setupValidators();
  connectSignals();
  }

void ManterPerfilWindow::connectSignals(){
  connect(this, SIGNAL(changeSenhaValidationNeeded(QString, QString, QString)), this, SLOT(validateChangeSenhaData(QString,QString,QString)));
  connect(this, SIGNAL(changeSenhaValidData(QString)), processor, SLOT(changeSenhaRequested(QString)));
  connect(processor, SIGNAL(maintenanceError(QString)), this, SLOT(onMaintenanceError(QString)));
  connect(processor, SIGNAL(changeOperationDone(QString)), this, SLOT(onChangeDone(QString)));
  connect(this, SIGNAL(changeCardValid(unsigned long, unsigned int)), processor, SLOT(changeCardRequested(unsigned long, unsigned int)));
  connect(this, SIGNAL(deleteRequested()), processor, SLOT(onDeleteRequested()));
  connect(processor, SIGNAL(deleteDone()), session, SLOT(logout()));
  connect(session, SIGNAL(logoutDone()), this, SLOT(onDeleteDone()));
}

void ManterPerfilWindow::setupValidators(){
  QRegExp reSenha("^[0-9]{6,}$");
  QRegExpValidator *validatorSenha = new QRegExpValidator(reSenha, this);
  ui->oldSenhaEdit->setValidator(validatorSenha);
  ui->senhaEdit->setValidator(validatorSenha);
  ui->confSenhaEdit->setValidator(validatorSenha);

  QRegExp reCartao("^[0-9]{14,16}$");
  QRegExpValidator *validatorCartao = new QRegExpValidator(reCartao, this);
  ui->numCardEdit->setValidator(validatorCartao);
}

void ManterPerfilWindow::setupLayout(){
  ui->title->setText(session->getUsuario().getCPF().c_str());
  ui->numCardEdit->setText(std::to_string(session->getUsuario().getCartao().getNumero()).c_str());
  ui->numSegEdit->setText(std::to_string(session->getUsuario().getCartao().getNumSeguranca()).c_str());
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
  if(ui->senhaEdit->text() < 6 || ui->oldSenhaEdit->text() < 6 || ui->confSenhaEdit->text() < 6){
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

void ManterPerfilWindow::onMaintenanceError(QString message){
  QMessageBox::warning(this, "Erro na operação", message);
}

void ManterPerfilWindow::onChangeDone(QString message){
  QMessageBox::warning(this, "Alteração realizada", message);
}

void ManterPerfilWindow::on_salvarBtn_clicked(){
  ui->salvarBtn->setEnabled(false);
  if(Cartao::isValidNumber(ui->numCardEdit->text().toULong()) && ui->numSegEdit->text().toUInt() > 99 && ui->numSegEdit->text().toUInt() < 10000){
    emit changeCardValid(ui->numCardEdit->text().toULong(), ui->numSegEdit->text().toUInt());
  } else {
    QMessageBox::warning(this, "Erro", "Número de cartão inválido!");
  }
}

void ManterPerfilWindow::on_deleteBtn_clicked(){
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Confirmação", "Sua conta será deletada e todos os seus ingressos serão perdidos.\nTem certeza que deseja continuar?.",
                                QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel);
  if (reply == QMessageBox::Yes) {
    emit deleteRequested();
  }
}

void ManterPerfilWindow::onDeleteDone(){
  QMessageBox::warning(this, "Perfil apagado", "Seu perfil foi apagado com sucesso!");
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new LoginWindow(mw));
  this->destroy();
}
