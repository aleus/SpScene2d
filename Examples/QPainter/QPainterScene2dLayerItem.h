#pragma once

#include "QPainterScene2dLayer.h" // IWYU pragma: keep

#include <QQuickPaintedItem>

namespace sp
{

/** @brief Компонент отображения PainterScene2dLayer на сцене в Scene2d.qml.*/
class QPainterScene2dLayerItem : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(PainterScene2dLayer * scene2dLayer READ scene2dLayer WRITE setScene2dLayer NOTIFY scene2dLayerChanged FINAL)

public:
    QPainterScene2dLayerItem();

    void paint(QPainter * painter) override;
};

} // namespace sp
