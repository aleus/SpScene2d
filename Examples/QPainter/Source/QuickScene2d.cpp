#include "QuickScene2d.h"
#include "Scene2dLayers/PainterScene2dLayer.h"
#include "Scene2dLayers/QuickPainterScene2dLayer.h"
#include "qqmlcomponent.h"

#include <QQmlComponent>
#include <QQmlEngine>
#include <QDebug> // Debug!!!
#include <qquickitem.h>

namespace sp
{

QuickScene2d::QuickScene2d()
{
    connect(this, &QQuickItem::widthChanged, this, &QuickScene2d::onWidthChanged);
    connect(this, &QQuickItem::heightChanged, this, &QuickScene2d::onHeightChanged);
}

void QuickScene2d::setScene2d(Scene2d * scene2d)
{
    if (_scene2d != scene2d) {
        _scene2d = scene2d;

        if (_scene2d) {
            createLayers();
        }

        emit scene2dChanged();
    }
}

void QuickScene2d::createLayers()
{
    Q_ASSERT(_scene2d);

    auto * layerComponent = new QQmlComponent(qmlEngine(this), ":/PainterScene2dLayer.qml");

    auto createItems = [layerComponent, this]() {
        if (layerComponent->isError()) [[unlikely]] {
            Q_ASSERT_X(false, "QuickScene2d", "Can't load component of PainterScene2dLayer.qml");
        } else {
            for (const auto & scene2dLayer : _scene2d->scene2dLayers()) {
                // TODO Сейчас класс знает о соответствии Quick-элемента и типа слоя. Возможно, стоит вынести.
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

void QuickScene2d::onWidthChanged()
{
    // Debug!!! Обновление должно проходить лениво
    _scene2d->update();
}

void QuickScene2d::onHeightChanged()
{
    // Debug!!! Обновление должно проходить лениво
    _scene2d->update();
}

} // namespace sp
