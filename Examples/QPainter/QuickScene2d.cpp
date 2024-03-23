#include "QuickScene2d.h"
#include "PainterScene2dLayer.h"
#include "QuickPainterScene2dLayer.h"
#include "qqmlcomponent.h"

#include <QQmlComponent>
#include <QQmlEngine>

namespace sp {

QuickScene2d::QuickScene2d() {
}

void QuickScene2d::setScene2d(Scene2d * scene2d) {
    if (_scene2d != scene2d) {
        _scene2d = scene2d;

        if (_scene2d) {
            createLayers();
        }

        emit scene2dChanged();
    }
}

void QuickScene2d::createLayers() {
    Q_ASSERT(_scene2d);

    auto * layerComponent = new QQmlComponent(qmlEngine(this), ":/PainterScene2dLayer.qml");

    auto createItems = [layerComponent, this]() {
        if (layerComponent->isError()) [[unlikely]] {
            Q_ASSERT_X(false, "QuickScene2d", "Can't load component of PainterScene2dLayer.qml");
        } else {
            for (const auto & scene2dLayer : _scene2d->scene2dLayers()) {
                if (auto * painterScene2dLayer = dynamic_cast<PainterScene2dLayer *>(scene2dLayer.get());
                    painterScene2dLayer)
                {
                    QVariantMap properties{
                        {"parent", QVariant::fromValue(this)},
                        {"scene2dLayer", QVariant::fromValue(painterScene2dLayer)}};
                    auto * object = layerComponent->createWithInitialProperties(properties);
                    auto * quickPainterScene2dLayer = qobject_cast<QuickPainterScene2dLayer *>(object);

                    if (!quickPainterScene2dLayer) [[unlikely]] {
                        qCritical() << layerComponent->errorString();
                        Q_ASSERT_X(quickPainterScene2dLayer, "QuickScene2d", "Can't create object from PainterScene2dLayer.qml");
                    }
                }
            }
        }
    };

    if (layerComponent->isReady()) {
        createItems();
    } else {
        connect(layerComponent, &QQmlComponent::statusChanged,
                this, createItems);
    }
}

} // namespace sp
