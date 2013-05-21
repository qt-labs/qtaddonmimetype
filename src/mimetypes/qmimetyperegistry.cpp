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

#include "qmimetyperegistry.h"

#include <QtCore/QByteArray>

// ------------------------------------------------------------------------------------------------

// title -> part -> chapter

/*!
    \page design
    \title MIME type API for Qt

    This is a draft of the MIME type API for Qt

    \part Default handlers vs. user selection

    #US001

    \table
        \header
            \o {3, 1} text, audio, image, video file
        \row
            \o open
            \o file
        \row
            \o edit
            \o file
        \row
            \o share
            \o file
            \o => Pick an application (Picasa, Flickr, Facebook, Google+, Google Buzz, Twitter, TwitPic, YouTube, ...)
    \endtable

    \table
        \header
            \o {3, 1} URL handling (Change wording)
        \row
            \o open
            \o http URL
            \o => Bookmark application
        \row
            \o open
            \o tel:phone_number URL
            \o => Contacts application
        \row
            \o open
            \o Skype ID URL
            \o => Contacts application
        \row
            \o open
            \o Facebook User URL
            \o => Contacts application
    \endtable

    \table
        \header
            \o {3, 1} URL modifying (Change wording)
        \row
            \o edit
            \o http URL
            \o => Bookmark application
        \row
            \o edit
            \o tel:phone_number URL
            \o => Contacts application
        \row
            \o edit
            \o Skype ID URL
            \o => Contacts application or Profile editing
        \row
            \o edit
            \o Facebook User URL
            \o => Contacts application or Profile editing
    \endtable

    \table
        \header
            \o {3, 1} URL sharing
        \row
            \o share
            \o Any URL
            \o => Pick an application
    \endtable

    \table
        \header
            \o {3, 1} Not really an action but important anyways (Maybe later)
        \row
            \o textedit
            \o http URL
            \o <- TODO: Plugin for validation!!!
        \row
            \o textedit
            \o tel:phone_number URL
            \o <- TODO: Plugin for validation!!!
        \row
            \o textedit
            \o Skype ID URL
            \o <- TODO: Plugin for validation!!!
        \row
            \o textedit
            \o Facebook User URL
            \o <- TODO: Plugin for validation!!!
    \endtable

    #US004

    \table
        \header
            \o {3, 1} Not really an action but important anyways (Maybe later)
        \row
            \o call
            \o http URL
            \o => Browser application #US005
        \row
            \o call
            \o tel:phone_number URL
            \o => Phone application
        \row
            \o call
            \o Skype ID URL
            \o => Skype application
        \row
            \o call
            \o contact UUID vcard
            \o => Address book application
    \endtable

    \table
        \header
            \o {3, 1} UUID
        \row
            \o open
            \o file
        \row
            \o edit
            \o file
        \row
            \o share
            \o file
            \o => Pick an application (Picasa, Flickr, Facebook, Google+, Google Buzz, Twitter, TwitPic, YouTube, ...)
    \endtable

    \table
        \header
            \o {3, 1} Messaging
        \row
            \o message
            \o mailto:email_address
            \o => E-Mail application
        \row
            \o message
            \o tel:phone_number URL
            \o => SMS application
        \row
            \o message
            \o Twitter User URL
            \o => Twitter application
        \row
            \o message
            \o Facebook User URL
            \o => Facebook application
        \row
            \o message
            \o contact UUID vcard
            \o => Address book application
    \endtable

    \table
        \header
            \o {3, 1} Chatting
        \row
            \o chat
            \o Google Mail user URL
            \o => E-Mail application
        \row
            \o chat
            \o Skype user URL
            \o => Twitter application
        \row
            \o chat
            \o Facebook User URL
            \o => Facebook application
        \row
            \o chat
            \o contact UUID vcard
            \o => Address book application
    \endtable

    Good actions for files seem to be open, edit and share.

    Good actions for User identities and addresses and numbers seem to be directory, call, message and chat?

    A good idea is to define a default action "" that represents open and not have an "open" action at all.

    We might have to consult UI guidelines.

    \list
        \o tel open => phone app => selection between call and message
        \o skype open => skype app => selection between call, video call, chat
        \o FB open => FB app => chat, message
    \endlist

    Open questions:

    \list
        \o ProcessManager handles URLs, already???
        \o ProcessManager handles default action, already???
    \endlist

    Check with Martin Zielinski!!!

    We need a setter method for the default handler!!!
    We need to be able to reset default handling. In that case the user needs to pick an application.

    URL need to be parsed to determine the service:

    \list
        \o http:// * => *
        \o http://www.facebook.com/ * => Facebook
        \o http://www.dropbox.com/ * => Dropbox
        \o http://www.nytimes.com/ * => NYT
        \o http://www.youtube.com/ * => YouTube
        \o http://www.ovi.com/ * => Ovi
    \endlist
 */

