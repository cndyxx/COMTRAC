import QtQuick
import QtQuick.Controls
import QtQuick.Layouts



Button {
    property string buttonIcon
    id: root
    width: 65
    height: 65

    background: Rectangle {
        color: root.down ? root.Qt.darger("grey", 1.2) : (root.hovered ? Qt.lighter("grey", 1.2) : "grey")
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

