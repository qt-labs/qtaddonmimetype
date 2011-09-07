#ifndef DECLARATIVE_MIME_TYPE_REGISTRY_P_H_INCLUDED
#define DECLARATIVE_MIME_TYPE_REGISTRY_P_H_INCLUDED

#include "qmimetyperegistry.h"

#include <QtDeclarative/qdeclarative.h>

#include <QtCore/QObject>

class QDeclarativeMimeType;
class QDeclarativeServiceAction;

// ------------------------------------------------------------------------------------------------

class QDeclarativeMimeTypeRegistry : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList mimeTypes
               READ mimeTypes
               STORED false)

    Q_PROPERTY(QVariantList fileExtentions
               READ fileExtentions
               STORED false)

    Q_PROPERTY(QVariantList serviceActions
               READ serviceActions
               STORED false)

protected:
    // We keep this destructor with its default value of 0 protected since only
    // QDeclarativePrivate::QDeclarativeElement<T> needs it:
    QDeclarativeMimeTypeRegistry(QObject *theParent = 0);

public:
    ~QDeclarativeMimeTypeRegistry();

    QMimeTypeRegistry &mimeTypeRegistry();

    // --------------------------------------------------------------------------------------------

    Q_INVOKABLE void insertMimeType (
                         QDeclarativeMimeType *mimeType
                     );

    QVariantList mimeTypes() const;

    Q_INVOKABLE QDeclarativeMimeType *findMimeType (
                                          const QString &mimeTypeName
                                      );

    Q_INVOKABLE void removeMimeType (
                         const QString &mimeTypeName
                     );

    // --------------------------------------------------------------------------------------------

    QVariantList fileExtentions() const;

    Q_INVOKABLE QString extractFileExtention (
                            const QString &fileName
                        ) const;

    Q_INVOKABLE QVariantList findMimeTypes (
                                 const QString &fileExtention
                             ) const;

    // --------------------------------------------------------------------------------------------

    QString determineMimeType (
                const QByteArray &data
            ) const;

    // --------------------------------------------------------------------------------------------

    Q_INVOKABLE void insertServiceAction (
                         QDeclarativeServiceAction *serviceAction
                     );

    QVariantList serviceActions() const;

    Q_INVOKABLE QDeclarativeServiceAction *findServiceAction (
                                               const QString &serviceActionName
                                           );

    Q_INVOKABLE void removeServiceAction (
                         const QString &serviceActionName
                     );

    // --------------------------------------------------------------------------------------------

    Q_INVOKABLE bool userAlwaysSelectsApplication (
                         const QString &serviceActionName,
                         const QString &mimeTypeName
                     ) const;

    Q_INVOKABLE void setUserAlwaysSelectsApplication (
                         const QString &serviceActionName,
                         const QString &mimeTypeName,
                         const bool newSetting
                     );

    // --------------------------------------------------------------------------------------------

    Q_INVOKABLE void registerApplication (
                         const QString &applicationId,
                         const QString &serviceActionName,
                         const QString &mimeTypeName
                     );

    Q_INVOKABLE void increaseApplicationPreference (
                         const QString &applicationId,
                         const QString &serviceActionName,
                         const QString &mimeTypeName
                     );

    Q_INVOKABLE void decreaseApplicationPreference (
                         const QString &applicationId,
                         const QString &serviceActionName,
                         const QString &mimeTypeName
                     );

    Q_INVOKABLE void unregisterApplication (
                         const QString &applicationId
                     );

    Q_INVOKABLE QVariantList findApplications (
                                 const QString &mimeTypeName
                             ) const;

    Q_INVOKABLE QVariantList findApplications (
                                 const QString &serviceActionName,
                                 const QString &mimeTypeName
                             ) const;

    // --------------------------------------------------------------------------------------------

private:
    QMimeTypeRegistry m_MimeTypeRegistry;
};

QML_DECLARE_TYPE(QDeclarativeMimeTypeRegistry)

#endif
