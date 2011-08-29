#include "declarativeserviceaction_p.h"

#include <QtCore/QDebug>

// ------------------------------------------------------------------------------------------------

DeclarativeServiceAction::DeclarativeServiceAction(QObject *theParent) :
        QObject(theParent),
        m_ServiceAction()
{}

// ------------------------------------------------------------------------------------------------

DeclarativeServiceAction::DeclarativeServiceAction(const QServiceAction &other, QObject *theParent) :
        QObject(theParent),
        m_ServiceAction(other)
{}

// ------------------------------------------------------------------------------------------------

DeclarativeServiceAction::~DeclarativeServiceAction()
{
    //qDebug() << Q_FUNC_INFO << "name():" << name();
}

// ------------------------------------------------------------------------------------------------

void DeclarativeServiceAction::assign(DeclarativeServiceAction *other)
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return;
    }

    m_ServiceAction = other->m_ServiceAction;
}

// ------------------------------------------------------------------------------------------------

bool DeclarativeServiceAction::equals(DeclarativeServiceAction *other) const
{
    if (other == 0) {
        qWarning() << Q_FUNC_INFO << "other:" << other;
        return false;
    }

    return m_ServiceAction == other->m_ServiceAction;
}

// ------------------------------------------------------------------------------------------------

QServiceAction DeclarativeServiceAction::serviceAction() const
{
    return m_ServiceAction;
}

// ------------------------------------------------------------------------------------------------

bool DeclarativeServiceAction::isValid() const
{
    return m_ServiceAction.isValid();
}

// ------------------------------------------------------------------------------------------------

const QServiceActionName &DeclarativeServiceAction::name() const
{
    return m_ServiceAction.name();
}

// ------------------------------------------------------------------------------------------------

void DeclarativeServiceAction::setName(const QServiceActionName &newName)
{
    m_ServiceAction = QServiceAction(newName, m_ServiceAction.displayName(), m_ServiceAction.iconUrl());
}

// ------------------------------------------------------------------------------------------------

QString DeclarativeServiceAction::displayName() const
{
    return m_ServiceAction.displayName();
}

// ------------------------------------------------------------------------------------------------

void DeclarativeServiceAction::setDisplayName(const QString &newDisplayName)
{
    m_ServiceAction = QServiceAction(m_ServiceAction.name(), newDisplayName, m_ServiceAction.iconUrl());
}

// ------------------------------------------------------------------------------------------------

QString DeclarativeServiceAction::iconUrl() const
{
    return m_ServiceAction.iconUrl();
}

// ------------------------------------------------------------------------------------------------

void DeclarativeServiceAction::setIconUrl(const QString &newIconUrl)
{
    m_ServiceAction = QServiceAction(m_ServiceAction.name(), m_ServiceAction.displayName(), newIconUrl);
}
