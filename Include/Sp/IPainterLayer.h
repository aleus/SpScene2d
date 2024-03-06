#pragma once

#include "Sp/IVisualObject.h"
#include "Sp/ConstructorMacros.h"

#include <vector>

namespace sp
{

class IPainterLayer
{
    public:
        virtual ~IPainterLayer() = default;
        DELETE_COPY_MOVE_CONSTRUCTOR(IPainterLayer)

        virtual void paint(std::vector<IVisualObjectCPtr> & visualObject) = 0;
};

} // namespace sp
