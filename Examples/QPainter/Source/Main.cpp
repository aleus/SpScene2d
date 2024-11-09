#include "QmlAppContext.h"
#include "QmlRegister.h"
#include "Sp/IVisualObject.h"
#include <RenderFilters/EmptyRenderFilter.h>
#include <RenderFilters/SceneClipRenderFilter.h>
#include <Scene2dLayers/PainterScene2dLayer.h>
#include <VisualObjects/CircleVisualObject.h>
#include <VisualObjects/RectangleVisualObject.h>

#include <Sp/Scene2d.h>
#include <Sp/Scene2dLayer.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <algorithm>
#include <iterator>
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
    renderFilters.emplace_back(new SceneClipRenderFilter);
    renderFilters.emplace_back(new EmptyRenderFilter);

    Scene2d scene2d(std::move(scene2dLayers), std::move(renderFilters));

    // Визуальные объекты для отладки
    {
        auto rectangle = std::make_shared<RectangleVisualObject>();
        scene2d.add(rectangle);

        IVisualObjectsContainer circles;
        constexpr std::size_t circlesCount = 2;
        circles.reserve(circlesCount);
        std::generate_n(std::back_insert_iterator<IVisualObjectsContainer>(circles),
                        circlesCount,
                        []() {
                            return std::make_shared<CircleVisualObject>();
                        });
        scene2d.add(circles);
    }

    scene2d.update();

    QmlAppContext qmlAppContext(&scene2d);

    qmlRegisterSingletonInstance("SP", 1, 0, "AppContext", &qmlAppContext);

    QQmlApplicationEngine engine;

    engine.load("qrc:/Main.qml");

    return app.exec();
}