#ifndef SERVICE_ACTION_H_INCLUDED
#define SERVICE_ACTION_H_INCLUDED

#include <QtCore/QScopedPointer>

class QServiceActionPrivate;

class QString;

// ------------------------------------------------------------------------------------------------

// A temporary solution in case the type changes until the final release:
typedef QString QServiceActionName;

// ------------------------------------------------------------------------------------------------

class QServiceAction
{
public:
    QServiceAction();
    QServiceAction(const QServiceActionName &theName,
                   const QString &theDisplayName,
                   const QString &theIconUrl);
    QServiceAction(const QServiceAction &other);
    QServiceAction &operator=(const QServiceAction &other);
    ~QServiceAction();

    bool operator==(const QServiceAction &other) const;

    inline bool operator!=(const QServiceAction &other) const
    {
        return !operator==(other);
    }

    bool isValid() const;

    const QServiceActionName &name() const;
    QString displayName() const;
    QString iconUrl() const;

private:
    QScopedPointer<QServiceActionPrivate> d_ptr;
};

#endif
