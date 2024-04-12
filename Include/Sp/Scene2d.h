#pragma once

#include "Sp/ConstructorMacros.h"
#include "Sp/IRenderFilter.h"
#include "Sp/IVisualObject.h"
#include "Sp/Scene2dLayer.h"

#include <memory>

namespace sp {

class Scene2dPimpl;

/** @brief Центральный класс, управляющий отрисовкой 2D-сцены. */
class Scene2d {
public:
    Scene2d(Scene2dLayers && scene2dLayers, RenderFilters && renderFilters);
    ~Scene2d();
    DELETE_COPY_MOVE_CONSTRUCTOR(Scene2d)

    const Scene2dLayers & scene2dLayers() const;

    /** Добавляет визуальный объект на сцену для отображения. */
    void add(const IVisualObjectCPtr & visualObject);

    /** Удаляет визуальный объект со сцены. */
    void remove(const IVisualObjectCPtr & visualObject);

    /** Вызывает обновление и перерисовку сцены. */
    void update();

private:
    std::unique_ptr<Scene2dPimpl> _pimpl;
};

} // namespace sp
