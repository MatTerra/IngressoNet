#include <QObject>
#include <QtTest>

// add necessary includes here

class TesteIngressoDAO : public QObject{
  Q_OBJECT

private slots:
  void initTestCase();
  void test_case1();

};

void TesteIngressoDAO::initTestCase(){
  QSKIP("Not implemented yet!");
}

void TesteIngressoDAO::test_case1()
{

}

QTEST_APPLESS_MAIN(TesteIngressoDAO)

#include "testeingressodao.moc"
