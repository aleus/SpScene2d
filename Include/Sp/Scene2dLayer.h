#pragma once

#include "Sp/ConstructorMacros.h"
#include "Sp/IVisualObject.h"

#include <memory>
#include <vector>

namespace sp
{

/** @brief Интерфейс слоя Scene2d. На слое отрисовываются визуальные объекты методом paint. */
class Scene2dLayer
{
public:
    Scene2dLayer() = default;
    virtual ~Scene2dLayer() = default;
    DELETE_COPY_MOVE_CONSTRUCTOR(Scene2dLayer)

    // Debug!!! Не понятно где должно быть?
    void setVisualObjects(std::vector<IVisualObjectCPtr> && visualObjects);

    virtual void update() = 0;

protected:
    std::vector<IVisualObjectCPtr> _visualObjects;
};

/** @brief Контейнер слоёв, используемых в Scene2d. */
using SceneLayers = std::vector<std::unique_ptr<Scene2dLayer>>;

} // namespace sp
