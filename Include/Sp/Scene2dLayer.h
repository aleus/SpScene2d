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

    // Debug!!! Не понятно где должно быть и в каком виде.
    inline const auto & visualObjects() const { return _visualObjects; }

    void setVisualObjects(const IVisualObjectsCContainer & visualObjects);
    void setVisualObjects(IVisualObjectsCContainer && visualObjects);

    virtual void update() = 0;

private:
    IVisualObjectsCContainer _visualObjects;
};

/** @brief Контейнер слоёв, используемых в Scene2d. */
using Scene2dLayers = std::vector<std::unique_ptr<Scene2dLayer>>;

} // namespace sp
