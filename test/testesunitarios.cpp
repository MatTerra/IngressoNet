#include <QObject>
#include <QtTest/QtTest>
#include "../src/cartao.h"
#include "../src/usuario.h"
#include "../src/cidade.h"

class TestesUnitarios : public QObject{
  Q_OBJECT
private slots:
    void validarNumeroCartao();
    void validarNumeroCartao_data();
    void validarNumeroCPF();
    void validarNumeroCPF_data();
    void nameAccessCidade();
    void nameEditCidade();
    void estadoAccessCidade();
    void estadoEditCidade();
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

void TestesUnitarios::validarNumeroCPF(){
  QFETCH(QString, cpf);
  QFETCH(bool, result);
  QCOMPARE(Usuario::isValidCPF(cpf.toStdString()), result);
}

void TestesUnitarios::validarNumeroCPF_data(){
  QTest::addColumn<QString>("cpf");
  QTest::addColumn<bool>("result");
  QTest::newRow("Valid CPF") << "326.688.371-38" << true;
  QTest::newRow("Invalid CPF; last digit wrong") << "326.688.371-39" << false;
  QTest::newRow("Invalid CPF; 10th digit wrong") << "326.688.371-48" << false;
}

void TestesUnitarios::nameAccessCidade(){
  Cidade cidade("Brasília", "DF");
  QCOMPARE(cidade.getNome(), "Brasília");
}

void TestesUnitarios::nameEditCidade(){
  Cidade cidade("Brasília", "DF");
  cidade.setNome("Patos");
  QCOMPARE(cidade.getNome(), "Patos");
}

void TestesUnitarios::estadoAccessCidade(){
  Cidade cidade("Brasília", "DF");
  QCOMPARE(cidade.getEstado(), "DF");
}

void TestesUnitarios::estadoEditCidade(){
  Cidade cidade("Brasília", "DF");
  cidade.setEstado("MG");
  QCOMPARE(cidade.getEstado(), "MG");
}

