import QtQuick.Controls 2.0
import QtQuick 2.0


TextField {
    id: root
    property color checkedColor: "#D5DBDB"
    property int textFieldWidth: 213
    property int textFieldHeight: 50

   // placeholderText: qsTr("Please enter content")
    font.family: "Arial"
    font.pixelSize: 17
    font.weight: Font.Thin
    color: "black"
    antialiasing: true
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter

    background: Rectangle {
        implicitWidth: textFieldWidth
        implicitHeight: textFieldHeight
        radius: 8
        color: "#F4F6F6"
        border.color: "dimgrey"
        border.width: 2
        opacity: root.enabled ? 1 : 0.7
        layer.enabled: root.hovered

    }


}
