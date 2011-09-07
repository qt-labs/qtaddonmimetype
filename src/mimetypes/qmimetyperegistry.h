#ifndef MIMETYPES_H_INCLUDED
#define MIMETYPES_H_INCLUDED

#include "qmimetype.h"
#include "qmimetypesfwd.h"
#include "qserviceaction.h"

#include <QtCore/QList>
#include <QtCore/QPair>

class QMimeTypeRegistryPrivate;

class QByteArray;

// ------------------------------------------------------------------------------------------------

class QMimeTypeRegistry
{
public:
    QMimeTypeRegistry();

    ~QMimeTypeRegistry();

    // --------------------------------------------------------------------------------------------

    void insertMimeType (
             const QMimeType &mimeType
         );

    QList<QMimeTypeName> mimeTypes() const;

    QMimeType findMimeType (
                  const QMimeTypeName &mimeTypeName
              ) const;

    void removeMimeType (
             const QMimeTypeName &mimeTypeName
         );

    // --------------------------------------------------------------------------------------------

    QList<QString> fileExtentions() const;

    QString extractFileExtention (
                 const QString &fileName
            ) const;

    QList<QMimeTypeName> findMimeTypes (
                             const QString &fileExtention
                         ) const;

    // --------------------------------------------------------------------------------------------

    QMimeTypeName determineMimeType (
                      const QByteArray &data
                  ) const;

    // --------------------------------------------------------------------------------------------

    void insertServiceAction (
             const QServiceAction &serviceAction
         );

    QList<QServiceActionName> serviceActions() const;

    QServiceAction findServiceAction (
                       const QServiceActionName &serviceActionName
                   );

    void removeServiceAction (
             const QServiceActionName &serviceActionName
         );

    // --------------------------------------------------------------------------------------------

    bool userAlwaysSelectsApplication (
             const QServiceActionName &serviceActionName,
             const QMimeTypeName &mimeTypeName
         ) const;

    void setUserAlwaysSelectsApplication (
             const QServiceActionName &serviceActionName,
             const QMimeTypeName &mimeTypeName,
             const bool newSetting
         );

    // --------------------------------------------------------------------------------------------

    void registerApplication (
             const QApplicationId &applicationId,
             const QServiceActionName &serviceActionName,
             const QMimeTypeName &mimeTypeName
         );

    void increaseApplicationPreference (
             const QApplicationId &applicationId,
             const QServiceActionName &serviceActionName,
             const QMimeTypeName &mimeTypeName
         );

    void decreaseApplicationPreference (
             const QApplicationId &applicationId,
             const QServiceActionName &serviceActionName,
             const QMimeTypeName &mimeTypeName
         );

    void unregisterApplication (
             const QApplicationId &applicationId
         );

    QList<QPair<QApplicationId, QServiceActionName> > findApplications (
                                                          const QMimeTypeName &mimeTypeName
                                                      ) const;

    QList<QApplicationId> findApplications (
                              const QServiceActionName &serviceActionName,
                              const QMimeTypeName &mimeTypeName
                          ) const;

    // --------------------------------------------------------------------------------------------

private:
    QMimeTypeRegistryPrivate *d_ptr;
};

#endif
