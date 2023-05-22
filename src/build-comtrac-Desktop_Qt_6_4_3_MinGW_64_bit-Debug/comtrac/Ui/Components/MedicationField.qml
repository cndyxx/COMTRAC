import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    property string medicationName
    property string intakeTime
    anchors.horizontalCenter: parent.horizontalCenter
    Button {
        width: parent.width
        height: parent.height

        contentItem: ColumnLayout {
            width: parent.width
            height: parent.height
            spacing: 5
            Text {
                text: medicationName
                color: "black"
                font.pixelSize: 18
                Layout.fillWidth: true
                font.family: "Arial"
                lineHeight: 0.5
            }
            Text {
                text: "Einnahme: " + intakeTime
                color: "black"
                font.pixelSize: 16
                Layout.fillWidth: true
                font.family: "Arial"
                lineHeight: 0.5
            }
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
}
