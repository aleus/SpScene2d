#pragma once

#include <Sp/IRenderFilter.h>

namespace sp
{

class GeneralizationRenderFilter final : public IRenderFilter
{
public:
    GeneralizationRenderFilter() = default;

    void pass(IVisualObjectsContainer & visualObjects,
              const RenderFilterParams & renderFilterParams) const override;
};

} // namespace sp
