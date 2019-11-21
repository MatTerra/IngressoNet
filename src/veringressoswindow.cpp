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
  setupTable();
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
