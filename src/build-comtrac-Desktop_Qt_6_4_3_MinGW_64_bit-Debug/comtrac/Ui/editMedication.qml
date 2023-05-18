import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: editMedication
    width: 250
    height: 500
    anchors.centerIn: parent.centerIn


    HeaderTemplate{
        id: headerMedication
        pageTitle: "Medikation"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ColumnLayout {
        id: gridLayout
        x: 7
        anchors.top: headerMedication.bottom
        anchors.topMargin: 10
        spacing: 5

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
            font.family: "Arial"
            font.pixelSize: 17
            Layout.fillWidth: true
            text: qsTr("Ibuprofen")
            color: "dimgrey"

        }
        Rectangle {
            id: line
            width: parent.width
            height: 2
            anchors.top: txtFieldMedication.bottom
            anchors.topMargin: 3
            color: "dimgrey"
        }
        Text {
            id: txtIntake
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
            onCurrentIndexChanged: {
               //do something
            }


        }
        //Muss sich ändern sobald ein Feld aus der ComboBox geänder hat. Dynamisch erstellen
        TextFieldTemplate{
            id: timerOne

        }
        TextFieldTemplate{
            id: timerTwo

        }
        RowLayout{
            Text {
                id: txtReminder
                text: qsTr("Erinnerung")
                font.family: "Arial"
                font.pixelSize: 23
            }
            SwitchTemplate{
                id: switchReminder
                anchors.left: txtReminder.right
                anchors.leftMargin: 60
            }
        }


        RadioButtonTemplate{
            id: radioButtonTimeOfTaking
            text: qsTr("Zum Zeitpunkt der Einnahme")
            font.pixelSize: 15
        }
        RadioButtonTemplate{
            id: radioButtonTenMinutesBefore
            text: qsTr("10 Minuten vorher")
            font.pixelSize: 15
        }
        RadioButtonTemplate{
            id: radioButtonAddReminder
            text: qsTr("Mehr")
            font.pixelSize: 15


        }
        ButtonTemplate{
            id: buttonBack
            text: qsTr("Zurück")
            width: 80
            height: 40

        }
        ButtonTemplate{
            id: buttonAdd
            anchors.left: buttonBack.right
            anchors.top: radioButtonAddReminder.bottom
            anchors.topMargin: 5
            anchors.leftMargin: 10
            text: qsTr("Eintragen")
            width: 80
            height: 40
        }


    }



}
