import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"

Item {
    property alias targetValue: findMedication.value

    width: parent.width
    height: parent.height

    Background { id: background}

    HeaderTemplate {
        id: header
        pageTitle: "Medikamente"
    }

    ColumnLayout {
        anchors.top: header.bottom

        Text {
            text: pageTitle
            color: "black"
            font.pixelSize: 23
            Layout.fillWidth: true
            opacity: 0.8
            font.family: "Arial"
            lineHeight: 0.5
        }

        Text {
            id: medicationInput
            Layout.fillWidth: true
            font.pixelSize: 17
            opacity: 0.8
            font.family: "Arial"
            color: "black"
           // text: qsTr(targetValue)
            onAccepted: {
                var medicationInput = text // Erfasse den eingegebenen Text

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
    //        RowLayout{
    //            Text {
    //                id: txtReminder
    //                text: qsTr("Erinnerung")
    //                font.family: "Arial"
    //                font.pixelSize: 23
    //            }
    //            SwitchTemplate{
    //                id: switchReminder
    //                anchors.left: txtReminder.right
    //                anchors.leftMargin: 60
    //            }
    //        }


    //        RadioButtonTemplate{
    //            id: radioButtonTimeOfTaking
    //            text: qsTr("Zum Zeitpunkt der Einnahme")
    //            font.pixelSize: 15
    //        }
    //        RadioButtonTemplate{
    //            id: radioButtonTenMinutesBefore
    //            text: qsTr("10 Minuten vorher")
    //            font.pixelSize: 15
    //        }
    //        RoundButton{
    //            id: radioButtonAddReminder

    //            width: 26; height: width


    //        }
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
