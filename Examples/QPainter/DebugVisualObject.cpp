#include "DebugVisualObject.h"
#include "PainterScene2dLayer.h"
#include "qsize.h"

#include <QPainter>

using namespace sp;

DebugVisualObject::DebugVisualObject()
{
}

void DebugVisualObject::paint(Scene2dLayer & scene2dLayer) const
{
    auto & painterScene2dLayer = static_cast<PainterScene2dLayer &>(scene2dLayer);

    QPainter * painter = painterScene2dLayer.painter();
    Q_ASSERT(painter != nullptr);

    QBrush brush(Qt::darkGreen);

    const auto size = painterScene2dLayer.size();
    const double borderWidth = 50;
    painter->fillRect(borderWidth,
                      borderWidth,
                      size.width() - 2 * borderWidth,
                      size.height() - 2 * borderWidth,
                      brush);
}
