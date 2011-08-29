#ifndef SERVICE_ACTION_P_H_INCLUDED
#define SERVICE_ACTION_P_H_INCLUDED

#include "serviceaction.h"

#include <QtCore/QString>

// ------------------------------------------------------------------------------------------------

struct QServiceActionPrivate
{
    QServiceActionPrivate(const QServiceActionName &theName,
                          const QString &theDisplayName,
                          const QString &theIconUrl) :
            m_Name(theName),
            m_Text(theDisplayName),
            m_IconUrl(theIconUrl)
    {}

    bool operator==(const QServiceActionPrivate &other) const
    {
        return m_Name == other.m_Name &&
               m_Text == other.m_Text &&
               m_IconUrl == other.m_IconUrl;
    }

    QServiceActionName m_Name;
    QString m_Text;
    QString m_IconUrl;
};

#endif
