CONFIG += testcase
TARGET = testecidadedao
QT = core testlib
SOURCES +=  \
    testecidadedao.cpp \
    ../../src/cidadedao.cpp \
    ../../src/cidade.cpp \
    ../../src/mysqlhelper.cpp
LIBS += -lmariadb
INCLUDEPATH += ../../src
