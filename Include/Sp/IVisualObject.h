#pragma once

#include "Sp/ConstructorMacros.h"

#include <memory>

namespace sp
{

class IVisualObject
{
public:
    virtual ~IVisualObject() = default;
    DELETE_COPY_MOVE_CONSTRUCTOR(IVisualObject)
};

using IVisualObjectPtr = std::shared_ptr<IVisualObject>;
using IVisualObjectCPtr = std::shared_ptr<const IVisualObject>;

} // namespace sp
