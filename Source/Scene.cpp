#include "Sp/Scene.h"
#include "ScenePimpl.h"

using namespace sp;

Scene::Scene()
    : _pimpl(new ScenePimpl())
{

}

Scene::~Scene() = default;

void Scene::add(const std::shared_ptr<const IVisualObject> & visualObject)
{
    _pimpl->add(visualObject);
}

void Scene::remove(const std::shared_ptr<const IVisualObject> & visualObject)
{
    _pimpl->remove(visualObject);
}

void Scene::update()
{
    // TODO Сделать отложенный вызов update - в следующей итерации цикла
    // Для этого нужна интеграция с внешним циклом событий.
    // Возможно, что это нужно отдать на откуп выше.

    _pimpl->update();
}
