#pragma once

#include "CellMatrix.h"

#include <cassert>

namespace sp
{

template <VisualObjectConcept VisualObject>
CellMatrix<VisualObject>::CellMatrix(Scene2dInt width, Scene2dInt height, Scene2dInt cellWidth, Scene2dInt cellHeight)
    : _width(width)
    , _height(height)
    , _cellWidth(cellWidth)
    , _cellHeight(cellHeight)
    , _sizeX(width ? (width - 1) / cellWidth + 1 : 0) // округление в большую сторону
    , _sizeY(height ? (height - 1) / cellHeight + 1 : 0)
    , _flatMatrix(_sizeX * _sizeY)
{
}

template <VisualObjectConcept VisualObject>
const typename CellMatrix<VisualObject>::VisualObjectsList &
CellMatrix<VisualObject>::get(Scene2dInt x, Scene2dInt y) const
{
    assert(x < _width && y < _height);

    return _flatMatrix[index(x, y)];
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(Scene2dInt x, Scene2dInt y, VisualObjectPtr && object)
{
    assert(x < _width && y < _height);
    assert(object);

    _flatMatrix[index(x, y)].push_back(std::forward<VisualObjectPtr>(object));
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(Scene2dInt left, Scene2dInt top, Scene2dInt width, Scene2dInt height, VisualObjectPtr && object)
{
    assert(left + width < _width && top + height < _height);
    assert(object);

    // TODO Написать более оптимальный алгоритм обхода индексов
    const Scene2dInt xLast = left + width;
    const Scene2dInt yLast = top + height;

    for (Scene2dInt y = top; y < yLast; y += _cellHeight) {
        for (Scene2dInt x = left; x < xLast; x += _cellWidth) {
            _flatMatrix[index(x, y)].push_back(std::forward<VisualObjectPtr>(object));
        }
    }
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(const Rect2d & rect, VisualObjectPtr && object)
{
    add(rect.left, rect.top, rect.width, rect.height, std::forward<VisualObjectPtr>(object));
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::clear()
{
    _flatMatrix.clear();
}

} // namespace sp
