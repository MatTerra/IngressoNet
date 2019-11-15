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
  Usuario user(cpf.toStdString(), senha.toStdString());
  qDebug("%s\t%s", cpf.toStdString().c_str(), senha.toStdString().c_str());
  Usuario userDB = udao->get(cpf.toStdString());
  qDebug("%s\t%s", userDB.getCPF().c_str(), userDB.getSenha().c_str());
  QCOMPARE(Usuario::compararUsuarios(userDB, user), true);

}


void TesteUsuarioDAO::testeGetUser_data(){
  QTest::addColumn<QString>("cpf");
  QTest::addColumn<QString>("senha");
  QTest::newRow("testUser") << "326.688.371-38" << "1234";
}

void TesteUsuarioDAO::testeSaveUser(){
  Usuario u("081.556.680-88", "1234");
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  udao->save(u);
  QCOMPARE(Usuario::compararUsuarios(udao->get(u.getCPF()), u), true);
}

void TesteUsuarioDAO::testeUpdateUser(){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Usuario u("081.556.680-88", "1234");
  std::string novaSenha = "123456";
  udao->update(u, "senha", novaSenha);
  Usuario a = udao->get(u.getCPF());
  QCOMPARE(a.getSenha(), novaSenha);
}

void TesteUsuarioDAO::testeRemoveUser(){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Usuario u("081.556.680-88", "1234");
  udao->remove(u);
  QCOMPARE(udao->get(u.getCPF()).getCPF().c_str(), "000.000.000-00");
}


