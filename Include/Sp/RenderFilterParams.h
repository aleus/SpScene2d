#pragma once

#include "Sp/Scene2dTypes.h"

namespace sp
{

// TODO Добавить возможность настраивать параметры в пользовательском коде
struct RenderFilterParams
{
    sp::Size2d sceneSize;
    double zoomLevel = 1.0;
};

} // namespace sp
