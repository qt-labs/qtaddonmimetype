#include "declarativemimetype_p.h"

#include <QtCore/QDebug>

// ------------------------------------------------------------------------------------------------

DeclarativeMimeType::DeclarativeMimeType(QObject *theParent) :
        QObject(theParent),
        m_MimeType()
{}

// ------------------------------------------------------------------------------------------------

DeclarativeMimeType::DeclarativeMimeType(const QMimeType &other, QObject *theParent) :
        QObject(theParent),
        m_MimeType(other)
{}

// ------------------------------------------------------------------------------------------------

DeclarativeMimeType::~DeclarativeMimeType()
{
    //qDebug() << Q_FUNC_INFO << "name():" << name();
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeType::assign(DeclarativeMimeType *other)
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return;
    }

    m_MimeType = other->m_MimeType;
}

// ------------------------------------------------------------------------------------------------

bool DeclarativeMimeType::equals(DeclarativeMimeType *other) const
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return false;
    }

    return m_MimeType == other->m_MimeType;
}

// ------------------------------------------------------------------------------------------------

QMimeType DeclarativeMimeType::mimeType() const
{
    return m_MimeType;
}

// ------------------------------------------------------------------------------------------------

bool DeclarativeMimeType::isValid() const
{
    return m_MimeType.isValid();
}

// ------------------------------------------------------------------------------------------------

const QMimeTypeName &DeclarativeMimeType::name() const
{
    return m_MimeType.name();
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeType::setName(const QMimeTypeName &newName)
{
    m_MimeType = QMimeType(newName, m_MimeType.displayName(), m_MimeType.iconUrl(), m_MimeType.fileExtentions());
}

// ------------------------------------------------------------------------------------------------

const QString &DeclarativeMimeType::displayName() const
{
    return m_MimeType.displayName();
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeType::setDisplayName(const QString &newDisplayName)
{
    m_MimeType = QMimeType(m_MimeType.name(), newDisplayName, m_MimeType.iconUrl(), m_MimeType.fileExtentions());
}

// ------------------------------------------------------------------------------------------------

const QString &DeclarativeMimeType::iconUrl() const
{
    return m_MimeType.iconUrl();
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeType::setIconUrl(const QString &newIconUrl)
{
    m_MimeType = QMimeType(m_MimeType.name(), m_MimeType.displayName(), newIconUrl, m_MimeType.fileExtentions());
}

// ------------------------------------------------------------------------------------------------

QVariantList DeclarativeMimeType::fileExtentions() const
{
    QVariantList result;

    foreach (const QString &fileExtention, m_MimeType.fileExtentions()) {
        result << fileExtention;
    }

    return result;
}

// ------------------------------------------------------------------------------------------------

void DeclarativeMimeType::setFileExtentions(const QVariantList &newFileExtentions)
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
