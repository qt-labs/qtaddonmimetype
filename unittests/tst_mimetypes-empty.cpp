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

#include "tst_mimetypes.h"

#include "qmimetyperegistry.h"

#include <QtTest/QtTest>

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::initTestCase()
{
}

// ------------------------------------------------------------------------------------------------

static const QMimeTypeName &pngMimeTypeName()
{
    static const QMimeTypeName result ("image/png");
    return result;
}

// ------------------------------------------------------------------------------------------------

static const QString &pngMimeTypeDisplayName()
{
    static const QString result ("PNG File");
    return result;
}

// ------------------------------------------------------------------------------------------------

static const QString &pngMimeTypeIconUrl()
{
    static const QString result ("/usr/share/icons/oxygen/64x64/mimetypes/image-x-generic.png");
    return result;
}

// ------------------------------------------------------------------------------------------------

static QList<QString> buildPngMimeTypeFileExtentions()
{
    QList<QString> result;
    result << ".png";
    return result;
}

// ------------------------------------------------------------------------------------------------

static const QList<QString> &pngMimeTypeFileExtentions()
{
    static const QList<QString> result (buildPngMimeTypeFileExtentions());
    return result;
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeType_isValid()
{
    QMimeType instantiatedPngMimeType (
                  pngMimeTypeName(), pngMimeTypeDisplayName(), pngMimeTypeIconUrl(), pngMimeTypeFileExtentions()
              );

    QVERIFY(instantiatedPngMimeType.isValid());

    QMimeType otherPngMimeType (instantiatedPngMimeType);

    QVERIFY(otherPngMimeType.isValid());
    QCOMPARE(instantiatedPngMimeType, otherPngMimeType);

    QMimeType defaultMimeType;

    QVERIFY(!defaultMimeType.isValid());
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeType_name()
{
    QMimeType instantiatedPngMimeType (
                  pngMimeTypeName(), pngMimeTypeDisplayName(), pngMimeTypeIconUrl(), pngMimeTypeFileExtentions()
              );

    QMimeType otherPngMimeType (
                  QMimeTypeName(), pngMimeTypeDisplayName(), pngMimeTypeIconUrl(), pngMimeTypeFileExtentions()
              );

    // Verify that the Id is part of the equality test:
    QCOMPARE(instantiatedPngMimeType.name(), pngMimeTypeName());

    QVERIFY(instantiatedPngMimeType != otherPngMimeType);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeType_displayName()
{
    QMimeType instantiatedPngMimeType (
                  pngMimeTypeName(), pngMimeTypeDisplayName(), pngMimeTypeIconUrl(), pngMimeTypeFileExtentions()
              );

    QMimeType otherPngMimeType (
                  pngMimeTypeName(), QString(), pngMimeTypeIconUrl(), pngMimeTypeFileExtentions()
              );

    // Verify that the IconUrl is part of the equality test:
    QCOMPARE(instantiatedPngMimeType.iconUrl(), pngMimeTypeIconUrl());

    QVERIFY(instantiatedPngMimeType != otherPngMimeType);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeType_iconUrl()
{
    QMimeType instantiatedPngMimeType (
                  pngMimeTypeName(), pngMimeTypeDisplayName(), pngMimeTypeIconUrl(), pngMimeTypeFileExtentions()
              );

    QMimeType otherPngMimeType (
                  pngMimeTypeName(), pngMimeTypeDisplayName(), QString(), pngMimeTypeFileExtentions()
              );

    // Verify that the IconUrl is part of the equality test:
    QCOMPARE(instantiatedPngMimeType.iconUrl(), pngMimeTypeIconUrl());

    QVERIFY(instantiatedPngMimeType != otherPngMimeType);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeType_fileExtentions()
{
    QMimeType instantiatedPngMimeType (
                  pngMimeTypeName(), pngMimeTypeDisplayName(), pngMimeTypeIconUrl(), pngMimeTypeFileExtentions()
              );

    QMimeType otherPngMimeType (
                  pngMimeTypeName(), pngMimeTypeDisplayName(), pngMimeTypeIconUrl(), QList<QString>()
              );

    // Verify that the FileExtentions are part of the equality test:
    QCOMPARE(instantiatedPngMimeType.fileExtentions(), pngMimeTypeFileExtentions());

    QVERIFY(instantiatedPngMimeType != otherPngMimeType);
}

// ------------------------------------------------------------------------------------------------

static const QServiceActionName &editServiceActionName()
{
    static const QServiceActionName result ("edit");
    return result;
}

// ------------------------------------------------------------------------------------------------

static const QString &editServiceActionDisplayName()
{
    static const QString result ("Edit");
    return result;
}

// ------------------------------------------------------------------------------------------------

static const QString &editServiceActionIconUrl()
{
    static const QString result ("/dev/null");
    return result;
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QServiceAction_isValid()
{
    QServiceAction instantiatedServiceAction (
                       editServiceActionName(), editServiceActionDisplayName(), editServiceActionIconUrl()
                   );

    QVERIFY(instantiatedServiceAction.isValid());

    QServiceAction otherPngServiceAction (instantiatedServiceAction);

    QVERIFY(otherPngServiceAction.isValid());
    QCOMPARE(instantiatedServiceAction, otherPngServiceAction);

    QServiceAction defaultServiceAction;

    QVERIFY(!defaultServiceAction.isValid());
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QServiceAction_name()
{
    QServiceAction instantiatedServiceAction (
                       editServiceActionName(), editServiceActionDisplayName(), editServiceActionIconUrl()
                   );

    QServiceAction otherServiceAction (
                       QServiceActionName(), editServiceActionDisplayName(), editServiceActionIconUrl()
                   );

    // Verify that the Id is part of the equality test:
    QCOMPARE(instantiatedServiceAction.name(), editServiceActionName());

    QVERIFY(instantiatedServiceAction != otherServiceAction);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QServiceAction_displayName()
{
    QServiceAction instantiatedServiceAction (
                       editServiceActionName(), editServiceActionDisplayName(), editServiceActionIconUrl()
                   );

    QServiceAction otherServiceAction (
                       editServiceActionName(), QString(), editServiceActionIconUrl()
                   );

    // Verify that the DisplayName is part of the equality test:
    QCOMPARE(instantiatedServiceAction.displayName(), editServiceActionDisplayName());

    QVERIFY(instantiatedServiceAction != otherServiceAction);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QServiceAction_iconUrl()
{
    QServiceAction instantiatedServiceAction (
                       editServiceActionName(), editServiceActionDisplayName(), editServiceActionIconUrl()
                   );

    QServiceAction otherServiceAction (
                       editServiceActionName(), editServiceActionDisplayName(), QString()
                   );

    // Verify that the IconUrl is part of the equality test:
    QCOMPARE(instantiatedServiceAction.iconUrl(), editServiceActionIconUrl());

    QVERIFY(instantiatedServiceAction != otherServiceAction);
}

// ------------------------------------------------------------------------------------------------

const QMimeType &pngMimeType()
{
    static const QMimeType result (
                               pngMimeTypeName(),
                               pngMimeTypeDisplayName(),
                               pngMimeTypeIconUrl(),
                               pngMimeTypeFileExtentions()
                           );
    return result;
}

void tst_mimetypes::test_QMimeTypeRegistry_mimeTypes()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeTypeRegistry_findMimeType()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeTypeRegistry_fileExtentions()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeTypeRegistry_extractFileExtention()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeTypeRegistry_findMimeTypes()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeTypeRegistry_determineMimeType()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

const QServiceAction &editServiceAction()
{
    static const QServiceAction result (
                                    editServiceActionName(),
                                    editServiceActionDisplayName(),
                                    editServiceActionIconUrl()
                                );
    return result;
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeTypeRegistry_serviceActions()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeTypeRegistry_findServiceAction()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeTypeRegistry_setUserAlwaysSelectsApplication()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

void tst_mimetypes::test_QMimeTypeRegistry_findApplications()
{
    QVERIFY(false);
}

// ------------------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    tst_mimetypes tc;
    return QTest::qExec(&tc, argc, argv);
}
