#include "rxcpp/rx.hpp" // IWYU pragma: keep

#include <iostream>
#include <memory>
#include <utility>

namespace rx = rxcpp;
namespace rxsub = rxcpp::subjects;
namespace rxu = rxcpp::util;

class PainterLayer {
public:
    PainterLayer(const std::string & name);
    void paint(int);

private:
    std::string _name;
};

class Scene2d {
public:
    Scene2d() = default;

    Scene2d & addLayer(std::weak_ptr<PainterLayer> && layer);

    void paint();

private:
    rxsub::subject<int> _paintSubject;
    std::vector<std::weak_ptr<PainterLayer>> _layers;

    int _callNumber = 0;
};

int main()
{
    Scene2d scene;
    auto layer0 = std::make_shared<PainterLayer>("Layer 0");
    auto layer1 = std::make_shared<PainterLayer>("Layer 1");

    scene.addLayer(layer0);
    scene.addLayer(layer1);

    scene.paint();
    scene.paint();

    return 0;
}

PainterLayer::PainterLayer(const std::string & name)
    : _name(name)
{
}

void PainterLayer::paint(int)
{
    std::cout << "PainterLayer::paint: " << _name << "\n";
}

Scene2d & Scene2d::addLayer(std::weak_ptr<PainterLayer> && layer)
{
    auto paintFun = [layer](int v) {
        auto layerPtr = layer.lock();
        if (layerPtr) {
            layerPtr->paint(v);
        }
    };

    auto sub0 = _paintSubject.get_observable()
                    .subscribe(paintFun,
                               []() { std::cout << "OnCompleted\n"; });

    _layers.push_back(std::move(layer));

    return *this;
}

void Scene2d::paint()
{
    std::cout << "Scene2d::paint\n";
    _paintSubject.get_subscriber().on_next(_callNumber++);
}
