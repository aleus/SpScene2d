#pragma once

#include <Sp/IVisualObject.h>

namespace sp
{

class DebugVisualObject final : public IVisualObject
{
public:
    DebugVisualObject();

    void paint(Scene2dLayer & scene2dLayer) const override;
};

} // namespace sp
