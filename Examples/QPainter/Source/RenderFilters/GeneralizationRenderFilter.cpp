#include "GeneralizationRenderFilter.h"

#include <Sp/IVisualObject.h>
#include <Sp/Scene2dTypes.h>
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

    // Debug!! Для отладки смотрим только круги
    CellMatrix<const CircleVisualObject> cellMatrix(width, height, cellWidth, cellHeight);

    for (const auto & visualObject : visualObjects) {
        if (auto circle = std::dynamic_pointer_cast<const CircleVisualObject>(visualObject)) {
            cellMatrix.add(visualObject->boundingBoxPx(), std::move(circle));
        }
    }

    auto removeIndex = std::remove_if(visualObjects.begin(), visualObjects.end(),
                                      [&cellMatrix](const auto & visualObject) -> bool {
                                          auto * circle = dynamic_cast<const CircleVisualObject *>(visualObject.get());
                                          if (circle) {
                                              // Debug!!! Для отладки смотрим левый-правый угол, а нужно весь bb.
                                              auto bb = circle->boundingBoxPx();
                                              const auto & list = cellMatrix.get(bb.left, bb.top);

                                              assert(!list.empty());
                                              return !list.empty() && list.front() != visualObject;
                                          }
                                          return false;
                                      });
    visualObjects.erase(removeIndex, visualObjects.end());
}

} // namespace sp
