/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtMimeTypes addon of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qdeclarativemimetyperegistry_p.h"

#include "qdeclarativemimetype_p.h"
#include "qdeclarativeserviceaction_p.h"

#include <QtCore/QDebug>

// ------------------------------------------------------------------------------------------------

QDeclarativeMimeTypeRegistry::QDeclarativeMimeTypeRegistry(QObject *theParent) :
        QObject(theParent),
        m_MimeTypeRegistry()
{}

// ------------------------------------------------------------------------------------------------

QDeclarativeMimeTypeRegistry::~QDeclarativeMimeTypeRegistry()
{
    //qDebug() << Q_FUNC_INFO;
}

// ------------------------------------------------------------------------------------------------

QMimeTypeRegistry &QDeclarativeMimeTypeRegistry::mimeTypeRegistry()
{
    return m_MimeTypeRegistry;
}

// ------------------------------------------------------------------------------------------------

QVariantList QDeclarativeMimeTypeRegistry::mimeTypes() const
{
    QVariantList result;

    foreach (const QMimeTypeName &mimeTypeName, m_MimeTypeRegistry.mimeTypes()) {
        result << mimeTypeName;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

QDeclarativeMimeType *QDeclarativeMimeTypeRegistry::findMimeType (
                                                      const QMimeTypeName &mimeTypeName
                                                  )
{
    return new QDeclarativeMimeType (
                   m_MimeTypeRegistry.findMimeType(mimeTypeName),
                   this   // <- The new object will be released later
                          //    when this registry is released.
               );
}

// ------------------------------------------------------------------------------------------------

QVariantList QDeclarativeMimeTypeRegistry::filenameExtensions() const
{
    QVariantList result;

    foreach (const QString &filenameExtension, m_MimeTypeRegistry.filenameExtensions()) {
        result << filenameExtension;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

QString QDeclarativeMimeTypeRegistry::extractFilenameExtension (
                                          const QString &fileName
                                      ) const
{
    return m_MimeTypeRegistry.extractFilenameExtension(fileName);
}

// ------------------------------------------------------------------------------------------------

QVariantList QDeclarativeMimeTypeRegistry::findMimeTypes (
                                               const QString &filenameExtension
                                           ) const
{
    QVariantList result;

    foreach (const QMimeTypeName &mimeTypeName, m_MimeTypeRegistry.findMimeTypes(filenameExtension)) {
        result << mimeTypeName;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

QMimeTypeName QDeclarativeMimeTypeRegistry::determineMimeType (
                                                const QByteArray &data
                                            ) const
{
    return m_MimeTypeRegistry.determineMimeType(data);
}

// ------------------------------------------------------------------------------------------------

QVariantList QDeclarativeMimeTypeRegistry::serviceActions() const
{
    QVariantList result;

    foreach (const QServiceActionName &serviceActionName, m_MimeTypeRegistry.serviceActions()) {
        result << serviceActionName;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

QDeclarativeServiceAction *
    QDeclarativeMimeTypeRegistry::findServiceAction (
                                      const QServiceActionName &serviceActionName
                                  )
{
    return new QDeclarativeServiceAction (
                   m_MimeTypeRegistry.findServiceAction(serviceActionName),
                   this   // <- The new object will be released later
                          //    when this registry is released.
               );
}

// ------------------------------------------------------------------------------------------------

bool QDeclarativeMimeTypeRegistry::userAlwaysSelectsApplication (
                                       const QServiceActionName &serviceActionName,
                                       const QMimeTypeName &mimeTypeName
                                   ) const
{
    return m_MimeTypeRegistry.userAlwaysSelectsApplication(serviceActionName, mimeTypeName);
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeMimeTypeRegistry::setUserAlwaysSelectsApplication (
                                       const QServiceActionName &serviceActionName,
                                       const QMimeTypeName &mimeTypeName,
                                       const bool newSetting
                                   )
{
    return m_MimeTypeRegistry.setUserAlwaysSelectsApplication(serviceActionName, mimeTypeName, newSetting);
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeMimeTypeRegistry::increaseApplicationPreference (
                                       const QApplicationId &applicationId,
                                       const QServiceActionName &serviceActionName,
                                       const QMimeTypeName &mimeTypeName
                                   )
{
    return m_MimeTypeRegistry.increaseApplicationPreference(applicationId, serviceActionName, mimeTypeName);
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeMimeTypeRegistry::decreaseApplicationPreference (
                                       const QApplicationId &applicationId,
                                       const QServiceActionName &serviceActionName,
                                       const QMimeTypeName &mimeTypeName
                                   )
{
    return m_MimeTypeRegistry.decreaseApplicationPreference(applicationId, serviceActionName, mimeTypeName);
}

// ------------------------------------------------------------------------------------------------

QVariantList QDeclarativeMimeTypeRegistry::findApplications (
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

QVariantList QDeclarativeMimeTypeRegistry::findApplications (
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
