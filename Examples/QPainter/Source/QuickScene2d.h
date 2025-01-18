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
    Q_PROPERTY(qreal scale READ scale WRITE setScale NOTIFY scaleChanged)
    Q_PROPERTY(QPointF translation READ translation WRITE setTranslation NOTIFY translationChanged)

    Q_INTERFACES(QQmlParserStatus)

public:
    QuickScene2d();

    inline Scene2d * scene2d() { return _scene2d; }
    inline const Scene2d * scene2d() const { return _scene2d; }

    void setScene2d(Scene2d * scene2d);

    qreal scale() const;
    // Debug!!! Масштабирование должно идти относительно точки курсора
    void setScale(qreal scale);

    QPointF translation() const;
    void setTranslation(const QPointF & translation);

    void componentComplete() override;

signals:
    void scene2dChanged();
    void scaleChanged();
    void translationChanged();

private:
    void createLayers();
    void updateSize();

    void onWidthChanged();
    void onHeightChanged();

private:
    Scene2d * _scene2d = nullptr;
    bool _completed = false;
    qreal _lastWidth = 0.0;
    qreal _lastHeight = 0.0;
};

} // namespace sp
