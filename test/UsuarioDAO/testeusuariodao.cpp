#include <QObject>
#include <QTest>

#include <usuariodao.h>
#include <usuario.h>
#include <cartao.h>

class TesteUsuarioDAO : public QObject{

Q_OBJECT

private:

private slots:
  void initTestCase();
  void testeGetUser();
  void testeGetUser_data();
  void testeSaveUser();
  void testeUpdateUser();
  void testeRemoveUser();
};

QTEST_APPLESS_MAIN(TesteUsuarioDAO)

#include "testeusuariodao.moc"


void TesteUsuarioDAO::initTestCase(){
  MYSQL* dbconn = mysql_init(nullptr);
  dbconn = mysql_real_connect(dbconn, IP, USER, PASSWORD, DB, 0, nullptr, 0);
  if (!dbconn) {
    QSKIP("No database running");
  }
  mysql_close(dbconn);
}

void TesteUsuarioDAO::testeGetUser(){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  QFETCH(QString, cpf);
  QFETCH(QString, senha);
  QFETCH(long, numeroCartao);
  QFETCH(int, codigoSeguranca);
  Cartao c(static_cast<unsigned long>(numeroCartao), static_cast<unsigned int>(codigoSeguranca));
  Usuario user(cpf.toStdString(), senha.toStdString(), c);
  QCOMPARE(Usuario::compararUsuarios(udao->get(cpf.toStdString()), user), true);

}


void TesteUsuarioDAO::testeGetUser_data(){
  QTest::addColumn<QString>("cpf");
  QTest::addColumn<QString>("senha");
  QTest::addColumn<long>("numeroCartao");
  QTest::addColumn<int>("codigoSeguranca");
  QTest::newRow("testUser") << "326.688.371-38" << "1234" << 5555666677778884 << 1234;
}

void TesteUsuarioDAO::testeSaveUser(){
  Cartao c(36490102462661, 1234);
  Usuario u("081.556.680-88", "1234", c);
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  udao->save(u);
  QCOMPARE(Usuario::compararUsuarios(udao->get(u.getCPF()), u), true);
}

void TesteUsuarioDAO::testeUpdateUser(){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Cartao c(36490102462661, 1234);
  Usuario u("081.556.680-88", "1234", c);
  udao->update(u, "senha", "123456");
  Usuario a = udao->get(u.getCPF());
  QCOMPARE(a.getSenha(), "123456");
}

void TesteUsuarioDAO::testeRemoveUser(){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Cartao c(36490102462661, 1234);
  Usuario u("081.556.680-88", "1234", c);
  udao->remove(u);
  QCOMPARE(udao->get(u.getCPF()).getCPF().c_str(), "000.000.000-00");
}


