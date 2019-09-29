CONFIG += testcase
TARGET = testejogodao
QT = core testlib
SOURCES +=  \
    testejogodao.cpp \
    ../../src/jogodao.cpp \
    ../../src/jogo.cpp \
    ../../src/mysqlhelper.cpp
LIBS += -lmariadb
INCLUDEPATH += ../../src
