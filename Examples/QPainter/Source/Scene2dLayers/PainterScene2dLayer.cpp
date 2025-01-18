#include "PainterScene2dLayer.h"
#include "QuickPainterScene2dLayer.h"
#include "qnamespace.h"

#include <QPainter>

namespace sp
{

void PainterScene2dLayer::paint(QPainter * painter)
{
    Q_ASSERT(painter);
    Q_ASSERT(!_painter);

    _painter = painter;

    auto size = PainterScene2dLayer::size();
    _painter->setBackground(Qt::transparent);
    _painter->eraseRect(0, 0, size.width(), size.height());

    // Debug!!! Проверяем масштабирование сцены
    _painter->setTransform(
        QTransform::fromTranslate(camera().translation().x, camera().translation().y) *
        QTransform::fromScale(camera().scale().x, camera().scale().y));

    for (const auto & visualObject : visualObjects()) {
        visualObject->paint(*this);
    }

    _painter = nullptr;
}

void PainterScene2dLayer::setScene2dLayerItem(QuickPainterScene2dLayer * scene2dLayerItem)
{
    _scene2dLayerItem = scene2dLayerItem;
}

QSizeF PainterScene2dLayer::size() const
{
    Q_ASSERT(_scene2dLayerItem);
    return _scene2dLayerItem->size();
}

void PainterScene2dLayer::update()
{
    if (_scene2dLayerItem) {
        _scene2dLayerItem->update();
    }
}

} // namespace sp
