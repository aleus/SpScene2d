#include "PainterScene2dLayer.h"
#include "QmlAppContext.h"
#include "QuickPainterScene2dLayer.h"
#include "QuickScene2d.h"
#include "qqml.h"

#include <Sp/Scene2d.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char * argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    sp::Scene2dLayers scene2dLayers;
    scene2dLayers.emplace_back(new sp::PainterScene2dLayer());
    scene2dLayers.emplace_back(new sp::PainterScene2dLayer());

    sp::Scene2d scene2d(std::move(scene2dLayers));

    qmlRegisterType<sp::QuickScene2d>("SP", 1, 0, "Scene2d");
    qmlRegisterType<sp::QuickPainterScene2dLayer>("SP", 1, 0, "PainterScene2dLayer");

    sp::QmlAppContext qmlAppContext;

    qmlRegisterSingletonInstance("SP", 1, 0, "QmlAppContext", &qmlAppContext);

    QQmlApplicationEngine engine;

    engine.load("qrc:/Main.qml");

    return app.exec();
}