// ------------------------------------------------------------------------------------------------

/*!
    \typedef QApplicationId
    \brief ID of applications that provide service actions on MIME types
 */

// ------------------------------------------------------------------------------------------------

/*!
    \class QMimeTypeRegistry
    \brief QMimeTypeRegistry is the data store that manages mime types, service actions and filename extensions.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QMimeTypeRegistry::QMimeTypeRegistry();
    \brief Puts the injected implementation object into place.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QMimeTypeRegistry::~QMimeTypeRegistry()
    \brief Destroys the implementation object.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn void QMimeTypeRegistry::insertMimeType (
                                    const QMimeType &mimeType
                                );
    \brief Registers a new MIME type.

    \a mimeType The MIME type object that is being registered
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QList<QMimeTypeName> QMimeTypeRegistry::mimeTypes() const;
    \brief Returns the list of registered MIME types.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QMimeType QMimeTypeRegistry::findMimeType (
                                         const QMimeTypeName &mimeTypeName
                                     ) const;
    \brief Searches for the specified MIME type.

    \a mimeTypeName The MIME type ID for which we need to perform the search

    Returns a 0 pointer if the specified MIME Type ID is not known.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn void QMimeTypeRegistry::removeMimeType (
                                    const QMimeTypeName &mimeTypeName
                                );
    \brief Deregisters a new MIME type.

    \a mimeTypeName The MIME type ID that is being deregistered
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QList<QString> QMimeTypeRegistry::filenameExtensions() const;
    \brief Returns a list of filename extensions of all registered MIME types.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QString QMimeTypeRegistry::extractFilenameExtension (
                                       const QString &fileName
                                   ) const;
    \brief Extracts the filename extension from the specified file name.

    \a fileName A file name of which we need to determine the extension.

    Will only extract as deep into the file name as there are filename extensions known currently.
    E.g. "a.b.c.tar.gz" will result in ".tar.gz".

    Returns an empty string if no knwn file extentipn coulb be extracted from the file name.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QList<QMimeTypeName> QMimeTypeRegistry::findMimeTypes (
                                                    const QString &filenameExtension
                                                ) const;
    \brief Determines which MIME types use the specified filename extension.

    \a filenameExtension The filename extension for which we need to perform the search.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QMimeTypeName QMimeTypeRegistry::determineMimeType (
                                             const QByteArray &data
                                         ) const;
    \brief Determines the MIME type of the data in the specified byte array.

    \a data A byte array that contains the data.

    Will return a default constructed QMimeTypeName if the MIME type could not be determined.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn void QMimeTypeRegistry::insertServiceAction (
                                    const QServiceAction &serviceAction
                                );
    \brief Registers a new service action.

    This registration happens during the installation of an application.

    \a serviceAction The service action object that is being registered.
 */

// ------------------------------------------------------------------------------------------------


