#include "QuickScene2d.h"
#include "QuickPainterScene2dLayer.h"
#include "qqmlcomponent.h"

#include <QQmlComponent>
#include <QQmlEngine>

using namespace sp;

QuickScene2d::QuickScene2d()
{
}

void QuickScene2d::componentComplete()
{
    auto * layerComponent = new QQmlComponent(qmlEngine(this), ":/PainterScene2dLayer.qml");

    auto createLayer = [layerComponent, this]() {
        if (layerComponent->isError()) [[unlikely]] {
            Q_ASSERT_X(false, "QuickScene2d", "Can't load component of PainterScene2dLayer.qml");
        } else {
            QVariantMap properties{{"parent", QVariant::fromValue(this)}};
            auto * object = layerComponent->createWithInitialProperties(properties);
            auto * quickPainterScene2dLayer = qobject_cast<QuickPainterScene2dLayer *>(object);

            if (!quickPainterScene2dLayer) [[unlikely]] {
                Q_ASSERT_X(quickPainterScene2dLayer, "QuickScene2d", "Can't create object from PainterScene2dLayer.qml");
            }
        }
    };

    if (layerComponent->isReady()) {
        createLayer();
    } else {
        connect(layerComponent, &QQmlComponent::statusChanged,
                this, createLayer);
    }

    QQuickItem::componentComplete();
}
