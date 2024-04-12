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

    MouseArea {
        anchors.fill: parent
        onClicked: {
            AppContext.debugPrivateSignal();
        }
    }
}
