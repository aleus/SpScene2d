#include "QmlAppContext.h"
#include <QDebug>

namespace sp
{

QmlAppContext::QmlAppContext(Scene2d * scene2d)
    : _scene2d(scene2d)
{
    Q_ASSERT(_scene2d);

    connect(this, &QmlAppContext::debugPrivateSignal, this, []() {
        qDebug() << "Slot of debugPrivateSignal";
    });
}

} // namespace sp
