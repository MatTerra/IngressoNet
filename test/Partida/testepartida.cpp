#include <QtTest>

#include <partida.h>

class TestePartida : public QObject
{
  Q_OBJECT

public:
  TestePartida();
  ~TestePartida();

private slots:
  void testeVenderIngresso();

};

void TestePartida::testeVenderIngresso()
{

}

QTEST_APPLESS_MAIN(TestePartida)

#include "testepartida.moc"
