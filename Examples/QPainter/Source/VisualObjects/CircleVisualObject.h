#pragma once

#include "Sp/Scene2dTypes.h"
#include <Sp/IVisualObject.h>

namespace sp
{

class CircleVisualObject final : public IVisualObject
{
public:
    CircleVisualObject();

    void paint(Scene2dLayer & scene2dLayer) const override;
    Rect2dF boundingBox() const override;

private:
    sp::Point2dF _center;
    sp::Scene2dFloat _radius;
};

} // namespace sp
