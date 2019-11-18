#include <QObject>
#include <QtTest>

#include <cidadedao.h>
#include <cidade.h>

class TesteCidadeDAO : public QObject{
  Q_OBJECT

private slots:
  void initTestCase();
  void testeGetCidade();
  void testeGetCidadeByProperty();
  void testeSaveCidade();
  void testeUpdateCidade();
  void testeRemoveCidade();
};

void TesteCidadeDAO::initTestCase(){
  MYSQL* dbconn = mysql_init(nullptr);
  dbconn = mysql_real_connect(dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
  if (!dbconn) {
    QSKIP("No database running");
  }
  mysql_close(dbconn);
}

void TesteCidadeDAO::testeGetCidade(){
  CidadeDAO* cdao = CidadeDAO::getInstance();
  Cidade c = cdao->get("1");
  QCOMPARE(c.getNome(), "Brasilia");
}

void TesteCidadeDAO::testeGetCidadeByProperty(){
  CidadeDAO* cdao = CidadeDAO::getInstance();
  Cidade c = cdao->getByProperty("nomeCidade", "Brasilia")[0];
  QCOMPARE(c.getId(), 1);
}

void TesteCidadeDAO::testeSaveCidade(){
  CidadeDAO* cdao = CidadeDAO::getInstance();
  Estado e(13, "MG");
  Cidade c(-1, "Patos", e);
  cdao->save(c);
  c.setId(cdao->getByProperty("nomeCidade", "Patos")[0].getId());
  QCOMPARE(c.getId() != -1, true);
}

void TesteCidadeDAO::testeUpdateCidade(){
  CidadeDAO* cdao = CidadeDAO::getInstance();
  Cidade c = cdao->getByProperty("nomeCidade", "Patos")[0];
  cdao->update(c, "nomeCidade", "Ventania");
  c = cdao->getByProperty("nomeCidade", "Ventania")[0];
  cdao->update(c, "idEstado", "7");
  c = cdao->get(std::to_string(c.getId()));
  QCOMPARE((c.getNome().compare("Ventania")==0 && c.getEstado().getId()==7),true);
}

void TesteCidadeDAO::testeRemoveCidade(){
  CidadeDAO* cdao = CidadeDAO::getInstance();
  Cidade c = cdao->getByProperty("nomeCidade", "Ventania")[0];
  cdao->remove(c);
  QCOMPARE(cdao->get(std::to_string(c.getId())).getId(), -1);
}

QTEST_APPLESS_MAIN(TesteCidadeDAO)

#include "testecidadedao.moc"
