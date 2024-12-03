#include "RectangleVisualObject.h"
#include "Sp/Scene2dTypes.h"

#include <Scene2dLayers/PainterScene2dLayer.h>

#include <QPainter>

#include <limits>

namespace sp
{

RectangleVisualObject::RectangleVisualObject()
{
}

void RectangleVisualObject::paint(Scene2dLayer & scene2dLayer) const
{
    auto & painterScene2dLayer = static_cast<PainterScene2dLayer &>(scene2dLayer);

    QPainter * painter = painterScene2dLayer.painter();
    Q_ASSERT(painter != nullptr);

    QBrush brush(Qt::darkGreen);

    // Debug!!! Отладочные размеры, привязанные к размеру сцены
    const auto size = painterScene2dLayer.size();
    const double borderWidth = 50;
    painter->fillRect(borderWidth,
                      borderWidth,
                      size.width() - 2 * borderWidth,
                      size.height() - 2 * borderWidth,
                      brush);
}

Rect2dF RectangleVisualObject::boundingBox() const
{
    // Debug!!! boundingBox на всю сцену
    return {
        .left = 0.5 * std::numeric_limits<Scene2dFloat>::lowest(),
        .top = 0.5 * std::numeric_limits<Scene2dFloat>::lowest(),
        .width = std::numeric_limits<Scene2dFloat>::max(),
        .height = std::numeric_limits<Scene2dFloat>::max(),
    };
}

Rect2d RectangleVisualObject::boundingBoxPx() const
{
    // Debug!!! boundingBox на всю сцену
    return {
        .left = std::numeric_limits<Scene2dInt >::lowest(),
        .top = std::numeric_limits<Scene2dInt>::lowest(),
        .width = std::numeric_limits<Scene2dInt>::max(),
        .height = std::numeric_limits<Scene2dInt>::max(),
    };
}

} // namespace sp
