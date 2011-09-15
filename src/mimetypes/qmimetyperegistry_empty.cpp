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

#include "qmimetyperegistry.h"

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

QList<QMimeTypeName> QMimeTypeRegistry::mimeTypes() const
{
    typedef QList<QMimeTypeName> Result;

    return Result();
}

// ------------------------------------------------------------------------------------------------

QMimeType QMimeTypeRegistry::findMimeType (
                                 const QMimeTypeName &searchMimeTypeName
                             ) const
{
    typedef QMimeType Result;

    Q_UNUSED(searchMimeTypeName)

    return Result();
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
    QString result;

    const QList<QString> theFileExtentions (fileExtentions());

    foreach (const QString &fileExtention, theFileExtentions) {
        if (fileExtention.length() > result.length() &&
                fileName.right(fileExtention.length()) == fileExtention) {
            result = fileExtention;
        }
    }

    return result;
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

QList<QServiceActionName> QMimeTypeRegistry::serviceActions() const
{
    typedef QList<QServiceActionName> Result;

    return Result();
}

// ------------------------------------------------------------------------------------------------

QServiceAction QMimeTypeRegistry::findServiceAction (
                                      const QServiceActionName &searchServiceActionName
                                  )
{
    typedef QServiceAction Result;

    Q_UNUSED(searchServiceActionName)

    return Result();
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
