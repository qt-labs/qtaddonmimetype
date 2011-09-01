#include "mimetyperegistry.h"

#include <QtCore/QFuture>

// ------------------------------------------------------------------------------------------------

class QMimeTypeRegistryPrivate
{};

// ------------------------------------------------------------------------------------------------

QMimeTypeRegistry::QMimeTypeRegistry() :
        d_ptr(new QMimeTypeRegistryPrivate())
{}

// ------------------------------------------------------------------------------------------------

QMimeTypeRegistry::~QMimeTypeRegistry()
{
    delete d_ptr; d_ptr = 0;
}

// ------------------------------------------------------------------------------------------------

void QMimeTypeRegistry::insertMimeType (
                            const QMimeType &mimeType
                        )
{
    Q_UNUSED(mimeType)
}

// ------------------------------------------------------------------------------------------------

QList<QMimeTypeName> QMimeTypeRegistry::mimeTypes() const
{
    typedef QList<QMimeTypeName> Result;

    return Result();
}

// ------------------------------------------------------------------------------------------------

QMimeType QMimeTypeRegistry::findMimeType (
                                 const QMimeTypeName &searchQMimeTypeName
                             ) const
{
    typedef QMimeType Result;

    Q_UNUSED(searchQMimeTypeName)

    return Result();
}

// ------------------------------------------------------------------------------------------------

void QMimeTypeRegistry::removeMimeType (
                            const QMimeTypeName &mimeTypeName
                        )
{
    Q_UNUSED(mimeTypeName)
}

// ------------------------------------------------------------------------------------------------

QList<QString> QMimeTypeRegistry::fileExtentions() const
{
    typedef QList<QString> Result;

    return Result();
}

// ------------------------------------------------------------------------------------------------

QString QMimeTypeRegistry::extractFileExtention (
                               const QString &fileName
                           ) const
{
    Q_UNUSED(fileName)

    return QString();
}

// ------------------------------------------------------------------------------------------------

QList<QMimeTypeName> QMimeTypeRegistry::findMimeTypes (
                                            const QString &searchFileExtention
                                        ) const
{
    typedef QList<QMimeTypeName> Result;

    Q_UNUSED(searchFileExtention)

    return Result();
}

// ------------------------------------------------------------------------------------------------

QMimeTypeName QMimeTypeRegistry::determineMimeType (
                                     const QByteArray &data
                                 ) const
{
    typedef QMimeTypeName Result;

    Q_UNUSED(data)

    return Result();
}

// ------------------------------------------------------------------------------------------------

void QMimeTypeRegistry::insertServiceAction (
                            const QServiceAction &serviceAction
                        )
{
    Q_UNUSED(serviceAction)
}

// ------------------------------------------------------------------------------------------------

QList<QServiceActionName> QMimeTypeRegistry::serviceActions() const
{
    typedef QList<QServiceActionName> Result;

    return Result();
}

// ------------------------------------------------------------------------------------------------

QServiceAction QMimeTypeRegistry::findServiceAction (
                                      const QServiceActionName &searchQServiceActionName
                                  )
{
    typedef QServiceAction Result;

    Q_UNUSED(searchQServiceActionName)

    return Result();
}

// ------------------------------------------------------------------------------------------------

void QMimeTypeRegistry::removeServiceAction (
                            const QServiceActionName &serviceActionName
                        )
{
    Q_UNUSED(serviceActionName)
}

// ------------------------------------------------------------------------------------------------

bool QMimeTypeRegistry::userAlwaysSelectsApplication (
                            const QServiceActionName &serviceActionName,
                            const QMimeTypeName &mimeTypeName
                        ) const
{
    typedef bool Result;

    Q_UNUSED(serviceActionName)
    Q_UNUSED(mimeTypeName)

    return Result();
}

// ------------------------------------------------------------------------------------------------

void QMimeTypeRegistry::setUserAlwaysSelectsApplication (
                            const QServiceActionName &serviceActionName,
                            const QMimeTypeName &mimeTypeName,
                            const bool newSetting
                        )
{
    Q_UNUSED(serviceActionName)
    Q_UNUSED(mimeTypeName)
    Q_UNUSED(newSetting)
}

// ------------------------------------------------------------------------------------------------

void QMimeTypeRegistry::registerApplication (
                            const QApplicationId &applicationId,
                            const QServiceActionName &serviceActionName,
                            const QMimeTypeName &mimeTypeName
                        )
{
    Q_UNUSED(applicationId)
    Q_UNUSED(serviceActionName)
    Q_UNUSED(mimeTypeName)
}

// ------------------------------------------------------------------------------------------------

void QMimeTypeRegistry::increaseApplicationPreference (
                            const QApplicationId &applicationId,
                            const QServiceActionName &serviceActionName,
                            const QMimeTypeName &mimeTypeName
                        )
{
    Q_UNUSED(applicationId)
    Q_UNUSED(serviceActionName)
    Q_UNUSED(mimeTypeName)
}

// ------------------------------------------------------------------------------------------------

void QMimeTypeRegistry::decreaseApplicationPreference (
                            const QApplicationId &applicationId,
                            const QServiceActionName &serviceActionName,
                            const QMimeTypeName &mimeTypeName
                        )
{
    Q_UNUSED(applicationId)
    Q_UNUSED(serviceActionName)
    Q_UNUSED(mimeTypeName)
}

// ------------------------------------------------------------------------------------------------

void QMimeTypeRegistry::unregisterApplication (
                            const QApplicationId &applicationId
                        )
{
    Q_UNUSED(applicationId)
}

// ------------------------------------------------------------------------------------------------

QList<QPair<QApplicationId, QServiceActionName> >
    QMimeTypeRegistry::findApplications (
                           const QMimeTypeName &mimeTypeName
                       ) const
{
    typedef QList<QPair<QApplicationId, QServiceActionName> > Result;

    Q_UNUSED(mimeTypeName)

    return Result();
}

// ------------------------------------------------------------------------------------------------

QList<QApplicationId>
    QMimeTypeRegistry::findApplications (
                           const QServiceActionName &serviceActionName,
                           const QMimeTypeName &mimeTypeName
                       ) const
{
    typedef QList<QApplicationId> Result;

    Q_UNUSED(serviceActionName)
    Q_UNUSED(mimeTypeName)

    return Result();
}
