#pragma once

#include "Sp/ConstructorMacros.h"
#include "Sp/IRenderFilter.h"
#include "Sp/IVisualObject.h"
#include "Sp/Scene2dLayer.h"
#include "Sp/Camera.h"

#include <memory>

namespace sp
{

class Scene2dPimpl;

/** @brief Центральный класс, управляющий отрисовкой 2D-сцены. */
class Scene2d
{
public:
    Scene2d(Scene2dLayers && scene2dLayers, RenderFilters && renderFilters);
    ~Scene2d();
    DELETE_COPY_MOVE_CONSTRUCTOR(Scene2d)

    const Scene2dLayers & scene2dLayers() const;

    /** Добавляет визуальный объект на сцену для отображения. */
    void add(const IVisualObjectCPtr & visualObject);
    void add(const IVisualObjectsContainer & visualObjects);

    /** Удаляет визуальный объект со сцены. */
    void remove(const IVisualObjectCPtr & visualObject);

    /** Вызывает обновление и перерисовку сцены. */
    void update();

    inline const Camera & camera() const { return _camera; }
    inline Camera & camera() { return _camera; }

    const Size2d & size() const;
    void setSize(const Size2d & size);

private:
    Camera _camera;
    std::unique_ptr<Scene2dPimpl> _pimpl;
};

} // namespace sp
