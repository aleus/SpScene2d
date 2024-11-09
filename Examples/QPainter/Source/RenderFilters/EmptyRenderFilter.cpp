#pragma once

#include "EmptyRenderFilter.h"

namespace sp
{

void EmptyRenderFilter::pass(const IVisualObjectsContainer & /* visualObjects */,
                             IVisualObjectsContainer & /* visualObjectsDerivative */,
                             const RenderFilterParams & /* renderFilterParams */) const
{
}

} // namespace sp
