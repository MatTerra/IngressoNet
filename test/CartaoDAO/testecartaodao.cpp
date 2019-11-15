#include <QObject>
#include <QtTest>

#include <cartao.h>
#include <cartaodao.h>
#include <usuariodao.h>

class TesteCartaoDAO : public QObject
{
  Q_OBJECT


private slots:
  void initTestCase();
  void cleanupTestCase();
  void testeGetCartao();
  void testeGetCartao_data();
  void testeGetCartaoByProperty();
  void testeSaveCartao();
  void testeUpdateCartao();
  void testeRemoveCartao();

};

void TesteCartaoDAO::initTestCase(){
  MYSQL* dbconn = mysql_init(nullptr);
  dbconn = mysql_real_connect(dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
  if (!dbconn) {
    QSKIP("No database running");
  }
  mysql_close(dbconn);
}

void TesteCartaoDAO::testeGetCartao(){
  CartaoDAO* cdao = CartaoDAO::getInstance();
  QFETCH(long, numeroCartao);
  QFETCH(int, codigoSeguranca);
  Cartao c(static_cast<unsigned long>(numeroCartao), static_cast<unsigned int>(codigoSeguranca));
  QCOMPARE(Cartao::compararCartoes(cdao->get(std::to_string(static_cast<unsigned long>(numeroCartao))), c), true);
}

void TesteCartaoDAO::testeGetCartao_data(){
  QTest::addColumn<long>("numeroCartao");
  QTest::addColumn<int>("codigoSeguranca");
  QTest::newRow("testCard") << 5555666677778884 << 1234;
}

void TesteCartaoDAO::testeGetCartaoByProperty(){
  Cartao card(376449047333005, 123);
  CartaoDAO* cdao = CartaoDAO::getInstance();
  Cartao c = cdao->getByProperty("cpf", "932.613.760-07")[0];
  QCOMPARE(Cartao::compararCartoes(card, cdao->get(std::to_string(c.getNumero()))), true);
}

void TesteCartaoDAO::testeSaveCartao(){
  Cartao c(36490102462661, 1234);
  CartaoDAO* cdao = CartaoDAO::getInstance();
  cdao->save(c);
  QCOMPARE(Cartao::compararCartoes(cdao->get(std::to_string(c.getNumero())), c), true);
}

void TesteCartaoDAO::testeUpdateCartao(){
  Cartao c(36490102462661, 1234);
  CartaoDAO* cdao = CartaoDAO::getInstance();
  cdao->update(c, "cpf", "000.000.000-01");
  Cartao updated = cdao->getByProperty("cpf", "000.000.000-01")[0];
  QCOMPARE(Cartao::compararCartoes(cdao->get(std::to_string(updated.getNumero())), c), true);
}

void TesteCartaoDAO::testeRemoveCartao(){
  Cartao c(36490102462661, 1234);
  CartaoDAO* cdao = CartaoDAO::getInstance();
  cdao->remove(c);
  QCOMPARE(cdao->get(std::to_string(c.getNumero())).getNumero(), 0);
}

void TesteCartaoDAO::cleanupTestCase(){

}



QTEST_APPLESS_MAIN(TesteCartaoDAO)

#include "testecartaodao.moc"
