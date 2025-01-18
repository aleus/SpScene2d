#include "QuickScene2d.h"
#include "Scene2dLayers/PainterScene2dLayer.h"
#include "Scene2dLayers/QuickPainterScene2dLayer.h"
#include "qqmlcomponent.h"

#include <QQmlComponent>
#include <QQmlEngine>
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

qreal QuickScene2d::scale() const
{
    // Debug!!! Отладочное масштабирование по обоим осям сразау.
    return _scene2d->camera().scale().x;
}

void QuickScene2d::setScale(qreal scale)
{
    _scene2d->camera().setScale({scale, scale});
    _scene2d->update();

    emit scaleChanged();
}

QPointF QuickScene2d::translation() const
{
    const auto & translation_ = _scene2d->camera().translation();
    return {translation_.x, translation_.y};
}

void QuickScene2d::setTranslation(const QPointF & translation)
{
    _scene2d->camera().setTranslation({translation.x(), translation.y()});
    _scene2d->update();

    emit translationChanged();
}

void QuickScene2d::componentComplete()
{
    QQuickItem::componentComplete();

    _completed = true;

    if (_scene2d && !_scene2d->scene2dLayers().empty() &&
        size().width() > 0 && size().height() > 0)
    {
        _scene2d->update();
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

void QuickScene2d::updateSize()
{
    _scene2d->setSize({static_cast<int>(size().width()), static_cast<int>(size().height())});

    if (_completed) {
        _scene2d->update();
    }
}

void QuickScene2d::onWidthChanged()
{
    if (_scene2d->size().width != static_cast<int>(size().width())) {
        updateSize();
    }
}

void QuickScene2d::onHeightChanged()
{
    if (_scene2d->size().height != static_cast<int>(size().height())) {
        updateSize();
    }
}

} // namespace sp
