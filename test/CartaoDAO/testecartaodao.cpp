#include <QObject>
#include <QtTest>

#include <cartao.h>
#include <cartaodao.h>

class TesteCartaoDAO : public QObject
{
  Q_OBJECT

private slots:
  void initTestCase();
  void cleanupTestCase();
  void test_case1();

};

void TesteCartaoDAO::initTestCase()
{
  QSKIP("Não implementado ainda");
}

void TesteCartaoDAO::cleanupTestCase()
{

}

void TesteCartaoDAO::test_case1()
{

}

QTEST_APPLESS_MAIN(TesteCartaoDAO)

#include "testecartaodao.moc"
