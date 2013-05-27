/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
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

#include "qserviceaction.h"

#include "qserviceaction_p.h"

// ------------------------------------------------------------------------------------------------

/*!
    \typedef QServiceActionName
    \brief ID of service actions on MIME types, e.g. "open", "edit", "share", "call", "message"

    A service action that is supposed to be applied on a specified MIME type, e.g. "view", "edit", "share-facebook". The default action ("") corrsponds to view and play.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \class QServiceAction
    \brief QServiceAction describes the behaviour and information about a specific action on a MIME type.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QServiceAction::QServiceAction();
    \brief Initializes the attributes with default values that indicate an invalid service action.
 */
QServiceAction::QServiceAction() :
        d_ptr(new QServiceActionPrivate(QServiceActionName(), QString(), QString()))
{}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QServiceAction::QServiceAction(const QServiceActionName &theName,
                                     const QString &theDisplayName,
                                     const QString &theIconUrl);
    \brief Initializes the attributes with the specified values
    \a theName The ID of the action
    \a theDisplayName The description of the action to be displayed on user interfaces
    \a theIconUrl The file name of an icon image that represents the action
 */
QServiceAction::QServiceAction(const QServiceActionName &theName,
                             const QString &theDisplayName,
                             const QString &theIconUrl) :
        d_ptr(new QServiceActionPrivate(theName, theDisplayName, theIconUrl))
{
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QServiceAction::QServiceAction(const QServiceAction &other);
    \brief Initializes the attributes with the data of another action.
    \a other The other action the data of which is copied
 */
QServiceAction::QServiceAction(const QServiceAction &other) :
        d_ptr(new QServiceActionPrivate(*other.d_ptr))
{}

// ------------------------------------------------------------------------------------------------

/*!
    \fn const QServiceAction &QServiceAction::operator=(const QServiceAction &other);
    \brief Assigns the data of another action.
    \a other The other action the data of which is assigned
 */
QServiceAction &QServiceAction::operator=(const QServiceAction &other)
{
    *d_ptr = *other.d_ptr;

    return *this;
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QServiceAction::~QServiceAction();
    \brief Frees the d_ptr.
 */
QServiceAction::~QServiceAction()
{}

// ------------------------------------------------------------------------------------------------

/*!
    \fn bool QServiceAction::operator==(const QServiceAction &other) const;
    \brief Tests for equality with another action
    \a other The other action that is to be compared with
    Returns if the other action is equal.
 */
bool QServiceAction::operator==(const QServiceAction &other) const
{
    return *d_ptr == *other.d_ptr;
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn bool QServiceAction::operator!=(const QServiceAction &other) const;
    \brief Tests for non-equality with another action
    \a other The other action that is to be compared with
    Returns if the other action is not equal.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn bool QServiceAction::isValid() const;
    \brief Checks if the object contains a valid action.
    Returns the result of the check.
 */
bool QServiceAction::isValid() const
{
    return !d_ptr->m_Name.isEmpty() &&
           !d_ptr->m_Text.isEmpty() &&
           !d_ptr->m_IconUrl.isEmpty();
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn const QServiceActionName &QServiceAction::name() const;
    \brief Returns the ID of the action.
 */
const QServiceActionName &QServiceAction::name() const
{
    return d_ptr->m_Name;
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QString QServiceAction::displayName() const
    \brief Returns a description of the action to be displayed on user interfaces.

    The returned text is return in English language. For other languages it is the caller's
    responsibility to get the text translated.
 */
QString QServiceAction::displayName() const
{
    return d_ptr->m_Text;
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QString QServiceAction::iconUrl() const;
    \brief Returns the file name of an icon image that represents the action.

    Returns an empty string if no icon file has been specified during the registration of the
    action.
 */
QString QServiceAction::iconUrl() const
{
    return d_ptr->m_IconUrl;
}
