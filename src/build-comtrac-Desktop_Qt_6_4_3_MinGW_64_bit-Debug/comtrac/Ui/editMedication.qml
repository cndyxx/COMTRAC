import QtQuick

Item {
    Column{

        anchors.centerIn: parent
        spacing: 6
        Text {
            id: txtMedication
            text: qsTr("Medikament")
            font.family: "Arial"
            font.pixelSize: 23
        }
        TextFieldTemplate{
            //Wert von Funktion holen
            text: "Ibuprofen"
        }
        Text {
            id: txtIntake
            text: qsTr("Einnahme")
            font.family: "Arial"
            font.pixelSize: 17
        }


        Text {
            id: txtReminder
            text: qsTr("Erinnerung")
            font.family: "Arial"
            font.pixelSize: 17
        }
        SwitchTemplate{
        }
        RadioButtonTemplate{
            text: qsTr("Zum Zeitpunkt der Einnahme")
        }
        RadioButtonTemplate{
            text: qsTr("10 Minuten vorher")
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
