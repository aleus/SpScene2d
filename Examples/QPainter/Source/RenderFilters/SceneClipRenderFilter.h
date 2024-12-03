#pragma once

#include <Sp/IRenderFilter.h>

namespace sp
{

class SceneClipRenderFilter final : public IRenderFilter
{
public:
    SceneClipRenderFilter() = default;

    void pass(IVisualObjectsCContainer & visualObjects,
              const RenderFilterParams & renderFilterParams) const override;
};

} // namespace sp
