#include <QObject>
#include <QtTest>

#include <jogodao.h>
#include <jogo.h>

class TesteJogoDAO : public QObject{
  Q_OBJECT

private slots:
  void initTestCase();
  void test_case1();

};

void TesteJogoDAO::initTestCase(){
  QSKIP("Not implemented yet!");
}

void TesteJogoDAO::test_case1()
{

}

QTEST_APPLESS_MAIN(TesteJogoDAO)

#include "testejogodao.moc"
