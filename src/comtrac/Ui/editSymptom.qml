import QtQuick
import "./Components"

Item {
    Column{

        anchors.centerIn: parent
        spacing: 6
        Text {
            id: txtSymptom
            text: qsTr("Symptom")
            font.family: "Arial"
            font.pixelSize: 23
        }
        TextFieldTemplate{
            //Wert von Funktion holen
            text: "Fieber"
        }
        Text {
            id: txtIntensity
            text: qsTr("Intensität")
            font.family: "Arial"
            font.pixelSize: 17
        }
        SliderTemplate{
        }
        Text {
            id: txtFrequency
            text: qsTr("Häufigkeit pro Tag:")
            font.family: "Arial"
            font.pixelSize: 17
        }
        SliderTemplate{
        }
        Text {
            id: txtDuration
            text: qsTr("Dauer")
            font.family: "Arial"
            font.pixelSize: 17
        }
        RadioButtonTemplate{
            text: qsTr("Seit weniger als 24h")
        }
        RadioButtonTemplate{
            text: qsTr("Seit mehr als 24h")
        }

        ButtonTemplate{
            id: addButton
            text: "Eintragen"
        }
        ButtonTemplate{
            text: "Zurück"
            anchors.left: addButton.left
        }


    }

}
