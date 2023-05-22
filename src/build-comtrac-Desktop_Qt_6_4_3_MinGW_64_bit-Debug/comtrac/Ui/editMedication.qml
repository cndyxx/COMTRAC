import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "./Components"

Item {
    property alias medicationName : medicationInput.text
    Background { id: background

    }

    HeaderTemplate {
        id: header
        pageTitle: "Medikamente"

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
            text: "Medikament"
            color: "black"
            font.pixelSize: 23
            Layout.fillWidth: true
            font.family: "Arial"
        }
        TextInput {
            id: medicationInput
            Layout.fillWidth: true
            font.pixelSize: 17
            font.family: "Arial"
            color: "black"
            text: medicationName
            focus: true
            Rectangle {
                width: header.width
                height: 2
                color: "grey"
                anchors.top: medicationInput.bottom
                anchors.topMargin: 5
            }
        }

        Text {
            text: "Einnahme"
            Layout.topMargin: 20
            color: "black"
            font.pixelSize: 23
            Layout.fillWidth: true
            font.family: "Arial"
        }
        ComboBoxTemplate {
            id: intakePerDayInput
            Layout.fillWidth: true

            Rectangle {
                width: parent.width
                height: 2
                color: "grey"
                anchors.top: intakePerDayInput.bottom
                anchors.topMargin: 5
            }

        }

        IntakeTimeList {
            id: intakeList
            width: header.width
            height: 50
        }


    }




    ColumnLayout {
        anchors.top: grid.bottom
        anchors.topMargin: intakeList.height + 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        //Abstand zum Header
        spacing: 10

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

        RowLayout {
            ButtonTemplate {
                text: qsTr("Abbrechen")
                // onClicked: toDoList.appendItem()
                buttonWidth: parent.width/2
                Layout.fillWidth: true
                onClicked: {
                    stackView.pop();
                    stackView.pop()
                }
            }
            ButtonTemplate {
                text: qsTr("Eintragen")
                //onClicked: toDoList.removeCompletedItems()
                Layout.fillWidth: true
                buttonWidth: parent.width / 2
                // onClicked: medModel.addMedication(medicationInput.text,intakePerDayInput,  )
            }
        }

    }







    //    ColumnLayout {
    //        id: gridLayout
    //        x: 7
    //        anchors.topMargin: 10
    //        spacing: 5

    //        Text {
    //            Layout.alignment: parent.left
    //           // anchors.left: parent.left
    //            id: txtMedication
    //            text: qsTr("Medikament")
    //            font.family: "Arial"
    //            font.pixelSize: 23
    //        }

    //        Text{
    //            id: txtFieldMedication
    //            font.family: "Arial"
    //            font.pixelSize: 17
    //            Layout.fillWidth: true
    //            text: qsTr("Ibuprofen")
    //            color: "black"

    //        }
    //        Rectangle {
    //            id: line
    //            width: parent.width
    //            height: 2
    //            anchors.top: txtFieldMedication.bottom
    //            anchors.topMargin: 3
    //            color: "dimgrey"
    //        }
    //        Text {
    //            id: txtIntake
    //            text: qsTr("Einnahme")
    //            font.family: "Arial"
    //            font.pixelSize: 23

    //        }
    //        PopupTemplate{
    //            id: popup
    //        }

    //        ComboBoxTemplate{
    //            id: dropDownIntake
    //            model: ["Einmal am Tag", "Zweimal am Tag", "Dreimal am Tag", "Viermal am Tag"]
    //            onCurrentIndexChanged: {
    //               //do something
    //            }


    //        }
    //        //Muss sich ändern sobald ein Feld aus der ComboBox geänder hat. Dynamisch erstellen
    //        TextFieldTemplate{
    //            id: timerOne

    //        }
    //        TextFieldTemplate{
    //            id: timerTwo

    //        }
    //
    //        ButtonTemplate{
    //            id: buttonBack
    //            text: qsTr("Zurück")
    //            width: 80
    //            height: 40

    //        }
    //        ButtonTemplate{
    //            id: buttonAdd
    //            anchors.left: buttonBack.right
    //            anchors.top: radioButtonAddReminder.bottom
    //            anchors.topMargin: 5
    //            anchors.leftMargin: 10
    //            text: qsTr("Eintragen")
    //            width: 80
    //            height: 40
    //        }


    //    }



}
