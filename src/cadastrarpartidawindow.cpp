#include "cadastrarpartidawindow.h"
#include "ui_cadastrarpartidawindow.h"

CadastrarPartidaWindow::CadastrarPartidaWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::CadastrarPartidaWindow){
  ui->setupUi(this);
  session=Session::getInstance();
  processor = new CadastrarPartidaProcessor();
  ui->estadoBox->setView(new QListView());
  ui->cidadeBox->setView(new QListView());
  ui->tipoBox->setView(new QListView());
  ui->dataEdit->setDateTime(QDateTime::currentDateTime());
  ui->tipoBox->addItem("Local");
  ui->tipoBox->addItem("Estadual");
  ui->tipoBox->addItem("Nacional");
  ui->tipoBox->addItem("Internacional");
  fillEstados();
  connect(this, SIGNAL(requestCadastroPartida(Partida&)), processor, SLOT(cadastroPartidaRequested(Partida&)));
  connect(processor, SIGNAL(createError(QString)), this, SLOT(onCreateError(QString)));
  connect(processor, SIGNAL(cadastroPartidaDone()), this, SLOT(onCadastroPartidaDone()));
}

CadastrarPartidaWindow::~CadastrarPartidaWindow(){
  delete ui;
}

void CadastrarPartidaWindow::fillEstados(){
  EstadoDAO* edao = EstadoDAO::getInstance();
  std::vector<Estado> estados = edao->getAll();
  foreach (Estado estado, estados) {
    ui->estadoBox->addItem(estado.getSigla().c_str());
  }
}

void CadastrarPartidaWindow::fillCidade(int idEstado){
  ui->cidadeBox->clear();
  CidadeDAO* cdao = CidadeDAO::getInstance();
  std::vector<Cidade> cidades = cdao->getByProperty("idEstado", std::to_string(idEstado));
  foreach (Cidade cidade, cidades) {
    Cidade c = cidade;
    ui->cidadeBox->addItem(cidade.getNome().c_str());
  }
}

void CadastrarPartidaWindow::on_VoltarBtn_clicked(){
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new DashboardWindow(mw));
  this->destroy();
}

void CadastrarPartidaWindow::on_cancelBtn_clicked(){
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Confirmação", "Sua partida não será cadastrada e você voltará para o Dashboard.",
                                QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Cancel);
  if (reply == QMessageBox::Ok) {
    QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
    mw->setCentralWidget(new DashboardWindow(mw));
    this->destroy();
  }
}

void CadastrarPartidaWindow::on_estadoBox_currentIndexChanged(const QString &){
    fillCidade(ui->estadoBox->currentIndex()+1);
}

void CadastrarPartidaWindow::on_cadastrarBtn_clicked(){
  if(ui->nomeJogoEdit->text().length()>5 && ui->dataEdit->dateTime() > QDateTime::currentDateTime()){
    Estado estado(ui->estadoBox->currentIndex()+1, ui->estadoBox->currentText().toStdString());
    std::vector<Cidade> cidades = CidadeDAO::getInstance()->getByProperty("idEstado", std::to_string(ui->estadoBox->currentIndex()+1));
    Cidade c(0,ui->cidadeBox->currentText().toStdString(), estado);
    foreach(Cidade cidade, cidades){
        if(cidade.getNome().compare(ui->cidadeBox->currentText().toStdString())==0){
            c.setId(cidade.getId());
          }
      }

    Jogo j(0, ui->nomeJogoEdit->text().toStdString(), Jogo::Tipo(ui->tipoBox->currentIndex()));
    Usuario resp = session->getUsuario();
    Partida p(0, c, ui->precoSpin->value(), ui->disponibilidadeSpin->value(), resp , ui->dataEdit->dateTime(), j);
    emit requestCadastroPartida(p);
  } else {
    QMessageBox::warning(this, "Erro no cadastro", "Confira os dados da partida");
  }
}

void CadastrarPartidaWindow::onCreateError(QString message){
  QMessageBox::warning(this, "Erro no Login", message);
}

void CadastrarPartidaWindow::onCadastroPartidaDone(){
  QMessageBox::warning(this, "Cadastro Realizado", "Partida cadastrada com sucesso!");
  QMainWindow* mw = dynamic_cast<QMainWindow *>(parent());
  mw->setCentralWidget(new DashboardWindow(mw));
  this->destroy();
}
