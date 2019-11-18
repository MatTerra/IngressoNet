#include "searchjogowindow.h"
#include "ui_searchjogowindow.h"

SearchJogoWindow::SearchJogoWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SearchJogoWindow){
  ui->setupUi(this);
  ui->estadoBox->setView(new QListView());
  ui->cidadeBox->setView(new QListView());
  session = Session::getInstance();
  fillEstados();
}

SearchJogoWindow::~SearchJogoWindow()
{
  delete ui;
}

void SearchJogoWindow::fillEstados(){
  EstadoDAO* edao = EstadoDAO::getInstance();
  std::vector<Estado> estados = edao->getAll();
  ui->estadoBox->addItem("Todos");
  foreach (Estado estado, estados) {
    ui->estadoBox->addItem(estado.getSigla().c_str());
  }
}

void SearchJogoWindow::on_estadoBox_currentIndexChanged(const QString&){
  ui->cidadeBox->clear();
  CidadeDAO* cdao = CidadeDAO::getInstance();
  std::vector<Cidade> cidades;
  if(ui->estadoBox->currentIndex()>0){
    cidades = cdao->getByProperty("idEstado",std::to_string(ui->estadoBox->currentIndex()));
  } else {
    cidades = cdao->getAll();
  }
  if(cidades[0].getId()==-1){
    ui->cidadeBox->addItem("Não há");
    ui->cidadeBox->setEnabled(false);
  } else {
    foreach (Cidade cidade, cidades) {
      ui->cidadeBox->addItem(cidade.getNome().c_str());
    }
    ui->cidadeBox->setEnabled(true);
  }
}

void SearchJogoWindow::on_voltarBtn_clicked(){
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new DashboardWindow(mw));
  this->destroy();
}
