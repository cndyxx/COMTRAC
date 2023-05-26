import QtQuick 2.0
import QtQuick.Controls 2.0



Slider {
    property color checkedColor: "grey"

    background: Rectangle {
        x: parent.leftPadding
        y: parent.topPadding + parent.availableHeight / 2 - height / 2
        implicitWidth: 200
        implicitHeight: 12
        width: parent.availableWidth
        height: implicitHeight
        radius: height / 2
        color: "#EBEDEF"


        Rectangle {
            width: parent.visualPosition = 0 ? 0 : parent.handle.x + parent.handle.width / 2
            height: parent.height
            color: parent.checkedColor
            radius: height / 2
            layer.enabled: parent.hovered | parent.pressed

        }
    }


    handle: Rectangle {
        x: parent.leftPadding + parent.visualPosition * (parent.availableWidth - width)
        y: parent.topPadding + parent.availableHeight / 2 - height / 2
        implicitWidth: parent.background.implicitHeight + 6
        implicitHeight: implicitWidth
        radius: implicitWidth / 2
        color: parent.pressed ? Qt.darker(parent.checkedColor, 1.2) : parent.checkedColor
        border.color: Qt.darker(parent.checkedColor, 0.93)
        layer.enabled: parent.hovered | parent.pressed

    }
}

