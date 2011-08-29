#ifndef DECLARATIVE_MIME_TYPES_H_INCLUDED
#define DECLARATIVE_MIME_TYPES_H_INCLUDED

#include <QtDeclarative/qdeclarativeextensionplugin.h>

// ------------------------------------------------------------------------------------------------

class QMimeTypeDeclarativeExtensionPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT

public:
    virtual void registerTypes(const char* uri);
};

#endif
