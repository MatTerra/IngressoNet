#include <QObject>
#include <QTest>
#include <cidade.h>


class TesteCidade : public QObject{

Q_OBJECT

private slots:
    void nameAccessCidade();
    void nameEditCidade();
    void estadoAccessCidade();
    void estadoEditCidade();
};

QTEST_APPLESS_MAIN(TesteCidade)

#include "testecidade.moc"

void TesteCidade::nameAccessCidade(){
  Cidade cidade("Brasília", "DF");
  QCOMPARE(cidade.getNome(), "Brasília");
}

void TesteCidade::nameEditCidade(){
  Cidade cidade("Brasília", "DF");
  cidade.setNome("Patos");
  QCOMPARE(cidade.getNome(), "Patos");
}

void TesteCidade::estadoAccessCidade(){
  Cidade cidade("Brasília", "DF");
  QCOMPARE(cidade.getEstado(), "DF");
}

void TesteCidade::estadoEditCidade(){
  Cidade cidade("Brasília", "DF");
  cidade.setEstado("MG");
  QCOMPARE(cidade.getEstado(), "MG");
}

