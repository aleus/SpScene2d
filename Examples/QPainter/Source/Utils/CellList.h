#pragma once

#include <memory>
#include <vector>

namespace sp
{

template <typename Object>
class CellList final
{
public:
    CellList(size_t width, size_t height, size_t cellWidth, size_t cellHeight)
        : _width(width)
        , _height(height)
        , _cellWidth(cellWidth)
        , _cellHeight(cellHeight)
        , _sizeX(width / cellWidth + 1) // округление в большую сторону
        , _sizeY(height / cellHeight + 1)
        , _container(_sizeX * _sizeY)
    {
    }

    const std::vector<Object> & get(size_t x, size_t y) {
        return _container[index(x, y)];
    }

    void set(size_t x, size_t y, const Object & object)
    {
        _container[index(x, y)].push_back(object);
    }

    void set(size_t x, size_t y, Object && object)
    {
        _container[index(x, y)].push_back(std::move(object));
    }

    void set(size_t x_, size_t y_, size_t width, size_t height, Object && object)
    {
        // TODO Написать более оптимальный алгоритм обхода индексов
        const size_t xLast = x_ + width;
        const size_t yLast = y_ + height;

        for (size_t y = y_; y < yLast; y += _cellHeight) {
            for (size_t x = x_; x < xLast; x += _cellWidth) {
                _container[index(x, y)].push_back(std::move(object));
            }
        }
    }

private:
    inline size_t index(size_t x, size_t y) {
        return (x / _cellWidth) * (y / _cellHeight);
    }

private :
    const size_t _width;
    const size_t _height;
    const size_t _cellWidth;
    const size_t _cellHeight;
    const size_t _sizeX;
    const size_t _sizeY;

    std::vector<std::vector<Object>> _container;
};

} // namespace sp
