#pragma once

#include <Sp/IRenderFilter.h>

namespace sp
{

class SceneClipRenderFilter final : public IRenderFilter
{
public:
    SceneClipRenderFilter() = default;

    void pass(const IVisualObjectsContainer & visualObjects,
              IVisualObjectsContainer & visualObjectsDerivative,
              const RenderFilterParams & renderFilterParams) const override;
};

} // namespace sp
