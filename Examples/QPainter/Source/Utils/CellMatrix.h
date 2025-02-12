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
class CellMatrix final
{
public:
    CellMatrix(Scene2dInt width, Scene2dInt height, Scene2dInt cellWidth, Scene2dInt cellHeight);

    // Debug!!! Проверяю теорию об использовании одного элемента вместа списка
    // using VisualObjectsList = std::vector<const VisualObject *>;

    /** @brief Возвращает массив объектов в ячейке с координатами (x,y). */
    [[nodiscard]]
    // const VisualObjectsList & get(Scene2dInt x, Scene2dInt y) const;
    bool get(Scene2dInt x, Scene2dInt y) const;
    bool get(Scene2dInt left, Scene2dInt top, Scene2dInt width, Scene2dInt height) const;
    bool get(const Rect2d & rect) const;

    /** @brief Добавляет object в ячейки, в которых расположен прямоугольник (x,y,width,height). */
    void set(Scene2dInt left, Scene2dInt top, Scene2dInt width, Scene2dInt height);
    void set(const Rect2d & rect);

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

    // Debug!!!
    // using FlatMatrix = std::vector<VisualObjectsList>;
    using FlatMatrix = std::vector<bool>;
    FlatMatrix _flatMatrix;
};

} // namespace sp
