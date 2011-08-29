#ifndef MIME_TYPE_P_H_INCLUDED
#define MIME_TYPE_P_H_INCLUDED

#include "mimetype.h"

#include <QtCore/QList>
#include <QtCore/QString>

// ------------------------------------------------------------------------------------------------

struct QMimeTypePrivate
{
    QMimeTypePrivate(const QMimeTypeName &theName,
                     const QString &theDisplayName,
                     const QString &theIconUrl,
                     const QList<QString> &theFileExtentions) :
            m_Name(theName),
            m_DisplayName(theDisplayName),
            m_IconUrl(theIconUrl),
            m_FileExtentions(theFileExtentions)
    {}

    bool operator==(const QMimeTypePrivate &other) const
    {
        return m_Name == other.m_Name &&
               m_DisplayName == other.m_DisplayName &&
               m_IconUrl == other.m_IconUrl &&
               m_FileExtentions == other.m_FileExtentions;
    }

    QMimeTypeName m_Name;
    QString m_DisplayName;
    QString m_IconUrl;
    QList<QString> m_FileExtentions;
};

#endif
