#include "qdeclarativemimetype_p.h"
#include "qdeclarativemimetyperegistry_p.h"
#include "qdeclarativeserviceaction_p.h"

#include <QtDeclarative/qdeclarativeextensionplugin.h>

// ------------------------------------------------------------------------------------------------

class QMimeTypesDeclarativeModule : public QDeclarativeExtensionPlugin
{
    Q_OBJECT

public:
    virtual void registerTypes(const char* uri);
};

// ------------------------------------------------------------------------------------------------

void QMimeTypesDeclarativeModule::registerTypes(const char* uri)
{
    qmlRegisterType<QDeclarativeMimeType>(uri, 1, 0, "MimeType");
    qmlRegisterType<QDeclarativeMimeTypeRegistry>(uri, 1, 0, "MimeTypeRegistry");
    qmlRegisterType<QDeclarativeServiceAction>(uri, 1, 0, "ServiceAction");
}

// ------------------------------------------------------------------------------------------------

#include "mimetypes.moc"

Q_EXPORT_PLUGIN2(qmimetypesdeclarativemodule, QT_PREPEND_NAMESPACE(QMimeTypesDeclarativeModule))
