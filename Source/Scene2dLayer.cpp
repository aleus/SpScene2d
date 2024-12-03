#include "Sp/Scene2dLayer.h"

namespace sp
{

void Scene2dLayer::setVisualObjects(const IVisualObjectsCContainer & visualObjects)
{
    _visualObjects = visualObjects;
}

void Scene2dLayer::setVisualObjects(IVisualObjectsCContainer && visualObjects)
{
    _visualObjects = std::move(visualObjects);
}

} // namespace sp
