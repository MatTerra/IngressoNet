CONFIG += testcase
TARGET = testecartaodao
QT = core testlib
SOURCES +=  \
    testecartaodao.cpp \
    ../../src/cartao.cpp \
    ../../src/cartaodao.cpp \
    ../../src/mysqlhelper.cpp \
    ../../src/usuariodao.cpp \
    ../../src/usuario.cpp
LIBS +=-lmariadb
INCLUDEPATH += ../../src
