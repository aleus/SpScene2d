#pragma once

#include <Sp/IVisualObject.h>

namespace sp
{

class RectangleVisualObject final : public IVisualObject
{
public:
    RectangleVisualObject();

    void paint(Scene2dLayer & scene2dLayer) const override;
};

} // namespace sp
