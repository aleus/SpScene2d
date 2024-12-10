#include "GeneralizationRenderFilter.h"

#include <Sp/IVisualObject.h>
#include <Sp/Scene2dTypes.h>
#include <Utils/CellMatrix.h>
#include <VisualObjects/CircleVisualObject.h>

#include <easy/profiler.h>
#include <QDebug>

namespace sp
{

void GeneralizationRenderFilter::pass(IVisualObjectsCContainer & visualObjects,
                                      const RenderFilterParams & renderFilterParams) const
{
    EASY_FUNCTION()

    qDebug();
    qDebug() << "Debug!!! before" << visualObjects.size();
    // Debug!!! Отладочные параметры cellMatrix
    size_t width = renderFilterParams.sceneSize.width;
    size_t height = renderFilterParams.sceneSize.height;
    size_t cellWidth = 1;
    size_t cellHeight = 1;

    CellMatrix cellMatrix(width, height, cellWidth, cellHeight);

    EASY_BLOCK("Remove 1 step")
    auto removeIndex = std::remove_if(visualObjects.begin(), visualObjects.end(),
                                      [&cellMatrix](const auto & visualObject) -> bool {
                                          // Debug!! Для отладки смотрим только круги
                                          auto * circle = dynamic_cast<const CircleVisualObject *>(visualObject.get());
                                          if (circle) {
                                              // Debug!!! Для отладки смотрим левый-правый угол, а нужно весь bb.
                                              auto bb = circle->boundingBoxPx();
                                              if (!cellMatrix.get(bb)) {
                                                  cellMatrix.set(bb);
                                                  return false;
                                              } else {
                                                  return true;
                                              }
                                          }
                                          return false;
                                      });
    EASY_END_BLOCK
    EASY_BLOCK("Remove 2 step")
    visualObjects.erase(removeIndex, visualObjects.end());
    EASY_END_BLOCK
    qDebug() << "Debug!!! after" << visualObjects.size();
}

} // namespace sp
