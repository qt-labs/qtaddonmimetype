/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtMimeTypes addon of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

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
