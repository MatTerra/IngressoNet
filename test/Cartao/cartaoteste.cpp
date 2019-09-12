#include <QObject>
#include <QtTest/QtTest>
#include "../../src/cartao.h"


class CartaoTeste : public QObject{
  Q_OBJECT
private slots:
    void validarNumero();
    void validarNumero_data();
};

QTEST_MAIN(CartaoTeste)
#include "cartaoteste.moc"


void CartaoTeste::validarNumero(){
  QFETCH(long, number);
  QFETCH(bool, result);
  QCOMPARE(Cartao::isValidNumber(number),result);
}

void CartaoTeste::validarNumero_data(){
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
