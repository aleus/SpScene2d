#include "ScenePimpl.h"
#include "Sp/IRenderFilter.h"
#include "Sp/IPainterLayer.h"

using namespace sp;

ScenePimpl::ScenePimpl()
{

}

ScenePimpl::~ScenePimpl() = default;

void ScenePimpl::add(const std::shared_ptr<const IVisualObject> & visualObject)
{
    _visualObjects.push_back(visualObject);
}

void ScenePimpl::remove(const std::shared_ptr<const IVisualObject> & visualObject)
{
    std::erase(_visualObjects, visualObject);
}

void ScenePimpl::update() const
{
    // TODO Сделать отложенный вызов update - в следующей итерации цикла

    auto visualObjects = _visualObjects;
    RenderFilterParams renderFilterParams; // TODO Инициализировать снаружи

    for (const auto & renderFilter : _renderFilters)
    {
        renderFilter->pass(visualObjects, renderFilterParams);
    }

    for (const auto & painter : _painters)
    {
        painter->paint(visualObjects);
    }
}
