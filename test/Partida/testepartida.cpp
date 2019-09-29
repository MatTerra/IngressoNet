#include <QtTest>

#include <partida.h>

class TestePartida : public QObject{
  Q_OBJECT

private slots:
  void initTestCase();
  void testeVenderIngresso();

};

void TestePartida::initTestCase(){
  QSKIP("Not implemented yet");
}

void TestePartida::testeVenderIngresso(){

}

QTEST_APPLESS_MAIN(TestePartida)

#include "testepartida.moc"