/*!
    \fn QList<QServiceActionName> QMimeTypeRegistry::serviceActions() const;
    \brief Returns the list of registered service actions.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QServiceAction QMimeTypeRegistry::findServiceAction (
                                              const QServiceActionName &serviceActionName
                                          );
    \brief Searches for the specified service action.

    \a serviceActionName The service action ID for which we need to perform the search.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn void QMimeTypeRegistry::removeServiceAction (
                                    const QServiceActionName &serviceActionName
                                );
    \brief Deregisters a service action.

    This deregistration happens during the deinstallation of an application.

    \a serviceActionName The ID of the service action object is being deregistered.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn bool QMimeTypeRegistry::userAlwaysSelectsApplication (
                                    const QServiceActionName &serviceActionName,
                                    const QMimeTypeName &mimeTypeName
                                ) const;
    \brief Returns if the user is always presented with a selection dialog for the action on the specified MIME type.

    \a serviceActionName Service action that the query is being performed on

    \a mimeTypeName MIME type that the quere is being performed on

    Always making the user choose the application for an action on a MIME type is for example
    used for the share action where the user picks out the share application e.g. the Twitter
    application that an item is supposed to be shared with. Another case is with image viewers
    for which the user did not want to specify a default.

    Returns false if there is only one application installed that is able to perform the
    service action on the specified MIME type.

    See also #US001, #US002.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn void QMimeTypeRegistry::setUserAlwaysSelectsApplication (
                                    const QServiceActionName &serviceActionName,
                                    const QMimeTypeName &mimeTypeName,
                                    const bool newSetting
                                );
    \brief Specifies if the user is always presented with a selection dialog for the action on the specified MIME type.

    \a serviceActionName Service action to which the setting is to be applied on.

    \a mimeTypeName MIME type to which the setting is to be applied on.

    \a newSetting The new setting

    Always making the user choose the application for an action on a MIME type is for example
    used for the share action where the user picks out the share application e.g. the Twitter
    application that an item is supposed to be shared with. Another case is with image viewers
    for which the user did not want to specify a default.

    During the start of an application it may check if it is the default handler for all of its
    MIME types. If it is currently not the default handler the application may start a dialog
    to offer itself as the default handler for its MIME types. If the user declines that UI
    needs a check box to select if the application should remember that decision.

    See also #US001, #US002.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn void QMimeTypeRegistry::registerApplication (
                                    const QApplicationId &applicationId,
                                    const QServiceActionName &serviceActionName,
                                    const QMimeTypeName &mimeTypeName
                                );
    \brief Registers an application's ability for a service action on a specific MIME type.

    This registration happens during the installation of an application.

    See also #US001, #US002, #US007, #US008

    Also creates entries the MIME type list, the file extension list, the service action list and the flag if the user always selects the application.

    \a applicationId The application ID for which we are trying to register

    \a serviceActionName The ID of the service action we are trying to register

    \a mimeTypeName The ID of the MIME type associated with the service action we are trying to register
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn void QMimeTypeRegistry::increaseApplicationPreference (
                                    const QApplicationId &applicationId,
                                    const QServiceActionName &serviceActionName,
                                    const QMimeTypeName &mimeTypeName
                                );
    \brief Increases the application's preference to handle a service action on a specific MIME type.

    \a applicationId The application ID for which we are trying to increase the preference

    \a serviceActionName The ID of the service action we are trying to increase the preference

    \a mimeTypeName The ID of the MIME type associated with the service action we are trying to increase the preference
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn void QMimeTypeRegistry::decreaseApplicationPreference (
                                    const QApplicationId &applicationId,
                                    const QServiceActionName &serviceActionName,
                                    const QMimeTypeName &mimeTypeName
                                );
    \brief Decreases the application's preference to handle a service action on a specific MIME type.

    \a applicationId The application ID for which we are trying to decrease the preference

    \a serviceActionName The ID of the service action we are trying to decrease the preference

    \a mimeTypeName The ID of the MIME type associated with the service action we are trying to decrease the preference
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn void QMimeTypeRegistry::unregisterApplication (
                                    const QApplicationId &applicationId
                                );
    \brief Unregisters all application's abilities for service actions on all MIME types.

    \a applicationId The application ID for which we are trying to unregister

    Also cleans up the MIME type list, the file extension list, the service action list and the flag if the user always selects the application.

    See also #US007
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QList<QPair<QApplicationId, QServiceActionName> > QMimeTypeRegistry::findApplications (
                                                                                 const QMimeTypeName &mimeTypeName
                                                                             ) const;
    \brief Searches which applications can handle the specified MIME type and what actions they can perform on it.

    \a mimeTypeName The MIME type ID for which we need to perform the search.

    The order in which the applications are returned reflects the user's preference.

    #US006, #US008, #US011, #US012
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QList<QApplicationId> QMimeTypeRegistry::findApplications (
                                                     const QServiceActionName &serviceActionName,
                                                     const QMimeTypeName &mimeTypeName
                                                 ) const;
    \brief Searches which applications can handle an acton on the specified MIME type.

    \a serviceActionName The service action for which we need to perform the search.

    \a mimeTypeName The MIME type ID for which we need to perform the search.

    The order in which the applications are returned reflects the user's preference.

    See also #US004, #US005, #US008, #US009, #US010
 */
