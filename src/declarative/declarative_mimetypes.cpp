#include "declarative_mimetypes.h"

#include "declarativemimetype_p.h"
#include "declarativemimetyperegistry_p.h"
#include "declarativeserviceaction_p.h"

// ------------------------------------------------------------------------------------------------

void QMimeTypeDeclarativeExtensionPlugin::registerTypes(const char* uri)
{
    qmlRegisterType<DeclarativeMimeType>(uri, 1, 0, "MimeType");
    qmlRegisterType<DeclarativeMimeTypeRegistry>(uri, 1, 0, "MimeTypeRegistry");
    qmlRegisterType<DeclarativeServiceAction>(uri, 1, 0, "ServiceAction");
}

// ------------------------------------------------------------------------------------------------

Q_EXPORT_PLUGIN2(declarative_mimetypes, QT_PREPEND_NAMESPACE(QMimeTypeDeclarativeExtensionPlugin))
