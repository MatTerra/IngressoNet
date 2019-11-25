#include "searchjogowindow.h"
#include "ui_searchjogowindow.h"

#define BUY_COLUMN 8

SearchJogoWindow::SearchJogoWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SearchJogoWindow){
  ui->setupUi(this);

  session = Session::getInstance();
  processor = new SearchProcessor();

  connectSignals();
  setupLayout();
  setupTable();
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
    QList<QStandardItem*> row = createRow(partida);
    model->appendRow(row);
  }
  ui->resultadoTable->resizeColumnsToContents();
}

void SearchJogoWindow::setupTable(){
  model->setHorizontalHeaderItem(0, new QStandardItem("Código"));
  model->setHorizontalHeaderItem(1, new QStandardItem("Jogo"));
  model->setHorizontalHeaderItem(2, new QStandardItem("Data"));
  model->setHorizontalHeaderItem(3, new QStandardItem("Hora"));
  model->setHorizontalHeaderItem(4, new QStandardItem("Cidade"));
  model->setHorizontalHeaderItem(5, new QStandardItem("Estado"));
  model->setHorizontalHeaderItem(6, new QStandardItem("Preço"));
  model->setHorizontalHeaderItem(7, new QStandardItem("Ingressos"));
  model->setHorizontalHeaderItem(BUY_COLUMN, new QStandardItem("Ação"));
}

void SearchJogoWindow::on_resultadoTable_clicked(const QModelIndex &index){
  if(index.column()!=BUY_COLUMN){
    qDebug("Nada a fazer");
    return;
  }
  ComprarItem* ci = static_cast<ComprarItem*>(model->item(index.row(), BUY_COLUMN));
  if(ci->text()=="Comprar"){
      emit requestCompraIngresso(ci->getPartida());
  }
}

void SearchJogoWindow::proccedToCompraIngresso(Partida& partida){
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new ComprarIngressoWindow(partida, mw));
  this->destroy();
}

void SearchJogoWindow::connectSignals(){
  connect(this, SIGNAL(requestSearchResults(QDateTime, QString, QString)), processor, SLOT(searchGame(QDateTime, QString, QString)));
  connect(processor, SIGNAL(gameResultsReady(QVector<Partida>)), this, SLOT(displayGameResults(QVector<Partida>)));
  connect(this,SIGNAL(requestCompraIngresso(Partida&)), this, SLOT(proccedToCompraIngresso(Partida&)));
}

void SearchJogoWindow::setupLayout(){
  model = new QStandardItemModel();
  ui->estadoBox->setView(new QListView());
  ui->cidadeBox->setView(new QListView());
  ui->resultadoTable->setModel(model);
  ui->resultadoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui->incioDateTime->setDateTime(QDateTime::currentDateTime());
}

QList<QStandardItem*> SearchJogoWindow::createRow(Partida& partida){
  QList<QStandardItem*> columns;
  if(partida.getCodigo() == -1){
      return columns;
  }
  columns << new QStandardItem(std::to_string(partida.getCodigo()).c_str());
  columns << new QStandardItem(partida.getJogo().getNome().c_str());
  columns << new QStandardItem(partida.getData().toString("dd/MM/yyyy"));
  columns << new QStandardItem(partida.getData().toString("hh:mm"));
  columns << new QStandardItem(partida.getCidade().getNome().c_str());
  columns << new QStandardItem(partida.getCidade().getEstado().getSigla().c_str());
  columns << new QStandardItem(std::to_string(partida.getPreco()).c_str());
  columns << new QStandardItem(std::to_string(partida.getDisponibilidade()).c_str());

  if(partida.getDisponibilidade()>0){
      ComprarItem* acao = new ComprarItem(partida, "Comprar");
      columns << acao;
  } else {
    columns << new QStandardItem("Indisponível");
  }
  foreach(QStandardItem* item, columns){
      item->setEditable(false);
  }
  return columns;
}
