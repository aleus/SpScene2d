#include "QuickPainterScene2dLayer.h"

#include <QPainter>

using namespace sp;

QuickPainterScene2dLayer::QuickPainterScene2dLayer()
{
}

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
    }
}

void QuickPainterScene2dLayer::setScene2dLayer(PainterScene2dLayer * Scene2dLayer)
{
    if (_scene2dLayer == Scene2dLayer)
        return;

    _scene2dLayer = Scene2dLayer;
    _scene2dLayer->setScene2dLayerItem(this);
}
