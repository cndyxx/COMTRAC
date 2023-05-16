import QtQuick
import QtQuick.Controls
import QtQuick.Layouts



Item {



    ColumnLayout {
        id: gridLayout
        anchors.left: parent.left
        anchors.leftMargin: -110
        anchors.top: parent.top
        anchors.topMargin: -200


        Text {
            Layout.alignment: parent.left
           // anchors.left: parent.left
            id: txtMedication
            text: qsTr("Medikament")
            font.family: "Arial"
            font.pixelSize: 23
        }

        Text{
            id: txtFieldMedication
            anchors.top: txtMedication.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            font.family: "Arial"
            font.pixelSize: 15
            Layout.fillWidth: true
            text: qsTr("Beispiel Medikament")
        }
        Text {
            id: txtIntake
            anchors.top: txtFieldMedication.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            text: qsTr("Einnahme")
            font.family: "Arial"
            font.pixelSize: 23
        }
        PopupTemplate{
            id: popup
        }

        ComboBoxTemplate{
            id: dropDownIntake
            model: ["Einmal am Tag", "Zweimal am Tag", "Dreimal am Tag", "Viermal am Tag"]
            anchors.top: txtIntake.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            onCurrentIndexChanged: {
               //do something
            }


        }
        //Muss sich ändern sobald ein Feld aus der ComboBox geänder hat. Dynamisch erstellen
        TextFieldTemplate{
            id: timerOne
            anchors.top: dropDownIntake.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
        }
        TextFieldTemplate{
            id: timerTwo
            anchors.top: timerOne.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
        }

        Text {
            id: txtReminder
            anchors.top: timerTwo.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            text: qsTr("Erinnerung")
            font.family: "Arial"
            font.pixelSize: 23
        }
        SwitchTemplate{
            anchors.left: txtReminder.right
            anchors.top: txtFieldTimer.bottom
            anchors.topMargin: 10
            anchors.leftMargin: 55
        }

        RadioButton{
            id: radioButtonTimeOfTaking
            anchors.top: txtReminder.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            text: qsTr("Zum Zeitpunkt der Einnahme")
        }
        RadioButton{
            id: radioButtonTenMinutesBefore
            anchors.top: radioButtonTimeOfTaking.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            text: qsTr("10 Minuten vorher")
        }
        Button{
            id: buttonBack
            text: qsTr("Zurück")
            anchors.left: parent.left
            anchors.top: radioButtonTenMinutesBefore.bottom
            anchors.topMargin: 10

        }
        Button{
            id: buttonAdd
            width: 50
            font.pixelSize: 15
            anchors.top: radioButtonTenMinutesBefore.bottom
            anchors.topMargin: 10
            anchors.left: buttonBack.right
            text: "Eintragen"
        }


    }



}
