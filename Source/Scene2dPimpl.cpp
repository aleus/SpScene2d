#include "Scene2dPimpl.h"
#include "Sp/IRenderFilter.h"
#include "Sp/Scene2dLayer.h"

#include <iterator>

namespace sp
{

Scene2dPimpl::Scene2dPimpl(Scene2dLayers && sceneLayers, RenderFilters && renderFilters, const Camera & camera)
    : _sceneLayers(std::move(sceneLayers))
    , _renderFilters(std::move(renderFilters))
    , _camera(camera)
{
    for (const auto & sceneLayer : _sceneLayers) {
        sceneLayer->setCamera(_camera);
    }
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

void Scene2dPimpl::setSize(const Size2d & size)
{
    _size = size;
}

void Scene2dPimpl::remove(const std::shared_ptr<const IVisualObject> & visualObject)
{
    std::erase(_visualObjects, visualObject);
}

void Scene2dPimpl::update()
{
    // TODO: Возможна неэффективная фильтрация при каждом обновлении сцены.
    // Debug!!! Заданы параметры по-умолчанию для отладки
    RenderFilterParams renderFilterParams{
        .sceneSize{_size},
    };

    passFilters(renderFilterParams);

    for (auto & sceneLayer : _sceneLayers) {
        // TODO Неэффективная передача массива объектов
        // Здесь нужно передавать отдельный массив для каждого слоя
        sceneLayer->setVisualObjects(_visualObjectsFiltered);
    }

    // TODO Сделать отложенный вызов update - в следующей итерации цикла
    for (const auto & sceneLayer : _sceneLayers) {
        sceneLayer->update();
    }
}

void Scene2dPimpl::passFilters(const RenderFilterParams & renderFilterParams)
{
    // TODO: Стоит оптимизировать копирование с помощью CoW
    _visualObjectsFiltered = _visualObjects;

    for (const auto & renderFilter : _renderFilters) {
        renderFilter->pass(_visualObjectsFiltered,
                           renderFilterParams);
    }
}

} // namespace sp
