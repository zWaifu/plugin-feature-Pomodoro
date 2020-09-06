#include <QFile>
#include <QDir>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlEngine>

#include "AzWaifuEngine.h"
#include "Pomodoro.h"

const QUuid Pomodoro::_featureId = QUuid("0330616c-e04a-4184-b20a-07ae86f14bcc");

const char *Pomodoro::_featureName = "Pomodoro Clock";

Pomodoro::Pomodoro() :
    _logger(nullptr),
    _pomodoroComponent(nullptr),
    _pomodoroQuickItem(nullptr)
{
}

void Pomodoro::initialize(QSharedPointer<AzWaifuEngine> engine)
{
    _engine = engine;
    _logger = engine->logger();

    _logger->debug("initializing Pomodoro...");
    QQmlComponent* pomodoroComponent = new QQmlComponent(_engine->qmlEngine(), getResourceUrl("qml/Pomodoro.qml"));
    if (!pomodoroComponent) {
        _logger->error("failed to create Pomodoro QML component");
        // FIXME: throw error
        return;
    }

    QQuickItem* pomodoroItem = qobject_cast<QQuickItem*>(pomodoroComponent->create());
    if (!pomodoroItem) {
        _logger->error("failed to create Pomodoro QQuickItem");
        // FIXME: throw error
        return;
    }

    _engine->qmlEngine()->setObjectOwnership(pomodoroItem, QQmlEngine::CppOwnership);
    pomodoroItem->setParent(_engine->qmlEngine());

    _pomodoroComponent = pomodoroComponent;
    _pomodoroQuickItem = pomodoroItem;
}

IzWaifuFeaturePlugin::FeatureType Pomodoro::featureType()
{
    return IzWaifuFeaturePlugin::FeatureType::ActiveWithGui;
}

bool Pomodoro::activate()
{
    _logger->debug("activating Pomodoro...");
    QQuickItem* elementContainer = _engine->rootElement();
    _pomodoroQuickItem->setParentItem(elementContainer);
    _logger->debug("Pomodoro activated");
    return true;
}

bool Pomodoro::deactivate()
{
    _logger->debug("deactivating Pomodoro...");
    _pomodoroQuickItem->setParentItem(nullptr);
    resetPomodoroUI();
    _logger->debug("Pomodoro deactivated");
    return true;
}

QString Pomodoro::featureName()
{
    return tr(_featureName);
}

QUuid Pomodoro::featureId()
{
    return _featureId;
}

QUrl Pomodoro::getResourceUrl(const QString &relativePath)
{
    return QUrl("qrc:///features/Pomodoro/" + relativePath);
}

void Pomodoro::resetPomodoroState()
{
    // FIXME: impl
    resetPomodoroUI();
}

void Pomodoro::resetPomodoroUI()
{
    // FIXME: impl
}
