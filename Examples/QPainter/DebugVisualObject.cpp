#include "DebugVisualObject.h"
#include "QPainterScene2dLayer.h"

#include <QPainter>

using namespace sp;

DebugVisualObject::DebugVisualObject()
{
}

void DebugVisualObject::paint(Scene2dLayer & scene2dLayer) const
{
    auto & painterScene2dLayer = static_cast<QPainterScene2dLayer &>(scene2dLayer);
    QPainter * painter = painterScene2dLayer.painter();
    Q_ASSERT(painter != nullptr);

    QBrush brush(Qt::darkGreen);

    const double width = painterScene2dLayer.width();
    const double height = painterScene2dLayer.height();
    const double borderWidth = 50;
    painter->fillRect(borderWidth, borderWidth, width - 2 * borderWidth, height - 2 * borderWidth, brush);
}
