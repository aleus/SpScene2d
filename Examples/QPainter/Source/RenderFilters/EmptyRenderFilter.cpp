#pragma once

#include "EmptyRenderFilter.h"

namespace sp
{

void EmptyRenderFilter::pass(IVisualObjectsContainer & /* visualObjects */,
                             const RenderFilterParams & /* renderFilterParams */) const
{
}

} // namespace sp
