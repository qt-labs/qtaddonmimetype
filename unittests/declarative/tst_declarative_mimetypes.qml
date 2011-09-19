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

import Qt 4.7
import QtTest 1.0
import QtMimeTypes 1.0

TestCase {
    name: "tst_declarative_mimetypes"

    function pngMimeTypeName() {
        return "image/png"
    }

    function pngMimeTypeDisplayName() {
        return "PNG File";
    }

    function pngMimeTypeIconUrl() {
        return "/usr/share/icons/oxygen/64x64/mimetypes/image-x-generic.png"
    }

    function firstPngMimeTypeFilenameExtension() {
        return ".png"
    }

    MimeType {
        id: instantiatedPngMimeType
        name: pngMimeTypeName()
        displayName: pngMimeTypeDisplayName()
        iconUrl: pngMimeTypeIconUrl()
        filenameExtensions: [ firstPngMimeTypeFilenameExtension() ]
    }

    MimeType {
        id: otherPngMimeType
    }

    MimeType {
        id: defaultMimeType
    }

    function test_MimeType_isValid() {
        compare(instantiatedPngMimeType.isValid, true)

        otherPngMimeType.assign(instantiatedPngMimeType)

        compare(otherPngMimeType.isValid, true)
        compare(instantiatedPngMimeType.equals(otherPngMimeType), true)
        compare(otherPngMimeType.equals(instantiatedPngMimeType), true)

        compare(defaultMimeType.isValid, false)
    }

    function test_MimeType_name() {
        otherPngMimeType.assign(instantiatedPngMimeType)
        otherPngMimeType.name = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedPngMimeType.name, pngMimeTypeName())

        compare(instantiatedPngMimeType.equals(otherPngMimeType), false)
    }

    function test_MimeType_displayName() {
        otherPngMimeType.assign(instantiatedPngMimeType)
        otherPngMimeType.displayName = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedPngMimeType.displayName, pngMimeTypeDisplayName())

        compare(instantiatedPngMimeType.equals(otherPngMimeType), false)
    }

    function test_MimeType_iconUrl() {
        otherPngMimeType.assign(instantiatedPngMimeType)
        otherPngMimeType.iconUrl = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedPngMimeType.iconUrl, pngMimeTypeIconUrl())

        compare(instantiatedPngMimeType.equals(otherPngMimeType), false)
    }

    function test_MimeType_filenameExtensions() {
        otherPngMimeType.assign(instantiatedPngMimeType)
        otherPngMimeType.filenameExtensions = []
        compare(otherPngMimeType.filenameExtensions.length, 0)

        // Verify that the Id is part of the equality test:
        compare(instantiatedPngMimeType.filenameExtensions.length, 1)
        compare(instantiatedPngMimeType.filenameExtensions[0], ".png")

        compare(instantiatedPngMimeType.equals(otherPngMimeType), false)
    }

    function editServiceActionName() {
        return "edit";
    }

    function editServiceActionDisplayName() {
        return "Edit"
    }

    function editServiceActionIconUrl() {
        return "/dev/null"
    }

    ServiceAction {
        id: instantiatedEditServiceAction
        name: editServiceActionName()
        displayName: editServiceActionDisplayName()
        iconUrl: editServiceActionIconUrl()
    }

    ServiceAction {
        id: otherEditServiceAction
    }

    ServiceAction {
        id: defaultServiceAction
    }

    function test_ServiceAction_isValid() {
        compare(instantiatedEditServiceAction.isValid, true)

        otherEditServiceAction.assign(instantiatedEditServiceAction)

        compare(otherEditServiceAction.isValid, true)
        compare(instantiatedEditServiceAction.equals(otherEditServiceAction), true)
        compare(otherEditServiceAction.equals(instantiatedEditServiceAction), true)

        compare(defaultServiceAction.isValid, false)
    }

    function test_ServiceAction_name() {
        otherEditServiceAction.assign(instantiatedEditServiceAction)
        otherEditServiceAction.name = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedEditServiceAction.name, editServiceActionName())

        compare(instantiatedEditServiceAction.equals(otherEditServiceAction), false)
    }

    function test_ServiceAction_displayName() {
        otherEditServiceAction.assign(instantiatedEditServiceAction)
        otherEditServiceAction.displayName = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedEditServiceAction.displayName, editServiceActionDisplayName())

        compare(instantiatedEditServiceAction.equals(otherEditServiceAction), false)
    }

    function test_ServiceAction_iconUrl() {
        otherEditServiceAction.assign(instantiatedEditServiceAction)
        otherEditServiceAction.iconUrl = ""

        // Verify that the Id is part of the equality test:
        compare(instantiatedEditServiceAction.iconUrl, editServiceActionIconUrl())

        compare(instantiatedEditServiceAction.equals(otherEditServiceAction), false)
    }

    MimeTypeRegistry {
        id: mimeTypeRegistry
    }

    function test_MimeTypeRegistry_mimeTypes() {
        compare(1, 0)
    }

    function test_MimeTypeRegistry_findMimeType() {
        compare(1, 0)
    }

    function test_MimeTypeRegistry_filenameExtensions() {
        compare(1, 0)
    }

    function test_MimeTypeRegistry_extractFilenameExtension() {
        compare(1, 0)
    }

    function test_MimeTypeRegistry_findMimeTypes() {
        compare(1, 0)
    }

    function test_MimeTypeRegistry_determineMimeType() {
        compare(1, 0)
    }

    function test_MimeTypeRegistry_serviceActions() {
        compare(1, 0)
    }

    function test_MimeTypeRegistry_findServiceAction() {
        compare(1, 0)
    }

    function test_MimeTypeRegistry_setUserAlwaysSelectsApplication() {
        compare(1, 0)
    }

    function shareOnPicasaWebAlbumsName() { return 'shareOnPicasaWebAlbums' }
    function shareOnPicasaWebAlbumsDisplayName() { return 'Share on Picasa Web Albums' }
    function shareOnPicasaWebAlbumsIconUrl() { return '/dev/null' }

    ServiceAction {
        id: shareOnPicasaWebAlbumsServiceAction
        name: shareOnPicasaWebAlbumsName()
        displayName: shareOnPicasaWebAlbumsDisplayName()
        iconUrl: shareOnPicasaWebAlbumsIconUrl()
    }

    function test_MimeTypeRegistry_findApplications() {
        compare(1, 0)
    }
}
