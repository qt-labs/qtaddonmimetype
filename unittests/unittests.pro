CONFIG   += qtestlib
TEMPLATE = app
TARGET   = tst_mimetypes
DEPENDPATH += .

QMAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-long-long -Wnon-virtual-dtor -Wc++0x-compat

# dependency management
QMAKE_CXXFLAGS += -MMD
include_dependencies.target = include_dependencies
include_dependencies.commands = @if grep \"^include \\*.d\" Makefile >/dev/null 2>&1; then echo \"Dependency files are already included.\"; else echo \"include *.d\" >> Makefile; echo \"Please rerun make because dependency files will be included next time.\"; fi
QMAKE_EXTRA_TARGETS += include_dependencies
POST_TARGETDEPS += include_dependencies

# runtime environment
LIBS += -L ../lib -lqt-mimetypes


API_DIR = ..

INCLUDEPATH += $$API_DIR/src/mimetypes $$API_DIR/unittests


SOURCES += tst_mimetypes-empty.cpp

HEADERS += $$API_DIR/unittests/tst_mimetypes.h


QMAKE_EXTRA_TARGETS += check
check.depends = $$TARGET
check.commands = ./$$TARGET -xunitxml -o unitTestResults.xml
