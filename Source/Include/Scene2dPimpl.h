#pragma once

#include "Sp/ConstructorMacros.h"
#include "Sp/IRenderFilter.h"
#include "Sp/IVisualObject.h"
#include "Sp/Scene2dLayer.h"

namespace sp
{

class IRenderFilter;

class Scene2dPimpl
{
public:
    Scene2dPimpl(Scene2dLayers && sceneLayers, RenderFilters && renderFilters);
    ~Scene2dPimpl();
    DELETE_COPY_MOVE_CONSTRUCTOR(Scene2dPimpl)

    inline const Scene2dLayers & scene2dLayers() const { return _sceneLayers; }

    void add(const IVisualObjectCPtr & visualObject);
    void add(const IVisualObjectsContainer & visualObjects);

    void remove(const IVisualObjectCPtr & visualObject);

    // TODO Временно удалил const
    // void update() const;
    void update();

private:
    void passFilters(const RenderFilterParams & renderFilterParams);

private:
    Scene2dLayers _sceneLayers;
    RenderFilters _renderFilters;

    // TODO Сделать контейнер дружественным к удалениям из середины.
    // Для этого при удалении нужно занулять указатель, но не удалять из контейнера,
    // и увеличивать счётчик удалённых объектов. Когда счётчик перевалит некую величину,
    // проводить очистку вектора.
    // Кроме этого ввести функции begin/end для удаления нескольких объектов.
    // Лучше использовать RAII-объект для этого.
    IVisualObjectsCContainer _visualObjects;
    IVisualObjectsCContainer _visualObjectsFiltered;
};

} // namespace sp
