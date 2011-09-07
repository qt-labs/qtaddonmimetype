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
