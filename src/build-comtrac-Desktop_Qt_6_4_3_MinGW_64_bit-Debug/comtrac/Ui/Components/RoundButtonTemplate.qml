import QtQuick
import QtQuick.Controls
import QtQuick.Layouts



Button {
    property string buttonIcon
    width: 65
    height: 65

    background: Rectangle {
        color: "grey"
        radius: 45
    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: buttonIcon
        color: "white"
        font.pixelSize: 30
    }
}

