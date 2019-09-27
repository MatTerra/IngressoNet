#include <QtTest>

#include <partida.h>s

class TestePartida : public QObject
{
  Q_OBJECT

public:
  TestePartida();
  ~TestePartida();

private slots:
  void testVenderIngresso();

};

void TestePartida::testeVenderIngresso()
{

}

QTEST_APPLESS_MAIN(TestePartida)

#include "testepartida.moc"
