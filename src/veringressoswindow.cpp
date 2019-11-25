#include "veringressoswindow.h"
#include "ui_veringressoswindow.h"

VerIngressosWindow::VerIngressosWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::VerIngressosWindow){
  ui->setupUi(this);

  session = Session::getInstance();
  model = new QStandardItemModel();
  ui->ingressosTable->setModel(model);
  ui->ingressosTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  fillTable();
}

VerIngressosWindow::~VerIngressosWindow()
{
  delete ui;
}

void VerIngressosWindow::on_voltarBtn_clicked(){
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new DashboardWindow(mw));
  this->destroy();
}

void VerIngressosWindow::setupTable(){
  model->setHorizontalHeaderItem(0, new QStandardItem("Código"));
  model->setHorizontalHeaderItem(1, new QStandardItem("Jogo"));
  model->setHorizontalHeaderItem(2, new QStandardItem("Data"));
  model->setHorizontalHeaderItem(3, new QStandardItem("Hora"));
  model->setHorizontalHeaderItem(4, new QStandardItem("Cidade"));
  model->setHorizontalHeaderItem(5, new QStandardItem("Estado"));
}

void VerIngressosWindow::fillTable(){
  model->clear();
  setupTable();
  ui->ingressosTable->clearSpans();
  std::vector<Ingresso> ingressos = IngressoDAO::getInstance()->getByProperty("cpf", session->getUsuario().getCPF());
  foreach(Ingresso ingresso, ingressos){
    QList<QStandardItem*> row = createRow(ingresso);
    model->appendRow(row);
  }
  ui->ingressosTable->resizeColumnsToContents();
}

QList<QStandardItem*> VerIngressosWindow::createRow(Ingresso& ingresso){
  QList<QStandardItem*> columns;

  columns << new QStandardItem(std::to_string(ingresso.getCodigo()).c_str());
  columns << new QStandardItem(ingresso.getPartida().getJogo().getNome().c_str());
  columns << new QStandardItem(ingresso.getPartida().getData().toString("dd/MM/yyyy"));
  columns << new QStandardItem(ingresso.getPartida().getData().toString("hh:mm"));
  columns << new QStandardItem(ingresso.getPartida().getCidade().getNome().c_str());
  columns << new QStandardItem(ingresso.getPartida().getCidade().getEstado().getSigla().c_str());

  foreach(QStandardItem* item, columns){
      item->setEditable(false);
  }
  return columns;
}
