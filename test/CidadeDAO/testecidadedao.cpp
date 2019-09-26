#include <QObject>
#include <QtTest>

#include <cidadedao.h>
#include <cidade.h>

class TesteCidadeDAO : public QObject{
  Q_OBJECT

private slots:
  void initTestCase();
  void test_case1();

};

void TesteCidadeDAO::initTestCase(){
  QSKIP("Não implementado");
}

void TesteCidadeDAO::test_case1()
{

}

QTEST_APPLESS_MAIN(TesteCidadeDAO)

#include "testecidadedao.moc"
