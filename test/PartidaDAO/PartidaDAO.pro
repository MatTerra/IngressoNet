CONFIG += testcase
TARGET = testepartidadao
QT = core testlib
SOURCES +=  \
    testepartidadao.cpp \
    ../../src/partidadao.cpp \
    ../../src/mysqlhelper.cpp \
    ../../src/cidade.cpp \
    ../../src/estado.cpp \
    ../../src/usuario.cpp \
    ../../src/partida.cpp \
    ../../src/cartao.cpp
LIBS += -lmariadb
INCLUDEPATH += ../../src

