import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Button {
    property string symptomName
    property string intakeTime
    anchors.horizontalCenter: parent.horizontalCenter
    width: parent.width
    height: parent.height
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: symptomName
        color: "black"
        font.pixelSize: 18
        Layout.fillWidth: true
        font.family: "Arial"
        lineHeight: 0.5
    }
    background: Rectangle {
        width: parent.width
        height: 50
        border.color: "darkgrey"
        border.width: 2
        color: "lightgrey"
        radius: 5

    }
}

