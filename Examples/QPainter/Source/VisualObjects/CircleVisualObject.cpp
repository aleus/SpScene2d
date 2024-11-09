#include "CircleVisualObject.h"
#include "PainterScene2dLayer.h"
#include "qnamespace.h"

#include <QPainter>

namespace sp
{

CircleVisualObject::CircleVisualObject()
{
}

void CircleVisualObject::paint(Scene2dLayer & scene2dLayer) const
{
    auto & painterScene2dLayer = static_cast<PainterScene2dLayer &>(scene2dLayer);

    QPainter * painter = painterScene2dLayer.painter();
    Q_ASSERT(painter != nullptr);

    QBrush brush(Qt::darkYellow);

    const auto radius = 30;
    const double borderWidth = 80;
    painter->setBrush(brush);
    painter->drawEllipse(QRectF(borderWidth, borderWidth, radius, radius));
}

} // namespace sp
