import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"


Item {
    property string value: ""
    signal textEntered(string text)
    Connections {
        target: editMedication // Verweise auf die Instanz der "findMedication.qml"-Seite
        onTextEntered: {
            var enteredText = text // Empfange den eingegebenen Text
            console.log("Eingegebener Text:", enteredText)
            // Führe weitere Aktionen mit dem empfangenen Text aus
        }
    }

    anchors.centerIn: parent.centerIn
    Background {id: background}
    HeaderTemplate {id: header;pageTitle: "Medikamente"}

    ColumnLayout {
        y: 218
        anchors.horizontalCenterOffset: 2
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            text: "Medikament"
            color: "black"
            font.pixelSize: 23
            Layout.fillWidth: true
            opacity: 0.8
            font.family: "Arial"
            lineHeight: 0.5
        }

        TextField {
            id: medicationInput
            Layout.fillWidth: true
            font.pixelSize: 17
            opacity: 0.8
            font.family: "Arial"
            color: "black"
            placeholderText: qsTr("Hier eingeben")
            onAccepted: {
                value= text // Erfasse den eingegebenen Text
                textEntered(medicationInput.text)
                stackView.push("editMedication.qml")
            }
        }
    }
}
