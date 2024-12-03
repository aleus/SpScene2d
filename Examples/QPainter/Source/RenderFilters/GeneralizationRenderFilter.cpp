#include "GeneralizationRenderFilter.h"

#include <Sp/Scene2dTypes.h>
#include <Sp/IVisualObject.h>
#include <Utils/CellMatrix.h>
#include <VisualObjects/CircleVisualObject.h>

namespace sp
{

void GeneralizationRenderFilter::pass(IVisualObjectsCContainer & visualObjects,
                                      const RenderFilterParams & renderFilterParams) const
{
    // Debug!!! Отладочные параметры cellMatrix
    size_t width = renderFilterParams.sceneSize.width;
    size_t height = renderFilterParams.sceneSize.height;
    size_t cellWidth = 10;
    size_t cellHeight = 10;

    CellMatrix<const IVisualObject> cellMatrix(width, height, cellWidth, cellHeight);

    for (const auto & visualObject : visualObjects) {
        // Debug!! Для отладки смотрим только круги
        if (dynamic_cast<const CircleVisualObject *>(visualObject.get())) {
            cellMatrix.add(visualObject->boundingBoxPx(), visualObject);
        }
    }
}

} // namespace sp
