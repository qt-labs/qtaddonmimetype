#include "qdeclarativeserviceaction_p.h"

#include <QtCore/QDebug>

// ------------------------------------------------------------------------------------------------

QDeclarativeServiceAction::QDeclarativeServiceAction(QObject *theParent) :
        QObject(theParent),
        m_ServiceAction()
{}

// ------------------------------------------------------------------------------------------------

QDeclarativeServiceAction::QDeclarativeServiceAction(const QServiceAction &other, QObject *theParent) :
        QObject(theParent),
        m_ServiceAction(other)
{}

// ------------------------------------------------------------------------------------------------

QDeclarativeServiceAction::~QDeclarativeServiceAction()
{
    //qDebug() << Q_FUNC_INFO << "name():" << name();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeServiceAction::assign(QDeclarativeServiceAction *other)
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return;
    }

    m_ServiceAction = other->m_ServiceAction;
}

// ------------------------------------------------------------------------------------------------

bool QDeclarativeServiceAction::equals(QDeclarativeServiceAction *other) const
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return false;
    }

    return m_ServiceAction == other->m_ServiceAction;
}

// ------------------------------------------------------------------------------------------------

QServiceAction QDeclarativeServiceAction::serviceAction() const
{
    return m_ServiceAction;
}

// ------------------------------------------------------------------------------------------------

bool QDeclarativeServiceAction::isValid() const
{
    return m_ServiceAction.isValid();
}

// ------------------------------------------------------------------------------------------------

const QServiceActionName &QDeclarativeServiceAction::name() const
{
    return m_ServiceAction.name();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeServiceAction::setName(const QServiceActionName &newName)
{
    m_ServiceAction = QServiceAction(newName, m_ServiceAction.displayName(), m_ServiceAction.iconUrl());
}

// ------------------------------------------------------------------------------------------------

QString QDeclarativeServiceAction::displayName() const
{
    return m_ServiceAction.displayName();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeServiceAction::setDisplayName(const QString &newDisplayName)
{
    m_ServiceAction = QServiceAction(m_ServiceAction.name(), newDisplayName, m_ServiceAction.iconUrl());
}

// ------------------------------------------------------------------------------------------------

QString QDeclarativeServiceAction::iconUrl() const
{
    return m_ServiceAction.iconUrl();
}

// ------------------------------------------------------------------------------------------------

void QDeclarativeServiceAction::setIconUrl(const QString &newIconUrl)
{
    m_ServiceAction = QServiceAction(m_ServiceAction.name(), m_ServiceAction.displayName(), newIconUrl);
}
