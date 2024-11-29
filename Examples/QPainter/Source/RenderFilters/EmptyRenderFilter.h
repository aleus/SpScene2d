#pragma once

#include <Sp/IRenderFilter.h>

namespace sp
{

class EmptyRenderFilter final : public IRenderFilter
{
public:
    EmptyRenderFilter() = default;

    void pass(IVisualObjectsContainer & visualObjects,
              const RenderFilterParams & renderFilterParams) const override;
};

} // namespace sp
