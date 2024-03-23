#pragma once

#include <Sp/Scene2dLayer.h>

#include <QMetaType>
#include <QSizeF>

class QPainter;

namespace sp {

class QuickPainterScene2dLayer;

/**
 *  @brief Слоя сцены Scene2d для отрисовки через QPainter в Qt Quick.
 *  @sa QPainterScene2dLayerItem
 */
class PainterScene2dLayer final : public Scene2dLayer {
public:
    PainterScene2dLayer() = default;
    ~PainterScene2dLayer() override = default;
    DELETE_COPY_MOVE_CONSTRUCTOR(PainterScene2dLayer)

    /**
     *  @brief Отрисовывает графические объекты на слое через QPainter.
     *  Во время вызова записывает аргумент painer во внутренее поле _painter.
     *  Которое потом используется при отрисовке визуальных объектов.
     *  @sa painter
     */
    void paint(QPainter * painter);

    /** @brief Возвращает временный указатель на QPainter во время вызова paint. */
    inline QPainter * painter() const { return _painter; }

    /** @brief Устанавливает Quick Item, отображающий соотвествующий слой. */
    void setScene2dLayerItem(QuickPainterScene2dLayer * scene2dLayerItem);

    /** @brief Возвращает размер слоя на сцене. */
    QSizeF size();

    void update() final;

private:
    QuickPainterScene2dLayer * _scene2dLayerItem = nullptr;
    QPainter * _painter = nullptr;
};

} // namespace sp

Q_DECLARE_METATYPE(sp::PainterScene2dLayer *)
