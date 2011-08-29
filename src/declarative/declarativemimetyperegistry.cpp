#include "declarativemimetyperegistry_p.h"

#include "declarativemimetype_p.h"
#include "declarativeserviceaction_p.h"

#include <QtCore/QDebug>

// ------------------------------------------------------------------------------------------------

DeclarativeMimeTypeRegistry::DeclarativeMimeTypeRegistry(QObject *theParent) :
        QObject(theParent),
        m_MimeTypeRegistry()
{}

// ------------------------------------------------------------------------------------------------

DeclarativeMimeTypeRegistry::~DeclarativeMimeTypeRegistry()
{
    //qDebug() << Q_FUNC_INFO;
}

// ------------------------------------------------------------------------------------------------

QMimeTypeRegistry &DeclarativeMimeTypeRegistry::mimeTypeRegistry()
{
    return m_MimeTypeRegistry;
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeTypeRegistry::insertMimeType (
                                      DeclarativeMimeType *mimeType
                                  )
{
    if (mimeType == 0) {
        qWarning() << Q_FUNC_INFO << "mimeType:" << mimeType;
        return;
    }

    m_MimeTypeRegistry.insertMimeType(mimeType->mimeType());
}

// ------------------------------------------------------------------------------------------------

QVariantList DeclarativeMimeTypeRegistry::mimeTypes() const
{
    QVariantList result;

    foreach (const QMimeTypeName &mimeTypeName, m_MimeTypeRegistry.mimeTypes()) {
        result << mimeTypeName;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

DeclarativeMimeType *DeclarativeMimeTypeRegistry::findMimeType (
                                                      const QMimeTypeName &mimeTypeName
                                                  )
{
    return new DeclarativeMimeType (
                   m_MimeTypeRegistry.findMimeType(mimeTypeName),
                   this   // <- The new object will be released later
                          //    when this registry is released.
               );
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeTypeRegistry::removeMimeType (
                                      const QMimeTypeName &mimeTypeName
                                  )
{
    m_MimeTypeRegistry.removeMimeType(mimeTypeName);
}

// ------------------------------------------------------------------------------------------------

QVariantList DeclarativeMimeTypeRegistry::fileExtentions() const
{
    QVariantList result;

    foreach (const QString &fileExtention, m_MimeTypeRegistry.fileExtentions()) {
        result << fileExtention;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

QString DeclarativeMimeTypeRegistry::extractFileExtention (
                                         const QString &fileName
                                     ) const
{
    return m_MimeTypeRegistry.extractFileExtention(fileName);
}

// ------------------------------------------------------------------------------------------------

QVariantList DeclarativeMimeTypeRegistry::findMimeTypes (
                                              const QString &fileExtention
                                          ) const
{
    QVariantList result;

    foreach (const QMimeTypeName &mimeTypeName, m_MimeTypeRegistry.findMimeTypes(fileExtention)) {
        result << mimeTypeName;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

QMimeTypeName DeclarativeMimeTypeRegistry::determineMimeType (
                                               const QByteArray &data
                                           ) const
{
    return m_MimeTypeRegistry.determineMimeType(data);
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeTypeRegistry::insertServiceAction (
                                      DeclarativeServiceAction *serviceAction
                                  )
{
    if (serviceAction == 0) {
        qWarning() << Q_FUNC_INFO << "serviceAction:" << serviceAction;
        return;
    }

    m_MimeTypeRegistry.insertServiceAction(serviceAction->serviceAction());
}

// ------------------------------------------------------------------------------------------------

QVariantList DeclarativeMimeTypeRegistry::serviceActions() const
{
    QVariantList result;

    foreach (const QServiceActionName &serviceActionName, m_MimeTypeRegistry.serviceActions()) {
        result << serviceActionName;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

DeclarativeServiceAction *
    DeclarativeMimeTypeRegistry::findServiceAction (
                                     const QServiceActionName &serviceActionName
                                 )
{
    return new DeclarativeServiceAction (
                   m_MimeTypeRegistry.findServiceAction(serviceActionName),
                   this   // <- The new object will be released later
                          //    when this registry is released.
               );
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeTypeRegistry::removeServiceAction (
                                      const QServiceActionName &serviceActionName
                                  )
{
    return m_MimeTypeRegistry.removeServiceAction(serviceActionName);
}

// ------------------------------------------------------------------------------------------------

bool DeclarativeMimeTypeRegistry::userAlwaysSelectsApplication (
                                      const QServiceActionName &serviceActionName,
                                      const QMimeTypeName &mimeTypeName
                                  ) const
{
    return m_MimeTypeRegistry.userAlwaysSelectsApplication(serviceActionName, mimeTypeName);
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeTypeRegistry::setUserAlwaysSelectsApplication (
                                      const QServiceActionName &serviceActionName,
                                      const QMimeTypeName &mimeTypeName,
                                      const bool newSetting
                                  )
{
    return m_MimeTypeRegistry.setUserAlwaysSelectsApplication(serviceActionName, mimeTypeName, newSetting);
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeTypeRegistry::registerApplication (
                                      const QApplicationId &applicationId,
                                      const QServiceActionName &serviceActionName,
                                      const QMimeTypeName &mimeTypeName
                                  )
{
    return m_MimeTypeRegistry.registerApplication(applicationId, serviceActionName, mimeTypeName);
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeTypeRegistry::increaseApplicationPreference (
                                      const QApplicationId &applicationId,
                                      const QServiceActionName &serviceActionName,
                                      const QMimeTypeName &mimeTypeName
                                  )
{
    return m_MimeTypeRegistry.increaseApplicationPreference(applicationId, serviceActionName, mimeTypeName);
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeTypeRegistry::decreaseApplicationPreference (
                                      const QApplicationId &applicationId,
                                      const QServiceActionName &serviceActionName,
                                      const QMimeTypeName &mimeTypeName
                                  )
{
    return m_MimeTypeRegistry.decreaseApplicationPreference(applicationId, serviceActionName, mimeTypeName);
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeTypeRegistry::unregisterApplication (
                                      const QApplicationId &applicationId
                                  )
{
    return m_MimeTypeRegistry.unregisterApplication(applicationId);
}

// ------------------------------------------------------------------------------------------------


QVariantList DeclarativeMimeTypeRegistry::findApplications (
                                              const QMimeTypeName &mimeTypeName
                                          ) const
{
    QVariantList result;

    typedef QPair<QApplicationId, QServiceActionName> ApplicationIdAndServiceActionName;
    foreach (const ApplicationIdAndServiceActionName &applicationIdAndServiceActionName,
            m_MimeTypeRegistry.findApplications(mimeTypeName)) {
        QVariantList pair;
        pair << applicationIdAndServiceActionName.first;
        pair << applicationIdAndServiceActionName.second;
        // The insert operation of one variant will only work as intended
        // if it comes from a QVariant instead of a QVariantList:
        const QVariant &pair2 (pair);
        result << pair2;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

QVariantList DeclarativeMimeTypeRegistry::findApplications (
                                              const QServiceActionName &serviceActionName,
                                              const QMimeTypeName &mimeTypeName
                                          ) const
{
    QVariantList result;

    foreach (const QApplicationId &applicationId,
            m_MimeTypeRegistry.findApplications(serviceActionName, mimeTypeName)) {
        result << applicationId;
    }

    return result;
}
