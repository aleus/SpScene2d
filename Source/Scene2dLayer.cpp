#include "Sp/Scene2dLayer.h"

namespace sp
{

void Scene2dLayer::setVisualObjects(std::vector<IVisualObjectCPtr> && visualObjects)
{
    _visualObjects = visualObjects;
}

} // namespace sp
