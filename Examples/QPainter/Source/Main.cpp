#include "CircleVisualObject.h"
#include "EmptyRenderFilter.h"
#include "PainterScene2dLayer.h"
#include "QmlAppContext.h"
#include "QmlRegister.h"
#include "RectangleVisualObject.h"
#include "qqml.h"

#include <Sp/Scene2d.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

using namespace sp;

int main(int argc, char * argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegister();

    Scene2dLayers scene2dLayers;
    scene2dLayers.emplace_back(new PainterScene2dLayer);
    scene2dLayers.emplace_back(new PainterScene2dLayer);

    RenderFilters renderFilters;
    renderFilters.emplace_back(new EmptyRenderFilter);

    Scene2d scene2d(std::move(scene2dLayers), std::move(renderFilters));

    auto rectangle = std::make_shared<RectangleVisualObject>();
    auto circle = std::make_shared<CircleVisualObject>();
    scene2d.add(rectangle);
    scene2d.add(circle);

    scene2d.update();

    QmlAppContext qmlAppContext(&scene2d);

    qmlRegisterSingletonInstance("SP", 1, 0, "AppContext", &qmlAppContext);

    QQmlApplicationEngine engine;

    engine.load("qrc:/Main.qml");

    return app.exec();
}
