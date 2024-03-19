#pragma once

#include <Sp/Scene2dLayer.h>

#include <QSizeF>

class QPainter;

namespace sp
{

class QPainterScene2dLayerItem;

/**
 *  @brief Слоя сцены Scene2d для отрисовки через QPainter в Qt Quick.
 *  @sa QPainterScene2dLayerItem
 */
class QPainterScene2dLayer final : public Scene2dLayer
{
public:
    QPainterScene2dLayer() = default;

    /** @brief Устанавливает Quick Item, отображающий соотвествующий слой. */
    void setScene2dLayerItem(QPainterScene2dLayerItem * scene2dLayerItem);

    /**
     *  @brief Отрисовывает графические объекты на слое через QPainter.
     *  Во время вызова записывает аргумент painer во внутренее поле _painter.
     *  Которое потом используется при отрисовке визуальных объектов.
     *  @sa painter
     */
    void paint(QPainter * painter);

    /** @brief Возвращает размер слоя на сцене. */
    QSizeF size();

    /** @brief Возвращает временный указатель на QPainter во время вызова paint. */
    inline QPainter * painter() const { return _painter; }

    void update() final;

private:
    QPainterScene2dLayerItem * _scene2dLayerItem = nullptr;
    QPainter * _painter = nullptr;
};

} // namespace sp
