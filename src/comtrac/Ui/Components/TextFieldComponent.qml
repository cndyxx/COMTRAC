import QtQuick
import QtQuick.Controls

Item {
    property string placeholderText
    TextField {
        id: input
        Layout.fillWidth: true
        font.pixelSize: 17
        font.family: "Arial"
        color: "black"
        placeholderText: qsTr(placeholderText)
        background: Rectangle {
            id: recInput
            implicitWidth: 213
            implicitHeight: 30
            color: "white"
            Rectangle {
                width: parent.width
                height: 2
                color: "grey"
                anchors.top: recInput.bottom
            }
        }
    }
}
