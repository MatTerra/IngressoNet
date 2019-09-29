#include <QObject>
#include <QtTest>

#include "partidadao.h"


class TestePartidaDAO : public QObject{
  Q_OBJECT

private slots:
  void initTestCase();
  void testePartida();

};

void TestePartidaDAO::initTestCase(){
  QSKIP("Not implemented yet");
}

void TestePartidaDAO::testePartida()
{

}

QTEST_APPLESS_MAIN(TestePartidaDAO)

#include "testepartidadao.moc"
