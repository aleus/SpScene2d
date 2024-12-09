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
    , _flatMatrix(_sizeX * _sizeY, nullptr)
{
}

template <VisualObjectConcept VisualObject>
// Debug!!!
// const typename CellMatrix<VisualObject>::VisualObjectsList &
const VisualObject * CellMatrix<VisualObject>::get(Scene2dInt x, Scene2dInt y) const
{
    assert(x < _width && y < _height);

    return _flatMatrix[index(x, y)];
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(Scene2dInt x, Scene2dInt y, const VisualObject * object)
{
    assert(x < _width && y < _height);
    assert(object);

    _flatMatrix[index(x, y)].push_back(object);
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(Scene2dInt left, Scene2dInt top, Scene2dInt width, Scene2dInt height, const VisualObject * object)
{
    assert(left + width < _width && top + height < _height);
    assert(object);

    size_t i = index(left, top);
    const size_t maxY = height ? (height - 1) / (_cellHeight + 1) : 0;
    const size_t maxX = width ? (width - 1) / (_cellWidth + 1) : 0;
    const size_t dy = _sizeX;

    for (size_t y = 0; y < maxY; ++y, i += dy) {
        for (size_t x = 0; x < maxX; ++x, ++i) {
            // Debug!!! Проверяем теорию об одном добавлении
            // if (VisualObjectsList & cellList = _flatMatrix[i]; cellList.empty()) {
            //     cellList.push_back(object);
            // }
            if (_flatMatrix[i] == nullptr) {
                _flatMatrix[i] = object;
            }
        }
    }
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::add(const Rect2d & rect, const VisualObject * object)
{
    add(rect.left, rect.top, rect.width, rect.height, object);
}

template <VisualObjectConcept VisualObject>
void CellMatrix<VisualObject>::clear()
{
    _flatMatrix.clear();
}

} // namespace sp
