#pragma once

#include "PainterScene2dLayer.h" // IWYU pragma: keep

#include <QQuickPaintedItem>

namespace sp
{

/** @brief Компонент отображения PainterScene2dLayer на сцене в Scene2d.qml.*/
class QuickPainterScene2dLayer : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT

public:
    QuickPainterScene2dLayer();
    ~QuickPainterScene2dLayer() override;

    void setScene2dLayer(PainterScene2dLayer * Scene2dLayer);

    void paint(QPainter * painter) override;

private:
    PainterScene2dLayer * _scene2dLayer = nullptr;
};

} // namespace sp
