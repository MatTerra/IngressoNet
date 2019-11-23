#include <QObject>
#include <QtTest>

#include <mysql/mysql.h>
#include <mysqlhelper.h>
#include <ingressodao.h>
#include <ingresso.h>

class TesteIngressoDAO : public QObject{
  Q_OBJECT

private slots:
  void initTestCase();
  void testGetIngresso();
};

void TesteIngressoDAO::initTestCase(){
  MYSQL* dbconn = mysql_init(nullptr);
  dbconn = mysql_real_connect(dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
  if (!dbconn) {
    QSKIP("No database running");
  }
  mysql_close(dbconn);
}

void TesteIngressoDAO::testGetIngresso(){
  IngressoDAO* idao = IngressoDAO::getInstance();
  Ingresso i = idao->get("0");
  qDebug("%s", i.getUsuario().getCPF().c_str());
  QCOMPARE(( Usuario::compararUsuarios(i.getUsuario(), Usuario("052.327.931-01","")) && i.getCodigo()==0 && i.getPartida().getCodigo()==1), true);
}


QTEST_APPLESS_MAIN(TesteIngressoDAO)

#include "testeingressodao.moc"
