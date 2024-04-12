#pragma once

#include <Sp/IRenderFilter.h>

namespace sp {

class EmptyRenderFilter : public IRenderFilter {
public:
    EmptyRenderFilter() = default;

    void pass(std::vector<IVisualObjectCPtr> & visualObjects,
              const RenderFilterParams & renderFilterParams) const override;
};

} // namespace sp
