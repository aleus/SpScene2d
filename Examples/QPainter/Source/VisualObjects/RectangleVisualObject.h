#pragma once

#include <QRectF>
#include <Sp/IVisualObject.h>

namespace sp
{

class RectangleVisualObject final : public IVisualObject
{
public:
    RectangleVisualObject();

    void paint(Scene2dLayer & scene2dLayer) const override;
    Rect2dF boundingBox() const override;
    Rect2d boundingBoxPx() const override;
};

} // namespace sp
