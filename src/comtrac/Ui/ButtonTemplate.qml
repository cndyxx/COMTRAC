import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Button {
    id: root
    property color backgroundDefaultColor: "#4E5BF2"
    property color backgroundPressedColor: Qt.darker(backgroundDefaultColor, 1.2)
    property color contentItemTextColor: "white"


   // text: "Button"
    contentItem: Text {
        text: root.text
        color: root.contentItemTextColor
        font.pixelSize: 15
        font.family: "Arial"
        font.weight: Font.Thin
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: 213
        implicitHeight: 50
        color: root.down ? root.backgroundPressedColor : root.backgroundDefaultColor
        radius: 15
        //layer.enabled: true
    }
}
