#include "QmlRegister.h"
#include "QuickPainterScene2dLayer.h"
#include "QuickScene2d.h"

Q_DECLARE_METATYPE(sp::Scene2d *)

namespace sp
{

void qmlRegister()
{
    qRegisterMetaType<Scene2d *>();
    qRegisterMetaType<PainterScene2dLayer *>();

    qmlRegisterType<QuickScene2d>("SP", 1, 0, "Scene2d");
    qmlRegisterType<QuickPainterScene2dLayer>("SP", 1, 0, "PainterScene2dLayer");
}

} // namespace sp
