#include <QObject>
#include <QTest>
#include <cartao.h>


class TesteCartao : public QObject{

Q_OBJECT

private slots:
  void validarNumeroCartao();
  void validarNumeroCartao_data();
  void testCompararCartoes();
  void testCompararCartoes_data();
};

QTEST_APPLESS_MAIN(TesteCartao)

#include "testecartao.moc"

void TesteCartao::validarNumeroCartao(){
  QFETCH(long, number);
  QFETCH(bool, result);
  QCOMPARE(Cartao::isValidNumber(static_cast<unsigned long>(number)),result);
}

void TesteCartao::validarNumeroCartao_data(){
  QTest::addColumn<long>("number");
  QTest::addColumn<bool>("result");
  QTest::newRow("number too short") << 1234567891234 << false;
  QTest::newRow("Valid 14 digit number(Dinners)") << 36490102462661 << true;
  QTest::newRow("Valid 15 digit number(AMEX)") << 376449047333005 << true;
  QTest::newRow("Valid 16 digit number") << 5555666677778884 << true;
  QTest::newRow("Invalid 14 digit number(Dinners)") << 36490102462662 << false;
  QTest::newRow("Invalid 15 digit number(AMEX)") << 376449047333006 << false;
  QTest::newRow("Invalid 16 digit number") << 5555666677778885 << false;

}

void TesteCartao::testCompararCartoes(){
  QFETCH(long, number);
  QFETCH(int, numSec);
  QFETCH(long, number2);
  QFETCH(int, numSec2);
  QFETCH(bool, result);
  QCOMPARE(Cartao::compararCartoes(Cartao(number, numSec), Cartao(number2, numSec2)),result);
}

void TesteCartao::testCompararCartoes_data(){
  QTest::addColumn<long>("number");
  QTest::addColumn<int>("numSec");
  QTest::addColumn<long>("number2");
  QTest::addColumn<int>("numSec2");
  QTest::addColumn<bool>("result");
  QTest::newRow("Equal Cards") << 36490102462661 << 1234 << 36490102462661 << 1234 << true;
  QTest::newRow("Different Numbers") << 36490102462661 << 1234 << 36490102462662 << 1234 << false;
  QTest::newRow("Different Security Numbers") << 36490102462661 << 1234 << 36490102462661 << 1233 << false;
}
