#include <QObject>
#include <QtTest>

#include <jogodao.h>
#include <jogo.h>

class TesteJogoDAO : public QObject{
  Q_OBJECT

private slots:
  void initTestCase();
  void testeGetJogo();

};

void TesteJogoDAO::initTestCase(){
  MYSQL* dbconn = mysql_init(nullptr);
  dbconn = mysql_real_connect(dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
  if (!dbconn) {
    QSKIP("No database running");
  }
  mysql_close(dbconn);
}

void TesteJogoDAO::testeGetJogo(){
  JogoDAO* jdao = JogoDAO::getInstance();
  Jogo jdb = jdao->get("0");
  Jogo j(0, "FlaFlu", Jogo::Nacional);
  QCOMPARE((jdb.getNome().compare(j.getNome()) == 0 && jdb.getTipo() == j.getTipo()), true);
}

QTEST_APPLESS_MAIN(TesteJogoDAO)

#include "testejogodao.moc"
