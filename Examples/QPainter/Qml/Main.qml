import QtQuick 2.15
import QtQuick.Window 2.15
import SP 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Scend2d Example")

    Scene2d {
        id: scene2d

        scene2d: AppContext.scene2d
        anchors.fill: parent
        clip: true
    }

    // Debug!!! Отладка масштабирования колёсиком мыши
    MouseArea {
        property var lastPosition

        anchors.fill: parent
        onWheel: (wheel) =>
        {
            if (wheel.angleDelta.y > 0) {
                scene2d.scale += 0.1;
            } else {
                scene2d.scale -= 0.1;
            }
        }

        onPressed: (mouse) =>
        {
            lastPosition = Qt.point(mouse.x, mouse.y);
        }

        onPositionChanged: (mouse) =>
        {
            // Debug!!! Некрасиво выглядит - переделать
            scene2d.translation = Qt.point(scene2d.translation.x - lastPosition.x + mouse.x,
                                           scene2d.translation.y - lastPosition.y + mouse.y);
            lastPosition = Qt.point(mouse.x, mouse.y);
        }
    }
}
