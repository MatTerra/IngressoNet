#include <QObject>
#include <QTest>
#include <cidade.h>


class TesteCidade : public QObject{

Q_OBJECT

private slots:

};

QTEST_APPLESS_MAIN(TesteCidade)

#include "testecidade.moc"

