#include "Scene2dPimpl.h"
#include "Sp/IRenderFilter.h"
#include "Sp/Scene2dLayer.h"

#include <iterator>

using namespace sp;

Scene2dPimpl::Scene2dPimpl(Scene2dLayers && sceneLayers)
    : _sceneLayers(std::move(sceneLayers))
{
}

Scene2dPimpl::~Scene2dPimpl() = default;

void Scene2dPimpl::add(const std::shared_ptr<const IVisualObject> & visualObject)
{
    _visualObjects.push_back(visualObject);
}

void Scene2dPimpl::add(const std::vector<IVisualObjectCPtr> & visualObjects)
{
    std::move(visualObjects.begin(), visualObjects.end(), std::back_inserter(_visualObjects));
}

void Scene2dPimpl::remove(const std::shared_ptr<const IVisualObject> & visualObject)
{
    std::erase(_visualObjects, visualObject);
}

void Scene2dPimpl::update() const
{
    // TODO Сделать отложенный вызов update - в следующей итерации цикла
    for (const auto & sceneLayer : _sceneLayers) {
        sceneLayer->update();
    }
}

void Scene2dPimpl::passFilters()
{
    _visualObjectsFiltered = _visualObjects;
    RenderFilterParams renderFilterParams; // TODO Инициализировать снаружи

    for (const auto & renderFilter : _renderFilters) {
        renderFilter->pass(_visualObjectsFiltered, renderFilterParams);
    }
}
