#pragma once

#include <utility>

namespace sp
{

struct RenderFilterParams
{
    double zoomLevel = 1.0;
    std::pair<int, int> _cursorPosition;
};

} // namespace sp
