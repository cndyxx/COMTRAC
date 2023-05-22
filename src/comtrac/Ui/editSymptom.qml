import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "./Components"

Item {
    property string symptomName
    Background { id: background}

    HeaderTemplate {
        id: header
        pageTitle: "Symptom hinzufügen"

    }

    ColumnLayout {
        id: grid
        anchors.top: header.bottom
        anchors.left: parent.left
        anchors.leftMargin: 10
        //Abstand zum Header
        anchors.margins: 30
        spacing: 10

        Text {
            text: "Symptom"
            color: "black"
            font.pixelSize: 23
            Layout.fillWidth: true
            font.family: "Arial"
        }
        TextInput {
            id: symptomInput
            Layout.fillWidth: true
            font.pixelSize: 17
            font.family: "Arial"
            color: "black"
            text: symptomName
            focus: true
            Rectangle {
                width: header.width
                height: 2
                color: "grey"
                anchors.top: symptomInput.bottom
                anchors.topMargin: 5
            }
        }

        Text {
            text: "Intensität: "
            Layout.topMargin: 20
            color: "black"
            font.pixelSize: 17
            Layout.fillWidth: true
            font.family: "Arial"
        }
        SliderTemplate {

        }

        Text {
            text: "Häufigkeit pro Tag: "
            Layout.topMargin: 20
            color: "black"
            font.pixelSize: 17
            Layout.fillWidth: true
            font.family: "Arial"
        }
        SliderTemplate {

        }
        Text {
            text: "Dauer des Auftretens: "
            Layout.topMargin: 20
            color: "black"
            font.pixelSize: 17
            Layout.fillWidth: true
            font.family: "Arial"
        }

        RadioButtonTemplate{
            text: qsTr("Seit weniger als 24 Stunden")
            font.pixelSize: 15
        }
        RadioButtonTemplate{
            id: radioButtonTenMinutesBefore
            text: qsTr("Seit mehr als 24 Stunden")
            font.pixelSize: 15
        }
        RowLayout {
            ButtonTemplate {
                text: qsTr("Abbrechen")
                buttonWidth: parent.width/2
                Layout.fillWidth: true
                onClicked: {
                    stackView.pop();
                    stackView.pop()
                }
            }
            ButtonTemplate {
                text: qsTr("Eintragen")
                Layout.fillWidth: true
                buttonWidth: parent.width / 2
                // onClicked:
            }
        }
    }
}

