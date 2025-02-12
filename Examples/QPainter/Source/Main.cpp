#include "QmlAppContext.h"
#include "QmlRegister.h"
#include "Sp/IVisualObject.h"
#include "Sp/Scene2dTypes.h"
#include <RenderFilters/EmptyRenderFilter.h>
#include <RenderFilters/GeneralizationRenderFilter.h>
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
#include <easy/profiler.h>
#include <iterator>
#include <memory>

using namespace sp;

int main(int argc, char * argv[])
{
    EASY_PROFILER_ENABLE

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
    renderFilters.emplace_back(new GeneralizationRenderFilter);

    Scene2d scene2d(std::move(scene2dLayers), std::move(renderFilters));

    // Визуальные объекты для отладки
    {
        // Debug!!! Убран прямоугольник из-за его boundingBox
        // auto rectangle = std::make_shared<RectangleVisualObject>();
        // scene2d.add(rectangle);

        IVisualObjectsContainer circles;
        constexpr std::size_t circlesCount = 300000;
        circles.reserve(circlesCount);
        std::generate_n(std::back_insert_iterator<IVisualObjectsContainer>(circles),
                        circlesCount,
                        []() {
                            return std::make_shared<CircleVisualObject>(Point2dF{95., 95.}, 30.);
                        });
        scene2d.add(circles);

        scene2d.add(std::make_shared<CircleVisualObject>(Point2dF{350., 195.}, 20.));
    }

    QmlAppContext qmlAppContext(&scene2d);

    qmlRegisterSingletonInstance("SP", 1, 0, "AppContext", &qmlAppContext);

    QQmlApplicationEngine engine;

    engine.load("qrc:/Main.qml");

    int result = app.exec();
    profiler::dumpBlocksToFile("profile.prof");
    return result;
}
