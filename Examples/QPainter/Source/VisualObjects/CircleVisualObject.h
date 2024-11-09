#pragma once

#include <Sp/IVisualObject.h>

namespace sp
{

class CircleVisualObject final : public IVisualObject
{
public:
    CircleVisualObject();

    void paint(Scene2dLayer & scene2dLayer) const override;
};

} // namespace sp
