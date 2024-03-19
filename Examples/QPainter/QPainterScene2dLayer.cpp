#include "QPainterScene2dLayer.h"
#include "QPainterScene2dLayerItem.h"

#include <QPainter>

using namespace sp;

void QPainterScene2dLayer::setScene2dLayerItem(QPainterScene2dLayerItem * scene2dLayerItem)
{
    _scene2dLayerItem = scene2dLayerItem;
}

void QPainterScene2dLayer::paint(QPainter * painter)
{
    Q_ASSERT(_scene2dLayerItem);
    Q_ASSERT(_painter);

    _painter = painter;

    auto [width, height] = size();
    painter->eraseRect(0, 0, width, height);

    for (const auto & visualObject : _visualObjects)
    {
        visualObject->paint(*this);
    }

    _painter = nullptr;
}

QSizeF QPainterScene2dLayer::size()
{
    Q_ASSERT(_scene2dLayerItem);
    return _scene2dLayerItem->size();
}

void QPainterScene2dLayer::update()
{
    Q_ASSERT(_scene2dLayerItem);
    _scene2dLayerItem->update();
}
