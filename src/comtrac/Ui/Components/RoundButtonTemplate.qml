import QtQuick
import QtQuick.Controls
import QtQuick.Layouts



Button {
    property string buttonIcon
    width: 50
    height: 50

    background: Rectangle {
        color: "grey"
        radius: 30
    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: buttonIcon
        color: "white"
        font.pixelSize: 30
    }
}

