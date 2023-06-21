import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Button {
    id: root
    anchors.horizontalCenter: parent.horizontalCenter
    width: parent.width * 0.9
    height: 50
    contentItem: Text {
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
        color: "lightgrey"
        radius: 5
        border.color: "dimgrey"
        border.width: 2

    }


}

