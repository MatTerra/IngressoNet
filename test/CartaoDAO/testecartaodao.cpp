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
  Cartao c(5555666677778884, 1234, "326.688.371-38");
  QCOMPARE(Cartao::compararCartoes(cdao->get(c.getCPF()), c), true);
}

void TesteCartaoDAO::testeGetCartaoByProperty(){
  Cartao card(376449047333005, 123);
  CartaoDAO* cdao = CartaoDAO::getInstance();
  Cartao c = cdao->getByProperty("numero", std::to_string(card.getNumero()).c_str())[0];
  QCOMPARE(Cartao::compararCartoes(card, cdao->get(c.getCPF())), true);
}

void TesteCartaoDAO::testeSaveCartao(){
  Cartao c(36490102462661, 1234, "000.000.000-01");
  CartaoDAO* cdao = CartaoDAO::getInstance();
  cdao->save(c);
  QCOMPARE(Cartao::compararCartoes(cdao->get(c.getCPF()), c), true);
}

void TesteCartaoDAO::testeUpdateCartao(){
  Cartao c(36490102462661, 1234, "000.000.000-01");
  CartaoDAO* cdao = CartaoDAO::getInstance();
  cdao->update(c, "cpf", "000.000.000-00");
  Cartao updated = cdao->getByProperty("cpf", "000.000.000-00")[0];
  QCOMPARE(Cartao::compararCartoes(cdao->get(updated.getCPF()), c), true);
}

void TesteCartaoDAO::testeRemoveCartao(){
  Cartao c(36490102462661, 1234, "000.000.000-00");
  CartaoDAO* cdao = CartaoDAO::getInstance();
  cdao->remove(c);
  QCOMPARE(cdao->get(std::to_string(c.getNumero())).getNumero(), 0);
}

void TesteCartaoDAO::cleanupTestCase(){

}



QTEST_APPLESS_MAIN(TesteCartaoDAO)

#include "testecartaodao.moc"
