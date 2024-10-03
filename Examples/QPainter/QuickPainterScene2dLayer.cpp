#include "QuickPainterScene2dLayer.h"

#include <QPainter>

namespace sp
{

QuickPainterScene2dLayer::~QuickPainterScene2dLayer()
{
    if (_scene2dLayer) {
        _scene2dLayer->setScene2dLayerItem(nullptr);
    }
}

void QuickPainterScene2dLayer::paint(QPainter * painter)
{
    if (_scene2dLayer) {
        _scene2dLayer->paint(painter);
    } else {
        Q_ASSERT_X(false, "QuickPainterScene2dLayer", "scene2dLayer must be set before first paint");
    }
}

void QuickPainterScene2dLayer::setScene2dLayer(PainterScene2dLayer * scene2dLayer)
{
    if (_scene2dLayer != scene2dLayer) {
        _scene2dLayer = scene2dLayer;
        _scene2dLayer->setScene2dLayerItem(this);

        emit scene2dLayerChanged();
    }
}

} // namespace sp
