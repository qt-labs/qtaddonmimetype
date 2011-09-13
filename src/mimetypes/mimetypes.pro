#CONFIG   += qt
TEMPLATE = lib
TARGET   = QtMimeTypes

# QtCore/qlist.h uses /usr/include/limits.h which uses does not compile with -pedantic.
#MAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-long-long -Wnon-virtual-dtor
QMAKE_CXXFLAGS += -W -Wall -Wextra -Werror -ansi           -Wshadow -Wno-long-long -Wnon-virtual-dtor
mac|darwin: {
} else {
    QMAKE_CXXFLAGS += -Wc++0x-compat
}

# dependency management
QMAKE_CXXFLAGS += -MMD
include_dependencies.target = include_dependencies
include_dependencies.commands = @if grep \"^-include \\*.d\" Makefile >/dev/null 2>&1; then echo \"Dependency files are already included.\"; else echo \"-include *.d\" >> Makefile; echo \"Please rerun make because dependency files will be included next time.\"; fi
QMAKE_EXTRA_TARGETS += include_dependencies
POST_TARGETDEPS += include_dependencies


API_DIR = ../..

INCLUDEPATH += $$API_DIR/src/mimetypes


SOURCES += $$API_DIR/src/mimetypes/qmimetype.cpp \
           $$API_DIR/src/mimetypes/qmimetyperegistry.cpp \
           qmimetyperegistry_empty.cpp \
           $$API_DIR/src/mimetypes/qserviceaction.cpp

HEADERS += $$API_DIR/src/mimetypes/qmimetypesfwd.h \
           $$API_DIR/src/mimetypes/qmimetype.h \
           $$API_DIR/src/mimetypes/qmimetype_p.h \
           $$API_DIR/src/mimetypes/qmimetyperegistry.h \
           $$API_DIR/src/mimetypes/qserviceaction.h \
           $$API_DIR/src/mimetypes/qserviceaction_p.h


the_includes.files += $$API_DIR/src/mimetypes/qmimetypesfwd.h \
                      $$API_DIR/src/mimetypes/qmimetype.h \
                      $$API_DIR/src/mimetypes/qmimetyperegistry.h \
                      $$API_DIR/src/mimetypes/qserviceaction.h


INSTALLS += the_includes target
