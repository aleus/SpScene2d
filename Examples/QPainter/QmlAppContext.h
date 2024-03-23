#pragma once

#include "Sp/Scene2d.h"

#include <QObject>

namespace sp
{

class QmlAppContext : public QObject
{
    Q_OBJECT

    Q_PROPERTY(sp::Scene2d * scene2d READ scene2d CONSTANT)

public:
    QmlAppContext(Scene2d * scene2d);

    inline Scene2d * scene2d() { return _scene2d; }
    inline const Scene2d * scene2d() const { return _scene2d; }

private:
    Scene2d * _scene2d = nullptr;
};

} // namespace sp
