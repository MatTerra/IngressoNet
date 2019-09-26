CONFIG += testcase
TARGET = testeusuariodao
QT = core testlib
SOURCES +=  \
    testeusuariodao.cpp \
    ../../src/usuariodao.cpp \
    ../../src/usuario.cpp \
    ../../src/cartao.cpp \
    ../../src/mysqlhelper.cpp
LIBS +=-lmariadb
INCLUDEPATH += ../../src
