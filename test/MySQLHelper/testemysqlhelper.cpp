#include <QObject>
#include <QtTest>
#include <mysqlhelper.h>


class TesteMySQLHelper : public QObject{

Q_OBJECT

private slots:
  void initTestCase();
  void isSingletonSameObject();
  void isSingletonNotNull();

};

QTEST_APPLESS_MAIN(TesteMySQLHelper)

#include "testemysqlhelper.moc"

void TesteMySQLHelper::initTestCase(){
  MYSQL* dbconn = mysql_init(nullptr);
  dbconn = mysql_real_connect(dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
  if (!dbconn) {
    QSKIP("No database running");
  }
}

void TesteMySQLHelper::isSingletonSameObject(){
  MySQLHelper* a = MySQLHelper::getInstance();
  MySQLHelper* b = MySQLHelper::getInstance();
  QCOMPARE(a, b);
}

void TesteMySQLHelper::isSingletonNotNull(){
  MySQLHelper* a = MySQLHelper::getInstance();
  QVERIFY(a!=nullptr);
}

