#ifndef DECLARATIVE_SERVICE_ACTION_P_INCLUDED
#define DECLARATIVE_SERVICE_ACTION_P_INCLUDED

#include "serviceaction.h"

#include <QtDeclarative/qdeclarative.h>

#include <QtCore/QObject>

// ------------------------------------------------------------------------------------------------

class DeclarativeServiceAction : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name
               READ name
               WRITE setName)

    Q_PROPERTY(QString displayName
               READ displayName
               WRITE setDisplayName)

    Q_PROPERTY(QString iconUrl
               READ iconUrl
               WRITE setIconUrl)

    Q_PROPERTY(bool isValid
               READ isValid
               STORED false)

protected:
    // We keep this destructor with its default value of 0 protected since only
    // QDeclarativePrivate::QDeclarativeElement<T> needs it:
    DeclarativeServiceAction(QObject *theParent = 0);

public:
    // We don't allow theParent to have a default value of 0 because in all
    // likelyhood we want to force the caller to specify its QObject so the
    // object will get destroyed in the caller's destructor:
    DeclarativeServiceAction(const QServiceAction &other, QObject *theParent);

    ~DeclarativeServiceAction();

    Q_INVOKABLE void assign(DeclarativeServiceAction *other);
    Q_INVOKABLE bool equals(DeclarativeServiceAction *other) const;

    QServiceAction serviceAction() const;

    bool isValid() const;

    const QServiceActionName &name() const;
    void setName(const QServiceActionName &newName);
    QString displayName() const;
    void setDisplayName(const QString &newDisplayName);
    QString iconUrl() const;
    void setIconUrl(const QString &newIconUrl);

private:
    QServiceAction m_ServiceAction;
};

QML_DECLARE_TYPE(DeclarativeServiceAction)

#endif
