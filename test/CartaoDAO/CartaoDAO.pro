CONFIG += testcase
TARGET = testecartaodao
QT = core testlib
SOURCES +=  \
    testecartaodao.cpp \
    ../../src/cartao.cpp \
    ../../src/cartaodao.cpp \
    ../../src/mysqlhelper.cpp
LIBS +=-lmariadb
INCLUDEPATH += ../../src
