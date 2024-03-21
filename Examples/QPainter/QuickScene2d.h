#pragma once

#include <QQuickItem>

namespace sp
{

class QuickScene2d : public QQuickItem
{
    Q_OBJECT
    QML_ELEMENT

public:
    QuickScene2d();

    void componentComplete() final;
};

} // namespace sp
