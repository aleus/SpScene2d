#include "Scene2dPimpl.h"
#include "Sp/IRenderFilter.h"
#include "Sp/Scene2dLayer.h"

#include <iterator>

namespace sp
{

Scene2dPimpl::Scene2dPimpl(Scene2dLayers && sceneLayers, RenderFilters && renderFilters)
    : _sceneLayers(std::move(sceneLayers))
    , _renderFilters(std::move(renderFilters))
{
}

Scene2dPimpl::~Scene2dPimpl() = default;

void Scene2dPimpl::add(const std::shared_ptr<const IVisualObject> & visualObject)
{
    _visualObjects.push_back(visualObject);
}

void Scene2dPimpl::add(const IVisualObjectsContainer & visualObjects)
{
    // Debug!!! Не уверен, что нужно перемещение, а не копирование
    std::move(visualObjects.begin(), visualObjects.end(), std::back_inserter(_visualObjects));
}

void Scene2dPimpl::remove(const std::shared_ptr<const IVisualObject> & visualObject)
{
    std::erase(_visualObjects, visualObject);
}

void Scene2dPimpl::update()
{
    // TODO Сделать отложенный вызов update - в следующей итерации цикла
    for (const auto & sceneLayer : _sceneLayers) {
        sceneLayer->update();
    }

    // Debug!!! Выставлено сюда для отладки
    // Нужно переделать на RxCpp
    passFilters();

    for (auto & sceneLayer : _sceneLayers) {
        // Здесь нужно передавать отдельный массив для каждого слоя
        // TODO Неэффективная передача массива объектов
        // Debug!!! Тут неправильное использование
        sceneLayer->setVisualObjects(_visualObjects);
    }
}

void Scene2dPimpl::passFilters()
{
    RenderFilterParams renderFilterParams; // TODO Инициализировать снаружи

    for (const auto & renderFilter : _renderFilters) {
        renderFilter->pass(_visualObjects,
                           _visualObjectsDerivative,
                           renderFilterParams);
    }
}

} // namespace sp
