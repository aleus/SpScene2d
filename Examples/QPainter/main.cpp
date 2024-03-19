#include "QPainterScene2dLayer.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char * argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    qmlRegisterType<sp::QPainterScene2dLayer>("SP", 1, 0, "PainterScene2dLayer");

    QQmlApplicationEngine engine;
    engine.load("qrc:/main.qml");

    return app.exec();
}
