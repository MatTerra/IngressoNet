CONFIG += testcase
TARGET = testeingressodao
QT = core testlib
SOURCES +=  \
    testeingressodao.cpp \
    ../../src/ingressodao.cpp \
    ../../src/ingresso.cpp \
    ../../src/mysqlhelper.cpp \
    ../../src/usuariodao.cpp \
    ../../src/partidadao.cpp \
    ../../src/cidade.cpp \
    ../../src/estado.cpp \
    ../../src/usuario.cpp \
    ../../src/partida.cpp \
    ../../src/cartao.cpp
LIBS += -lmariadb
INCLUDEPATH += ../../src

