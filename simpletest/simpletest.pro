QT       += core
QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app
TARGET   = tst_simple_mimetypes

# QtDeclarative/qdeclarativeprivate.h will not compile with -pedantic.
#MAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-long-long -Wnon-virtual-dtor -Wc++0x-compat
QMAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi           -Wshadow -Wno-long-long -Wnon-virtual-dtor -Wc++0x-compat

# dependency management
QMAKE_CXXFLAGS += -MMD
include_dependencies.target = include_dependencies
include_dependencies.commands = @if grep \"^include \\*.d\" Makefile >/dev/null 2>&1; then echo \"Dependency files are already included.\"; else echo \"include *.d\" >> Makefile; echo \"Please rerun make because dependency files will be included next time.\"; fi
QMAKE_EXTRA_TARGETS += include_dependencies
POST_TARGETDEPS += include_dependencies

# runtime environment
LIBS += -L ../lib -lqt-mimetypes

API_DIR = ..

INCLUDEPATH += $$API_DIR ../src/mimetypes


SOURCES += tst_simple_mimetypes.cpp

# No headers


SOURCES += $$API_DIR/src/declarative/declarativemimetype.cpp \
           $$API_DIR/src/declarative/declarativemimetyperegistry.cpp \
           $$API_DIR/src/declarative/declarativeserviceaction.cpp

HEADERS += $$API_DIR/src/declarative/declarativemimetype_p.h \
           $$API_DIR/src/declarative/declarativemimetyperegistry_p.h \
           $$API_DIR/src/declarative/declarativeserviceaction_p.h
