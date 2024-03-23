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

    Q_PROPERTY(sp::PainterScene2dLayer * scene2dLayer READ scene2dLayer WRITE setScene2dLayer NOTIFY scene2dLayerChanged REQUIRED FINAL)

public:
    QuickPainterScene2dLayer() = default;
    ~QuickPainterScene2dLayer() override;

    inline sp::PainterScene2dLayer * scene2dLayer() const { return _scene2dLayer; }
    void setScene2dLayer(PainterScene2dLayer * scene2dLayer);

    void paint(QPainter * painter) override;

signals:
    void scene2dLayerChanged();

private:
    PainterScene2dLayer * _scene2dLayer = nullptr;
};

} // namespace sp
