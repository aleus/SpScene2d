#pragma once

#include "Sp/Scene2d.h"

#include <QQuickItem>

namespace sp
{

/**
 * @brief Quick-компонент 2D сцены на базе класса Scene2d.
 * @details Для инициализации нужно в QML задать свойство scene2d.
 * При этом создаются дочерние Quick-элементы, соотвествующие слоям,
 * уже зарегестрированных в объекте scene2d.
 */
class QuickScene2d : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(sp::Scene2d * scene2d READ scene2d WRITE setScene2d NOTIFY scene2dChanged)

public:
    QuickScene2d();

    inline Scene2d * scene2d() { return _scene2d; }
    inline const Scene2d * scene2d() const { return _scene2d; }

    void setScene2d(Scene2d * scene2d);

signals:
    void scene2dChanged();

private:
    void createLayers();
    void onWidthChanged();
    void onHeightChanged();

private:
    Scene2d * _scene2d = nullptr;
};

} // namespace sp
