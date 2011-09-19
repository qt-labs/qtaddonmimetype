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

#ifndef MIME_TYPE_H_INCLUDED
#define MIME_TYPE_H_INCLUDED

#include <QtCore/QScopedPointer>

class QMimeTypePrivate;

class QString;

template<typename T>
class QList;

// ------------------------------------------------------------------------------------------------

// A temporary solution in case the type changes until the final release:
typedef QString QMimeTypeName;

// ------------------------------------------------------------------------------------------------

class QMimeType
{
public:
    QMimeType();
    QMimeType(const QMimeTypeName &theName,
              const QString &theDisplayName,
              const QString &theIconUrl,
              const QList<QString> &theFilenameExtensions);
    QMimeType(const QMimeType &other);
    QMimeType &operator=(const QMimeType &other);
    ~QMimeType();

    bool operator==(const QMimeType &other) const;

    inline bool operator!=(const QMimeType &other) const
    {
        return !operator==(other);
    }

    bool isValid() const;

    const QMimeTypeName &name() const;
    const QString &displayName() const;
    const QString &iconUrl() const;
    const QList<QString> &filenameExtensions() const;

private:
    QScopedPointer<QMimeTypePrivate> d_ptr;
};

#endif
