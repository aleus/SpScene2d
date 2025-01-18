#include "Sp/Scene2dLayer.h"

namespace sp
{

void Scene2dLayer::setCamera(const Camera & camera)
{
    _camera = &camera;
}

void Scene2dLayer::setVisualObjects(const IVisualObjectsCContainer & visualObjects)
{
    _visualObjects = visualObjects;
}

} // namespace sp
