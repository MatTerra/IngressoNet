#include "searchjogowindow.h"
#include "ui_searchjogowindow.h"

SearchJogoWindow::SearchJogoWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SearchJogoWindow){
  ui->setupUi(this);
  ui->estadoBox->setView(new QListView());
  ui->cidadeBox->setView(new QListView());
  ui->incioDateTime->setDateTime(QDateTime::currentDateTime());
  model = new QStandardItemModel();
  ui->resultadoTable->setModel(model);
  setupTable();
  session = Session::getInstance();
  processor = new SearchProcessor();
  connect(this, SIGNAL(requestSearchResults(QDateTime, QString, QString)), processor, SLOT(searchGame(QDateTime, QString, QString)));
  connect(processor, SIGNAL(gameResultsReady(QVector<Partida>)), this, SLOT(displayGameResults(QVector<Partida>)));
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
  ui->cidadeBox->addItem("Todos");
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
    ui->pesquisarBtn->setEnabled(false);
  } else {
    foreach (Cidade cidade, cidades) {
      ui->cidadeBox->addItem(cidade.getNome().c_str());
    }
    ui->cidadeBox->setEnabled(true);
    ui->pesquisarBtn->setEnabled(true);
  }
}

void SearchJogoWindow::on_voltarBtn_clicked(){
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new DashboardWindow(mw));
  this->destroy();
}

void SearchJogoWindow::on_pesquisarBtn_clicked(){
  if(ui->estadoBox->currentIndex()!=0){
    emit requestSearchResults(ui->incioDateTime->dateTime(), ui->cidadeBox->currentText(), ui->estadoBox->currentText());
  } else {
    emit requestSearchResults(ui->incioDateTime->dateTime(), std::to_string(ui->cidadeBox->currentIndex()).c_str(), ui->estadoBox->currentText());
  }
}

void SearchJogoWindow::displayGameResults(QVector<Partida> partidas){
  qDebug("Inicio display");
  model->clear();
  setupTable();
  ui->resultadoTable->clearSpans();
  foreach(Partida partida, partidas){
    QList<QStandardItem*> columns;
    columns << new QStandardItem(std::to_string(partida.getCodigo()).c_str());
    columns << new QStandardItem(partida.getJogo().getNome().c_str());
    columns << new QStandardItem(partida.getData().toString("yyyy-MM-dd hh:mm"));
    columns << new QStandardItem(std::to_string(partida.getPreco()).c_str());
    columns << new QStandardItem(std::to_string(partida.getDisponibilidade()).c_str());
    model->appendRow(columns);
  }
}

void SearchJogoWindow::setupTable(){
  model->setHorizontalHeaderItem(0, new QStandardItem("Código"));
  model->setHorizontalHeaderItem(1, new QStandardItem("Jogo"));
  model->setHorizontalHeaderItem(2, new QStandardItem("Data"));
  model->setHorizontalHeaderItem(3, new QStandardItem("Preço"));
  model->setHorizontalHeaderItem(4, new QStandardItem("Disponibilidade"));
  model->setHorizontalHeaderItem(5, new QStandardItem("Ação"));
}
