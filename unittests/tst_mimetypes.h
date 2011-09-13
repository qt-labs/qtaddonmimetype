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

#ifndef TST_MIMETYPES_H_INCLUDED
#define TST_MIMETYPES_H_INCLUDED

#include <QtCore/QObject>

class tst_mimetypes : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();

    void test_QMimeType_isValid();
    void test_QMimeType_name();
    void test_QMimeType_displayName();
    void test_QMimeType_iconUrl();
    void test_QMimeType_fileExtentions();

    void test_QServiceAction_isValid();
    void test_QServiceAction_name();
    void test_QServiceAction_displayName();
    void test_QServiceAction_iconUrl();

    void test_QMimeTypeRegistry_mimeTypes();
    void test_QMimeTypeRegistry_findMimeType();
    void test_QMimeTypeRegistry_fileExtentions();
    void test_QMimeTypeRegistry_extractFileExtention();
    void test_QMimeTypeRegistry_findMimeTypes();
    void test_QMimeTypeRegistry_determineMimeType();
    void test_QMimeTypeRegistry_serviceActions();
    void test_QMimeTypeRegistry_findServiceAction();
    void test_QMimeTypeRegistry_setUserAlwaysSelectsApplication();
    void test_QMimeTypeRegistry_findApplications();
};

#endif
