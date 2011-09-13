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

#include "qdeclarativemimetype_p.h"

#include <QtCore/QDebug>

// ------------------------------------------------------------------------------------------------

QDeclarativeMimeType::QDeclarativeMimeType(QObject *theParent) :
        QObject(theParent),
        m_MimeType()
{}

// ------------------------------------------------------------------------------------------------

QDeclarativeMimeType::QDeclarativeMimeType(const QMimeType &other, QObject *theParent) :
        QObject(theParent),
        m_MimeType(other)
{}

// ------------------------------------------------------------------------------------------------

QDeclarativeMimeType::~QDeclarativeMimeType()
{
    //qDebug() << Q_FUNC_INFO << "name():" << name();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeMimeType::assign(QDeclarativeMimeType *other)
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return;
    }

    m_MimeType = other->m_MimeType;
}

// ------------------------------------------------------------------------------------------------

bool QDeclarativeMimeType::equals(QDeclarativeMimeType *other) const
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return false;
    }

    return m_MimeType == other->m_MimeType;
}

// ------------------------------------------------------------------------------------------------

QMimeType QDeclarativeMimeType::mimeType() const
{
    return m_MimeType;
}

// ------------------------------------------------------------------------------------------------

bool QDeclarativeMimeType::isValid() const
{
    return m_MimeType.isValid();
}

// ------------------------------------------------------------------------------------------------

const QMimeTypeName &QDeclarativeMimeType::name() const
{
    return m_MimeType.name();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeMimeType::setName(const QMimeTypeName &newName)
{
    m_MimeType = QMimeType(newName, m_MimeType.displayName(), m_MimeType.iconUrl(), m_MimeType.fileExtentions());
}

// ------------------------------------------------------------------------------------------------

const QString &QDeclarativeMimeType::displayName() const
{
    return m_MimeType.displayName();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeMimeType::setDisplayName(const QString &newDisplayName)
{
    m_MimeType = QMimeType(m_MimeType.name(), newDisplayName, m_MimeType.iconUrl(), m_MimeType.fileExtentions());
}

// ------------------------------------------------------------------------------------------------

const QString &QDeclarativeMimeType::iconUrl() const
{
    return m_MimeType.iconUrl();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeMimeType::setIconUrl(const QString &newIconUrl)
{
    m_MimeType = QMimeType(m_MimeType.name(), m_MimeType.displayName(), newIconUrl, m_MimeType.fileExtentions());
}

// ------------------------------------------------------------------------------------------------

QVariantList QDeclarativeMimeType::fileExtentions() const
{
    QVariantList result;

    foreach (const QString &fileExtention, m_MimeType.fileExtentions()) {
        result << fileExtention;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeMimeType::setFileExtentions(const QVariantList &newFileExtentions)
{
    QList<QString> result;

    foreach (const QVariant &newFileExtention, newFileExtentions) {
        if (newFileExtention.type() != QVariant::String) {
            qWarning() << Q_FUNC_INFO << "newFileExtention" << newFileExtention << " is not a string!";
            continue;
        }

        result << newFileExtention.toString();
    }

    m_MimeType = QMimeType(m_MimeType.name(), m_MimeType.displayName(), m_MimeType.iconUrl(), result);
}
