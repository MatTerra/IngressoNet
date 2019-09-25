#include <QObject>
#include <QTest>

#include <usuariodao.h>
#include <usuario.h>
#include <cartao.h>

class TesteUsuarioDAO : public QObject{

Q_OBJECT

private:
  bool compararUsuarios(Usuario, Usuario);
  bool compararCartoes(Cartao, Cartao);

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
}

bool TesteUsuarioDAO::compararUsuarios(Usuario a, Usuario b){
  if(a.getCPF().compare(b.getCPF()) != 0){
      return false;
  }
  if(a.getSenha().compare(b.getSenha()) != 0){
      return false;
  }
  return this->compararCartoes(a.getCartao(), b.getCartao());
}

bool TesteUsuarioDAO::compararCartoes(Cartao a, Cartao b){
  if(a.getNumero() != b.getNumero()){
      return false;
  }
  if(a.getNumSeguranca() != b.getNumSeguranca()){
      return false;
  }
  return true;
}

void TesteUsuarioDAO::testeGetUser(){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  QFETCH(QString, cpf);
  QFETCH(QString, senha);
  QFETCH(long, numeroCartao);
  QFETCH(int, codigoSeguranca);
  Cartao c(static_cast<unsigned long>(numeroCartao), static_cast<unsigned int>(codigoSeguranca));
  Usuario user(cpf.toStdString(), senha.toStdString(), c);
  QCOMPARE(compararUsuarios(udao->get(cpf.toStdString()), user), true);

}


void TesteUsuarioDAO::testeGetUser_data(){
  QTest::addColumn<QString>("cpf");
  QTest::addColumn<QString>("senha");
  QTest::addColumn<long>("numeroCartao");
  QTest::addColumn<int>("codigoSeguranca");
  QTest::newRow("testUser") << "326.688.371-38" << "1234" << 5555666677778884 << 1234;
}

void TesteUsuarioDAO::testeSaveUser(){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Cartao c(36490102462661, 1234);
  Usuario u("081.556.680-88", "1234", c);
  udao->save(u);
  QCOMPARE(compararUsuarios(udao->get(u.getCPF()), u), true);
}

void TesteUsuarioDAO::testeUpdateUser(){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Cartao c(36490102462661, 1234);
  Usuario u("081.556.680-88", "1234", c);
  std::string params[] = {"senha", "123456"};
  udao->update(u, params);
  Usuario a = udao->get(u.getCPF());
  QCOMPARE(a.getSenha().compare(params[1]), 0);
  params[1]="1234";
  udao->update(u, params);
}

void TesteUsuarioDAO::testeRemoveUser(){
  UsuarioDAO* udao = UsuarioDAO::getInstance();
  Cartao c(36490102462661, 1234);
  Usuario u("081.556.680-88", "1234", c);
  udao->remove(u);
  QCOMPARE(udao->get(u.getCPF()).getCPF().c_str(), "000.000.000-00");
}


