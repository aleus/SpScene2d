#include "CircleVisualObject.h"
#include "Sp/Scene2dTypes.h"
#include "qnamespace.h"
#include <Scene2dLayers/PainterScene2dLayer.h>

#include <QPainter>

namespace sp
{

CircleVisualObject::CircleVisualObject()
    // Debug!!! Для отладки. Нужно передавать через параметры
    : _center{.x = 95, .y = 95}
    , _radius(30)
{
}

void CircleVisualObject::paint(Scene2dLayer & scene2dLayer) const
{
    // TODO Здесь нельзя использовать dynamic_cast из-за просадки производительности.
    // Нужно попробовать visitor извне
    auto & painterScene2dLayer = static_cast<PainterScene2dLayer &>(scene2dLayer);

    QPainter * painter = painterScene2dLayer.painter();
    Q_ASSERT(painter != nullptr);

    QBrush brush(Qt::darkYellow);

    painter->setBrush(brush);
    painter->drawEllipse(*reinterpret_cast<const QPointF *>(&_center), _radius, _radius);
}

Rect2dF CircleVisualObject::boundingBox() const
{
    sp::Scene2dFloat width = 2 * _radius;
    return {.left = _center.x,
            .top = _center.y,
            .width = width,
            .height = width};
}

} // namespace sp
