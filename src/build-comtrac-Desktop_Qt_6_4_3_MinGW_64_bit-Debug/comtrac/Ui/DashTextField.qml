import QtQuick.Controls 2.0
import QtQuick 2.0


TextField {
    id: root

    property color checkedColor: "#D5DBDB"


    placeholderText: qsTr("Please enter content")
    font.family: "Arial"
    font.pixelSize: 15
    font.weight: Font.Thin
    antialiasing: true

    background: Rectangle {
        implicitWidth: 213
        implicitHeight: 42
        radius: 8
        color: root.enabled ? "transparent" :"#F4F6F6"
        border.color: root.enabled ? root.checkedColor : "#D5DBDB"
        border.width: 2
        opacity: root.enabled ? 1 : 0.7

        layer.enabled: root.hovered

    }


}
