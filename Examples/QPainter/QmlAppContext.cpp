#include "QmlAppContext.h"

namespace sp
{

QmlAppContext::QmlAppContext(Scene2d * scene2d)
    : _scene2d(scene2d)
{
    Q_ASSERT(_scene2d);
}

} // namespace sp
