CONFIG   += qt
TEMPLATE = lib
TARGET   = qt-mimetypes
DESTDIR  = ../../lib

# QtCore/qlist.h uses /usr/include/limits.h which uses does not compile with -pedantic.
#MAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-long-long -Wnon-virtual-dtor -Wc++0x-compat
QMAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi           -Wshadow -Wno-long-long -Wnon-virtual-dtor -Wc++0x-compat

# dependency management
QMAKE_CXXFLAGS += -MMD
include_dependencies.target = include_dependencies
include_dependencies.commands = @if grep \"^include \\*.d\" Makefile >/dev/null 2>&1; then echo \"Dependency files are already included.\"; else echo \"include *.d\" >> Makefile; echo \"Please rerun make because dependency files will be included next time.\"; fi
QMAKE_EXTRA_TARGETS += include_dependencies
POST_TARGETDEPS += include_dependencies


API_DIR = ../..

INCLUDEPATH += $$API_DIR


SOURCES += $$API_DIR/src/mimetypes/mimetype.cpp \
           $$API_DIR/src/mimetypes/mimetyperegistry.cpp \
           mimetyperegistry_empty.cpp \
           $$API_DIR/src/mimetypes/serviceaction.cpp

HEADERS += $$API_DIR/src/mimetypes/applicationfwd.h \
           $$API_DIR/src/mimetypes/mimetype.h \
           $$API_DIR/src/mimetypes/mimetype_p.h \
           $$API_DIR/src/mimetypes/mimetyperegistry.h \
           $$API_DIR/src/mimetypes/serviceaction.h \
           $$API_DIR/src/mimetypes/serviceaction_p.h
