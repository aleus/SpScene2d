#pragma once

#include "Sp/ConstructorMacros.h"
#include "Sp/IVisualObject.h"
#include "Sp/Scene2dLayer.h"

#include <memory>
#include <vector>

namespace sp
{

class IRenderFilter;

class Scene2dPimpl
{
public:
    Scene2dPimpl(Scene2dLayers && sceneLayers);
    ~Scene2dPimpl();
    DELETE_COPY_MOVE_CONSTRUCTOR(Scene2dPimpl)

    inline const Scene2dLayers & scene2dLayers() const { return _sceneLayers; }

    void add(const IVisualObjectCPtr & visualObject);
    void add(const std::vector<IVisualObjectCPtr> & visualObjects);

    void remove(const IVisualObjectCPtr & visualObject);
    void update() const;

private:
    void passFilters();

private:
    // TODO Сделать контейнер дружественным к удалениям из середины.
    // Для этого при удалении нужно занулять указатель, но не удалять из контейнера,
    // и увеличивать счётчик удалённых объектов. Когда счётчик перевалит некую величину,
    // проводить очистку вектора.
    // Кроме этого ввести функции begin/end для удаления нескольких объектов.
    // Лучше использовать RAII-объект для этого.
    std::vector<IVisualObjectCPtr> _visualObjects;
    std::vector<IVisualObjectCPtr> _visualObjectsFiltered;

    std::vector<std::unique_ptr<IRenderFilter>> _renderFilters;

    Scene2dLayers _sceneLayers;
};

} // namespace sp
