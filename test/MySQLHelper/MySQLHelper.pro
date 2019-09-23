QT += core testlib sql
CONFIG += qt console warn_on depend_includepath testcase
INCLUDEPATH += ../../src
SOURCES +=  \
    testemysqlhelper.cpp \
    ../../src/mysqlhelper.cpp

LIBS +=-lmariadb
TARGET = testemysqlhelper


