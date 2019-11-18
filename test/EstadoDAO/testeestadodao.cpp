#include <QObject>
#include <QtTest>

#include <estadodao.h>
#include <estado.h>

class TesteEstadoDAO : public QObject{
  Q_OBJECT

private slots:
  void initTestCase();
  void testeGetEstado();
  void testeGetEstadoByProperty();
  void testeSaveEstado();
  void testeUpdateEstado();
  void testeRemoveEstado();
};

void TesteEstadoDAO::initTestCase(){
  MYSQL* dbconn = mysql_init(nullptr);
  dbconn = mysql_real_connect(dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
  if (!dbconn) {
    QSKIP("No database running");
  }
  mysql_close(dbconn);
}

void TesteEstadoDAO::testeGetEstado(){
  EstadoDAO* edao = EstadoDAO::getInstance();
  Estado e = edao->get("1");
  QCOMPARE(e.getSigla(), "AC");
}

void TesteEstadoDAO::testeGetEstadoByProperty(){
  EstadoDAO* edao = EstadoDAO::getInstance();
  Estado e = edao->getByProperty("siglaEstado", "AC")[0];
  QCOMPARE(e.getId(), 1);
}

void TesteEstadoDAO::testeSaveEstado(){
  EstadoDAO* edao = EstadoDAO::getInstance();
  Estado e(28, "MY");
  edao->save(e);
  QCOMPARE(edao->getByProperty("siglaEstado", "MY")[0].getSigla(), e.getSigla());
}

void TesteEstadoDAO::testeUpdateEstado(){
  EstadoDAO* edao = EstadoDAO::getInstance();
  Estado e = edao->getByProperty("siglaEstado","MY")[0];
  edao->update(e, "siglaEstado", "YR");
  e.setSigla("YR");
  QCOMPARE(e.getSigla(), edao->get(std::to_string(e.getId())).getSigla());
}

void TesteEstadoDAO::testeRemoveEstado(){
  EstadoDAO* edao = EstadoDAO::getInstance();
  Estado e = edao->getByProperty("siglaEstado","YR")[0];
  edao->remove(e);
  QCOMPARE(edao->get(std::to_string(e.getId())).getId(),-1);
}

QTEST_APPLESS_MAIN(TesteEstadoDAO)

#include "testeestadodao.moc"
