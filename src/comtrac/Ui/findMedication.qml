import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"


Item {

    anchors.centerIn: parent.centerIn
    Background {id: background}
    HeaderTemplate {id: header;pageTitle: "Medikamente"}

    ColumnLayout {
        y: 212
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: parent.left
        anchors.leftMargin: 10
        Text {
            text: "Medikament"
            color: "black"
            font.pixelSize: 23
            Layout.fillWidth: true
            font.family: "Arial"

        }

        TextField {
            id: medicationInput
            Layout.fillWidth: true
            font.pixelSize: 17
            font.family: "Arial"
            color: "black"
            placeholderText: qsTr("Hier eingeben")
            onAccepted: {
                stackView.push("editMedication.qml")
            }
        }
    }
}
