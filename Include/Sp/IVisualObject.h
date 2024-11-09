#pragma once

#include "Sp/ConstructorMacros.h"

#include <memory>
#include <vector>

namespace sp
{

class Scene2dLayer;

class IVisualObject
{
public:
    IVisualObject() = default;
    virtual ~IVisualObject() = default;
    DELETE_COPY_MOVE_CONSTRUCTOR(IVisualObject)

    // TODO Заменить Scene2dLayer на константный интерфейс
    virtual void paint(Scene2dLayer & scene2dLayer) const = 0;

    // Debug!!! Нужно ли вводить BB и его кеширование?
    // virtual void boundingBox() const = 0;
};

using IVisualObjectPtr = std::shared_ptr<IVisualObject>;
using IVisualObjectCPtr = std::shared_ptr<const IVisualObject>;
using IVisualObjectsContainer = std::vector<IVisualObjectCPtr>;

} // namespace sp
