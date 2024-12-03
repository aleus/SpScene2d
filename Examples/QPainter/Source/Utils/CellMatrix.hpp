#pragma once

#include "CellMatrix.h"

#include <cassert>

namespace sp
{

template <VisualObjectConcept VisualObject>
CellMatrix<VisualObject>::CellMatrix(size_t width, size_t height, size_t cellWidth, size_t cellHeight)
    : _width(width)
    , _height(height)
    , _cellWidth(cellWidth)
    , _cellHeight(cellHeight)
    , _sizeX(width ? (width - 1) / cellWidth + 1 : 0) // округление в большую сторону
    , _sizeY(height ? (height - 1) / cellHeight + 1 : 0)
    , _container(_sizeX * _sizeY)
{
}

template <VisualObjectConcept VisualObject>
const typename CellMatrix<VisualObject>::VisualObjectsList &
CellMatrix<VisualObject>::get(size_t x, size_t y) const
{
    assert(x < _width && y < _height);

    return _container[index(x, y)];
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(size_t x, size_t y, const VisualObjectPtr & object)
{
    assert(x < _width && y < _height);
    assert(object);

    _container[index(x, y)].push_back(object);
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(size_t x, size_t y, VisualObjectPtr && object)
{
    assert(x < _width && y < _height);
    assert(object);

    _container[index(x, y)].push_back(std::move(object));
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(size_t left, size_t top, size_t width, size_t height, const VisualObjectPtr & object)
{
    assert(left + width < _width && top + height < _height);
    assert(object);

    // TODO Написать более оптимальный алгоритм обхода индексов
    const size_t xLast = left + width;
    const size_t yLast = top + height;

    for (size_t y = top; y < yLast; y += _cellHeight) {
        for (size_t x = left; x < xLast; x += _cellWidth) {
            _container[index(x, y)].push_back(std::move(object));
        }
    }
}

template<VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(const Rect2d & rect, const VisualObjectPtr & object)
{
    add(rect.left, rect.top, rect.width, rect.height, object);
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::clear()
{
    _container.clear();
}

} // namespace sp
