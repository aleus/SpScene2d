#pragma once

#include <Sp/IVisualObject.h>
#include <Sp/Scene2dTypes.h>

#include <memory>
#include <vector>

namespace sp
{

template <class VisualObject>
concept VisualObjectConcept = std::is_base_of<IVisualObject, VisualObject>::value;

/**
 * @brief Структура данных для оптимизации нахождения объектов в определённой области сцены.
 * Представляет из себя матрицу ячеек, в которых указан список визуальных объектов,
 * расположенных в соответствующих координатах.
 *
 * @details Координаты точек всегда идут от 0 (т.е. матрица
 */
template <VisualObjectConcept VisualObject>
class CellMatrix final
{
public:
    CellMatrix(Scene2dInt width, Scene2dInt height, Scene2dInt cellWidth, Scene2dInt cellHeight);

    using VisualObjectPtr = std::shared_ptr<VisualObject>;
    using VisualObjectsList = std::vector<VisualObjectPtr>;

    /** @brief Возвращает массив объектов в ячейке с координатами (x,y). */
    [[nodiscard]]
    const VisualObjectsList & get(Scene2dInt x, Scene2dInt y) const;

    /** @brief Добавляет object в ячейку, соответствующую точке (x,y). */
    void add(Scene2dInt x, Scene2dInt y, VisualObjectPtr && object);

    /** @brief Добавляет object в ячейки, в которых расположен прямоугольник (x,y,width,height). */
    void add(Scene2dInt left, Scene2dInt top, Scene2dInt width, Scene2dInt height, VisualObjectPtr && object);
    void add(const Rect2d & rect, VisualObjectPtr && object);

    /** @brief Очищает все ячейки матрицы. */
    void clear();

private:
    inline size_t index(Scene2dInt x, Scene2dInt y) const
    {
        return (x / _cellWidth) * (y / _cellHeight);
    }

private:
    const Scene2dInt _width;
    const Scene2dInt _height;
    const Scene2dInt _cellWidth;
    const Scene2dInt _cellHeight;
    const size_t _sizeX;
    const size_t _sizeY;

    using FlatMatrix = std::vector<VisualObjectsList>;
    FlatMatrix _flatMatrix;
};

} // namespace sp

#include "CellMatrix.hpp"
