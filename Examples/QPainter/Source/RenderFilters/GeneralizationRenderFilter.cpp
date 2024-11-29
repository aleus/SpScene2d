#pragma once

#include "GeneralizationRenderFilter.h"
#include "Sp/Scene2dTypes.h"

#include <Utils/CellList.h>
#include <VisualObjects/CircleVisualObject.h>

#include <Sp/IVisualObject.h>

namespace sp
{

namespace
{

// TODO: Перенести функцию в Rect2dF или в утилиты
bool isIntersect(const Rect2dF & first, const Rect2dF & second)
{
    return (first.left < second.left + second.width && first.left + first.width > second.left &&
            first.top < second.top + second.height && first.top + first.height > second.top) ||
           (second.left < first.left + first.width && second.left + second.width > first.left &&
            second.top < first.top + first.height && second.top + second.height > first.top);
}

} // namespace

void GeneralizationRenderFilter::pass(IVisualObjectsContainer & visualObjects,
                                      const RenderFilterParams & renderFilterParams) const
{
    // Debug!!! Отладочные параметры cellList
    size_t width = renderFilterParams.sceneSize.width;
    size_t height = renderFilterParams.sceneSize.height;
    size_t cellWidth = 10;
    size_t cellHeight = 10;
    CellList<std::shared_ptr<IVisualObject>> cellList(width, height, cellWidth, cellHeight);

    // for (const IVisualObjectCPtr & visualObject : visualObjects) {
    //     // Debug!! Для отладки смотрим только круги
    //     if (auto * circle = dynamic_cast<const CircleVisualObject *>(visualObject.get())) {
    //     }
    // }
}

} // namespace sp
