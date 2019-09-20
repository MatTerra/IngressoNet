#include <QObject>
#include <QtTest/QtTest>
#include "../src/cartao.h"

class TestesUnitarios : public QObject{
  Q_OBJECT
private slots:
    void validarNumeroCartao();
    void validarNumeroCartao_data();
};

QTEST_MAIN(TestesUnitarios)
#include "testesunitarios.moc"


void TestesUnitarios::validarNumeroCartao(){
  QFETCH(long, number);
  QFETCH(bool, result);
  QCOMPARE(Cartao::isValidNumber(static_cast<unsigned long>(number)),result);
}

void TestesUnitarios::validarNumeroCartao_data(){
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
