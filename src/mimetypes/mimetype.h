#ifndef MIME_TYPE_H_INCLUDED
#define MIME_TYPE_H_INCLUDED

#include <QtCore/QScopedPointer>

class QMimeTypePrivate;

class QString;

template<typename T>
class QList;

// ------------------------------------------------------------------------------------------------

// A temporary solution in case the type changes until the final release:
typedef QString QMimeTypeName;

// ------------------------------------------------------------------------------------------------

class QMimeType
{
public:
    QMimeType();
    QMimeType(const QMimeTypeName &theName,
              const QString &theDisplayName,
              const QString &theIconUrl,
              const QList<QString> &theFileExtentions);
    QMimeType(const QMimeType &other);
    QMimeType &operator=(const QMimeType &other);
    ~QMimeType();

    bool operator==(const QMimeType &other) const;

    inline bool operator!=(const QMimeType &other) const
    {
        return !operator==(other);
    }

    bool isValid() const;

    const QMimeTypeName &name() const;
    const QString &displayName() const;
    const QString &iconUrl() const;
    const QList<QString> &fileExtentions() const;

private:
    QScopedPointer<QMimeTypePrivate> d_ptr;
};

#endif
