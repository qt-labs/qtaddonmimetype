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

#ifndef DECLARATIVE_MIME_TYPE_P_H_INCLUDED
#define DECLARATIVE_MIME_TYPE_P_H_INCLUDED

#include "qmimetype.h"

#include <QtDeclarative/qdeclarative.h>

#include <QtCore/QObject>

// ------------------------------------------------------------------------------------------------

class QDeclarativeMimeType : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name
               READ name
               WRITE setName)

    Q_PROPERTY(QString displayName
               READ displayName
               WRITE setDisplayName)

    Q_PROPERTY(QString iconUrl
               READ iconUrl
               WRITE setIconUrl)

    Q_PROPERTY(QVariantList filenameExtensions
               READ filenameExtensions
               WRITE setFilenameExtensions
               STORED false)

    Q_PROPERTY(bool isValid
               READ isValid
               STORED false)

protected:
    // We keep this destructor with its default value of 0 protected since only
    // QDeclarativePrivate::QDeclarativeElement<T> needs it:
    QDeclarativeMimeType(QObject *theParent = 0);

public:
    // We don't allow theParent to have a default value of 0 because in all
    // likelyhood we want to force the caller to specify its QObject so the
    // object will get destroyed in the caller's destructor:
    QDeclarativeMimeType(const QMimeType &other, QObject *theParent);

    ~QDeclarativeMimeType();

    Q_INVOKABLE void assign(QDeclarativeMimeType *other);
    Q_INVOKABLE bool equals(QDeclarativeMimeType *other) const;

    QMimeType mimeType() const;

    bool isValid() const;

    const QMimeTypeName &name() const;
    void setName(const QMimeTypeName &newName);
    const QString &displayName() const;
    void setDisplayName(const QString &newDisplayName);
    const QString &iconUrl() const;
    void setIconUrl(const QString &newIconUrl);
    QVariantList filenameExtensions() const;
    void setFilenameExtensions(const QVariantList &newFilenameExtensions);

private:
    QMimeType m_MimeType;
};

QML_DECLARE_TYPE(QDeclarativeMimeType)

#endif
