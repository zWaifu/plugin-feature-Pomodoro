#ifndef POMODORO_H
#define POMODORO_H

#include <QObject>
#include <QSharedPointer>

#include <spdlog/logger.h>

#include "Pomodoro_global.h"
#include "IzWaifuFeaturePlugin.h"

class QQuickItem;
class QQmlComponent;

// FIXME: decouple UI and plugin. Extract UI related methods to a new class

class POMODORO_EXPORT Pomodoro : public QObject, public IzWaifuFeaturePlugin
{
    Q_OBJECT
    Q_INTERFACES(IzWaifuFeaturePlugin)
    Q_PLUGIN_METADATA(IID zWaifuFeaturePluginInterface_iid FILE "pomodoro.json")
public:
    Pomodoro();

    virtual void initialize(QSharedPointer<AzWaifuEngine> engine) override;

    virtual FeatureType featureType() override;
    virtual bool activate() override;
    virtual bool deactivate() override;
    virtual QString featureName() override;
    virtual QUuid featureId() override;

private:
    QUrl getResourceUrl(const QString &relativePath);
    void resetPomodoroState();
    void resetPomodoroUI();

    QSharedPointer<AzWaifuEngine> _engine;
    spdlog::logger *_logger;

    QQmlComponent *_pomodoroComponent;
    QQuickItem *_pomodoroQuickItem;

    static const char *_featureName;
    static const QUuid _featureId;
};

#endif // POMODORO_H
