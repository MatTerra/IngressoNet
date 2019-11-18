CONFIG += testcase
TARGET = testecidadedao
QT = core testlib
SOURCES +=  \
    testecidadedao.cpp \
    ../../src/cidadedao.cpp \
    ../../src/cidade.cpp \
    ../../src/mysqlhelper.cpp \
    ../../src/estado.cpp
LIBS += -lmariadb
INCLUDEPATH += ../../src
