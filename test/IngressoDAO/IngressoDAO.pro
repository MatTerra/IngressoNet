CONFIG += testcase
TARGET = testecidadedao
QT = core testlib
SOURCES +=  \
    testeingressodao.cpp \
    ../../src/ingressodao.cpp \
    ../../src/ingresso.cpp \
    ../../src/mysqlhelper.cpp
LIBS += -lmariadb
INCLUDEPATH += ../../src

