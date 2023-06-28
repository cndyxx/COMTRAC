import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Button {
    id: root
    property color backgroundDefaultColor: "grey"
    property color backgroundPressedColor: Qt.darker(backgroundDefaultColor, 1.2)
    property color contentItemTextColor: "white"
    property color borderDefaultColor: "grey"
    property int buttonWidth: 213
    property int buttonHeight: 60
    property bool homeScreen: false


   // text: "Button"
    contentItem: Text {
        id: buttonTxt
        text: root.text
        color: root.contentItemTextColor
        font.pixelSize: 17
        font.family: "Arial"
        font.weight: Font.Thin
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        implicitWidth: buttonWidth
        implicitHeight: buttonHeight
        color: root.down ? root.backgroundPressedColor : (root.hovered ? Qt.lighter(backgroundDefaultColor, 1.2) : root.backgroundDefaultColor)
        radius: 25
        border.color: borderDefaultColor
        //layer.enabled: true
    }
}
