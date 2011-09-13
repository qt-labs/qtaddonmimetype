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
