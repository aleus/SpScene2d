#pragma once

#include "Sp/ConstructorMacros.h"
#include "Sp/IVisualObject.h"
#include "Sp/RenderFilterParams.h"

#include <vector>

namespace sp
{

class IRenderFilter
{
    public:
        virtual ~IRenderFilter() = default;
        DELETE_COPY_MOVE_CONSTRUCTOR(IRenderFilter)

        virtual void pass(std::vector<IVisualObjectCPtr> & visualObjects, const RenderFilterParams & renderFilterParams) const = 0;
};

} // namespace sp
