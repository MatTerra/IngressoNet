CONFIG += testcase
TARGET = testeestadodao
QT = core testlib
SOURCES +=  \
    testeestadodao.cpp \
    ../../src/estadodao.cpp \
    ../../src/estado.cpp \
    ../../src/mysqlhelper.cpp
LIBS += -lmariadb
INCLUDEPATH += ../../src
