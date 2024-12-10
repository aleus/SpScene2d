#pragma once

#include "CellMatrix.h"

#include <cassert>

namespace sp
{

CellMatrix::CellMatrix(Scene2dInt width, Scene2dInt height, Scene2dInt cellWidth, Scene2dInt cellHeight)
    : _width(width)
    , _height(height)
    , _cellWidth(cellWidth)
    , _cellHeight(cellHeight)
    , _sizeX(width ? (width - 1) / cellWidth + 1 : 0) // округление в большую сторону
    , _sizeY(height ? (height - 1) / cellHeight + 1 : 0)
    , _flatMatrix(_sizeX * _sizeY, false)
{
}

bool CellMatrix::get(Scene2dInt x, Scene2dInt y) const
{
    assert(x < _width && y < _height);

    return _flatMatrix[index(x, y)];
}

bool CellMatrix::get(Scene2dInt left, Scene2dInt top, Scene2dInt width, Scene2dInt height) const
{
    size_t i = index(left, top);
    const size_t maxY = height ? (height - 1) / (_cellHeight + 1) : 0;
    const size_t maxX = width ? (width - 1) / (_cellWidth + 1) : 0;
    const size_t dy = _sizeX;

    for (size_t y = 0; y < maxY; ++y, i += dy) {
        for (size_t x = 0; x < maxX; ++x, ++i) {
            if (_flatMatrix[i])
                return true;
        }
    }

    return false;
}

bool CellMatrix::get(const Rect2d & rect) const
{
    return get(rect.left, rect.top, rect.width, rect.height);
}

void CellMatrix::set(Scene2dInt left, Scene2dInt top, Scene2dInt width, Scene2dInt height)
{
    assert(left + width < _width && top + height < _height);
    assert(object);

    size_t i = index(left, top);
    const size_t maxY = height ? (height - 1) / (_cellHeight + 1) : 0;
    const size_t maxX = width ? (width - 1) / (_cellWidth + 1) : 0;
    const size_t dy = _sizeX;

    for (size_t y = 0; y < maxY; ++y, i += dy) {
        for (size_t x = 0; x < maxX; ++x, ++i) {
            _flatMatrix[i] = true;
        }
    }
}

void CellMatrix::set(const Rect2d & rect)
{
    set(rect.left, rect.top, rect.width, rect.height);
}

void CellMatrix::clear()
{
    _flatMatrix.clear();
}

} // namespace sp
