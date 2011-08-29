#ifndef DECLARATIVE_MIME_TYPE_P_H_INCLUDED
#define DECLARATIVE_MIME_TYPE_P_H_INCLUDED

#include "mimetype.h"

#include <QtDeclarative/qdeclarative.h>

#include <QtCore/QObject>

// ------------------------------------------------------------------------------------------------

class DeclarativeMimeType : public QObject
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

    Q_PROPERTY(QVariantList fileExtentions
               READ fileExtentions
               WRITE setFileExtentions
               STORED false)

    Q_PROPERTY(bool isValid
               READ isValid
               STORED false)

protected:
    // We keep this destructor with its default value of 0 protected since only
    // QDeclarativePrivate::QDeclarativeElement<T> needs it:
    DeclarativeMimeType(QObject *theParent = 0);

public:
    // We don't allow theParent to have a default value of 0 because in all
    // likelyhood we want to force the caller to specify its QObject so the
    // object will get destroyed in the caller's destructor:
    DeclarativeMimeType(const QMimeType &other, QObject *theParent);

    ~DeclarativeMimeType();

    Q_INVOKABLE void assign(DeclarativeMimeType *other);
    Q_INVOKABLE bool equals(DeclarativeMimeType *other) const;

    QMimeType mimeType() const;

    bool isValid() const;

    const QMimeTypeName &name() const;
    void setName(const QMimeTypeName &newName);
    const QString &displayName() const;
    void setDisplayName(const QString &newDisplayName);
    const QString &iconUrl() const;
    void setIconUrl(const QString &newIconUrl);
    QVariantList fileExtentions() const;
    void setFileExtentions(const QVariantList &newFileExtentions);

private:
    QMimeType m_MimeType;
};

QML_DECLARE_TYPE(DeclarativeMimeType)

#endif
