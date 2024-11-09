#include "Sp/Scene2dLayer.h"

namespace sp
{

void Scene2dLayer::setVisualObjects(const IVisualObjectsContainer & visualObjects)
{
    _visualObjects = visualObjects;
}

void Scene2dLayer::setVisualObjects(IVisualObjectsContainer && visualObjects)
{
    _visualObjects = std::move(visualObjects);
}

} // namespace sp
