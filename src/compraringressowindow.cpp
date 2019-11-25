#include "compraringressowindow.h"
#include "ui_compraringressowindow.h"

ComprarIngressoWindow::ComprarIngressoWindow(Partida partida, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ComprarIngressoWindow),
  partida(partida){
  ui->setupUi(this);
  session = Session::getInstance();
  processor = new ComprarIngressoProcessor();
  setupLabels();
  connect(this, SIGNAL(compraRequest(int,Partida&)), processor, SLOT(compraRequested(int, Partida&)));
  connect(processor, SIGNAL(purchaseError(QString)), this, SLOT(onPurchaseError(QString)));
  connect(processor, SIGNAL(purchaseDone()), this, SLOT(onPurchaseDone()));
}

ComprarIngressoWindow::~ComprarIngressoWindow()
{
  delete ui;
}

void ComprarIngressoWindow::setupLabels(){
  ui->nomeJogoLbl->setText(partida.getJogo().getNome().c_str());
  ui->dataPartidaLbl->setText(partida.getData().toString("dd/MM/yyyy"));
  ui->horaLbl->setText(partida.getData().toString("hh:mm"));
  ui->precoLbl->setText(std::to_string(partida.getPreco()).c_str());
  ui->cidadeEstadoLbl->setText((partida.getCidade().getNome()+"/"+partida.getCidade().getEstado().getSigla()).c_str());
  ui->ingDispLbl->setText(("/"+std::to_string(partida.getDisponibilidade())+" disponíveis").c_str());
  ui->spinBox->setValue(1);
  ui->spinBox->setMaximum(partida.getDisponibilidade());
  ui->totalLbl->setText(std::to_string(partida.getPreco()).c_str());
  ui->cpfUserLbl->setText(session->getUsuario().getCPF().c_str());
}

void ComprarIngressoWindow::on_spinBox_valueChanged(int arg1){
  ui->totalLbl->setText(std::to_string(partida.getPreco()*arg1).c_str());
}

void ComprarIngressoWindow::on_voltarBtn_clicked(){
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Confirmação", "Sua compra será cancelada e você voltará para a tela de pesquisa.",
                                QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Cancel);
  if (reply == QMessageBox::Ok) {
    QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
    mw->setCentralWidget(new SearchJogoWindow(mw));
    this->destroy();
  }
}

void ComprarIngressoWindow::on_cancelBtn_clicked(){
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Confirmação", "Sua compra será cancelada e você voltará para o Dashboard.",
                                QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Cancel);
  if (reply == QMessageBox::Ok) {
    QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
    mw->setCentralWidget(new DashboardWindow(mw));
    this->destroy();
  }
}

void ComprarIngressoWindow::on_comprarBtn_clicked(){
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Confirmação", "Sua compra será efetuada no total de "+ui->totalLbl->text()+" reais.\nTem certeza que deseja prosseguir?",
                                QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel);
  if (reply == QMessageBox::Yes) {
    emit compraRequest(ui->spinBox->value(), this->partida);
  }
}

void ComprarIngressoWindow::onPurchaseError(QString message){
  QMessageBox::warning(this, "Erro na compra", message);
}

void ComprarIngressoWindow::onPurchaseDone(){
  QMessageBox::warning(this, "Compra Efetuada", "Sua compra foi realizada com sucesso!");
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new VerIngressosWindow(mw));
  this->destroy();
}
