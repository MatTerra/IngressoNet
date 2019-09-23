#include <QObject>
#include <QTest>
#include <cartao.h>
#include <usuario.h>


class TesteUsuario : public QObject{

Q_OBJECT

private slots:
  void limparNumeroCPF();
  void limparNumeroCPF_data();
  void validarNumeroCPF();
  void validarNumeroCPF_data();
};

QTEST_APPLESS_MAIN(TesteUsuario)

#include "testeusuario.moc"

void TesteUsuario::validarNumeroCPF(){
  QFETCH(QString, cpf);
  QFETCH(bool, result);
  QCOMPARE(Usuario::isValidCPF(cpf.toStdString()), result);
}

void TesteUsuario::validarNumeroCPF_data(){
  QTest::addColumn<QString>("cpf");
  QTest::addColumn<bool>("result");
  QTest::newRow("Valid CPF") << "326.688.371-38" << true;
  QTest::newRow("Invalid CPF; last digit wrong") << "326.688.371-39" << false;
  QTest::newRow("Invalid CPF; 10th digit wrong") << "326.688.371-48" << false;
}

void TesteUsuario::limparNumeroCPF(){
  QFETCH(QString, cpf);
  QFETCH(QString, result);
  QCOMPARE(Usuario::getCPFNumbers(cpf.toStdString()), result.toStdString());
}

void TesteUsuario::limparNumeroCPF_data(){
  QTest::addColumn<QString>("cpf");
  QTest::addColumn<QString>("result");
  QTest::newRow("Valid CPF") << "326.688.371-38" << "32668837138";
}
