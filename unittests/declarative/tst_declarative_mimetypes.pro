TEMPLATE=app
TARGET=tst_declarative_mimetypes
CONFIG += warn_on qmltestcase

# runtime environment
LIBS += -L ../../lib -lqt-mimetypes


API_DIR = ../..

INCLUDEPATH += $$API_DIR


SOURCES += $$API_DIR/unittests/declarative/tst_declarative_mimetypes.cpp


# this reads the QML files from the same directory as this pro file
DEFINES += QUICK_TEST_SOURCE_DIR=\"\\\"$$PWD\\\"\"
