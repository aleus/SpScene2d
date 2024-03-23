#include "Sp/Scene2d.h"
#include "Scene2dPimpl.h"

namespace sp
{

Scene2d::Scene2d(Scene2dLayers && scene2dLayers)
    : _pimpl(new Scene2dPimpl(std::move(scene2dLayers)))
{
}

const Scene2dLayers & Scene2d::scene2dLayers() const
{
    return _pimpl->scene2dLayers();
}

Scene2d::~Scene2d() = default;

void Scene2d::add(const std::shared_ptr<const IVisualObject> & visualObject)
{
    _pimpl->add(visualObject);
}

void Scene2d::remove(const std::shared_ptr<const IVisualObject> & visualObject)
{
    _pimpl->remove(visualObject);
}

void Scene2d::update()
{
    // TODO Сделать отложенный вызов update - в следующей итерации цикла
    // Для этого нужна интеграция с внешним циклом событий.
    // Возможно, что это нужно отдать на откуп выше.

    _pimpl->update();
}

} // namespace sp
