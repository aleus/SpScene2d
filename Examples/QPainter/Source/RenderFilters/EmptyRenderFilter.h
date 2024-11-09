#pragma once

#include <Sp/IRenderFilter.h>

namespace sp
{

class EmptyRenderFilter final : public IRenderFilter
{
public:
    EmptyRenderFilter() = default;

    void pass(const IVisualObjectsContainer & visualObjects,
              IVisualObjectsContainer & visualObjectsDerivative,
              const RenderFilterParams & renderFilterParams) const override;
};

} // namespace sp
