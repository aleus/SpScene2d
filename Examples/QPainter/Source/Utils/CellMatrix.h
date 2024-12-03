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
    CellMatrix(size_t width, size_t height, size_t cellWidth, size_t cellHeight);

    using VisualObjectPtr = std::shared_ptr<VisualObject>;
    using VisualObjectsList = std::vector<VisualObjectPtr>;

    /** @brief Возвращает массив объектов в ячейке с координатами (x,y). */
    const VisualObjectsList & get(size_t x, size_t y) const;

    /** @brief Добавляет object в ячейку, соответствующую точке (x,y). */
    void add(size_t x, size_t y, const VisualObjectPtr & object);
    void add(size_t x, size_t y, VisualObjectPtr && object);

    /** @brief Добавляет object в ячейки, в которых расположен прямоугольник (x,y,width,height). */
    // TODO Добавить реализацию для копирования объекта
    // void add(size_t left, size_t top, size_t width, size_t height, const VisualObject & object);

    void add(size_t left, size_t top, size_t width, size_t height, const VisualObjectPtr & object);
    void add(const Rect2d & rect, const VisualObjectPtr & object);

    /** @brief Очищает все ячейки матрицы. */
    void clear();

private:
    inline size_t index(size_t x, size_t y)
    {
        return (x / _cellWidth) * (y / _cellHeight);
    }

private:
    const size_t _width;
    const size_t _height;
    const size_t _cellWidth;
    const size_t _cellHeight;
    const size_t _sizeX;
    const size_t _sizeY;

    using Container = std::vector<VisualObjectsList>;
    Container _container;
};

} // namespace sp

#include "CellMatrix.hpp"
