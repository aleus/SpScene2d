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
    IRenderFilter() = default;
    virtual ~IRenderFilter() = default;
    DELETE_COPY_MOVE_CONSTRUCTOR(IRenderFilter)

    /** @brief Обработка фильтром визуальных объектов.
     *  Контейнер visualObjects содержит входной набор объектов и модифицируется
     *  после прохода функции.  */
    virtual void pass(IVisualObjectsContainer & visualObjects,
                      const RenderFilterParams & renderFilterParams) const = 0;
};

/** @brief Контейнер фильтров рендера. */
using RenderFilters = std::vector<std::unique_ptr<IRenderFilter>>;

} // namespace sp
