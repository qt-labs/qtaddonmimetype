#include "qmimetype.h"

#include "qmimetype_p.h"

// ------------------------------------------------------------------------------------------------

/*!
    \typedef QMimeTypeName
    \brief ID of MIME types, e.g. "text/plain" or "text/html"
 */

// ------------------------------------------------------------------------------------------------

/*!
    \class QMimeType
    \brief QMimeType describes the behaviour and information about a specific MIME type.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn QMimeType::QMimeType()
    \brief Initializes the attributes with default values that indicate an invalid MIME type.
 */
QMimeType::QMimeType() :
        d_ptr(new QMimeTypePrivate(QMimeTypeName(), QString(), QString(), QList<QString>()))
{}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QMimeType::QMimeType(const QMimeTypeName &theName,
                             const QString &theDisplayName,
                             const QString &theIconUrl,
                             const QList<QString> &theFileExtentions);
    \brief Initializes the attributes with the specified values.
    \a theName The ID of the action
    \a theDisplayName The description of the action to be displayed on user interfaces
    \a theIconUrl The file name of an icon image that represents the action
    \a theFileExtentions The file extentions that are known to contain data of the MIME type
 */
QMimeType::QMimeType(const QMimeTypeName &theName,
                     const QString &theDisplayName,
                     const QString &theIconUrl,
                     const QList<QString> &theFileExtentions) :
        d_ptr(new QMimeTypePrivate(theName, theDisplayName, theIconUrl, theFileExtentions))
{}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QMimeType::QMimeType(const QMimeType &other);
    \brief Initializes the attributes with the data of another MIME type.
    \a other The other MIME type the data of which is copied
 */
QMimeType::QMimeType(const QMimeType &other) :
        d_ptr(new QMimeTypePrivate(*other.d_ptr))
{}

// ------------------------------------------------------------------------------------------------

/*!
    \fn const QMimeType &QMimeType::operator=(const QMimeType &other);
    \brief Assigns the data of another MIME type.
    \a other The other action the data of which is assigned
 */
QMimeType &QMimeType::operator=(const QMimeType &other)
{
    *d_ptr = *other.d_ptr;

    return *this;
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QMimeType::~QMimeType();
    \brief Frees the d_ptr.
 */
QMimeType::~QMimeType()
{}

// ------------------------------------------------------------------------------------------------

/*!
    \fn bool QMimeType::operator==(const QMimeType &other) const;
    \brief Tests for equality with another MIME type
    \a other The other MIME type that is to be compared with
    Returns if the other MIME type not equal.
 */
bool QMimeType::operator==(const QMimeType &other) const
{
    return *d_ptr == *other.d_ptr;
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn bool QMimeType::operator!=(const QMimeType &other) const;
    \brief Tests for non-equality with another MIME type
    \a other The other MIME type that is to be compared with
    Returns if the other MIME type is not equal.
 */

// ------------------------------------------------------------------------------------------------

/*!
    \fn bool QMimeType::isValid() const;
    \brief Checks if the object contains a valid MIME type.
    Returns the result of the check.
 */
bool QMimeType::isValid() const
{
    return !d_ptr->m_Name.isEmpty() &&
           !d_ptr->m_DisplayName.isEmpty() &&
           !d_ptr->m_IconUrl.isEmpty() &&
           !d_ptr->m_FileExtentions.isEmpty();
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn const QMimeTypeName &QMimeType::name() const;
    \brief Returns the ID of the MIME type.
 */
const QMimeTypeName &QMimeType::name() const
{
    return d_ptr->m_Name;
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QString QMimeType::displayName() const;
    \brief Returns a description of the MIME type to be displayed on user interfaces.

    The returned text is return in English language. For other languages it is the caller's
    responsibility to get the text translated.
 */
const QString &QMimeType::displayName() const
{
    return d_ptr->m_DisplayName;
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QString QMimeType::iconUrl() const;
    \brief Returns the file name of an icon image that represents the MIME type.

    Returns an empty string if no icon file has been specified during the registration of the
    MIME type.
 */
const QString &QMimeType::iconUrl() const
{
    return d_ptr->m_IconUrl;
}

// ------------------------------------------------------------------------------------------------

/*!
    \fn QList<QString> QMimeType::fileExtentions() const;
    \brief Returns the file extentions that are known to contain data of the MIME type.
 */
const QList<QString> &QMimeType::fileExtentions() const
{
    return d_ptr->m_FileExtentions;
}