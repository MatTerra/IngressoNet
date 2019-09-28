CONFIG += testcase
TARGET = testepartidadao
QT = core testlib
SOURCES +=  \
    testepartidadao.cpp \
    ../../src/partidadao.cpp \
    ../../src/mysqlhelper.cpp \
    ../../src/cidade.cpp
LIBS += -lmariadb
INCLUDEPATH += ../../src

