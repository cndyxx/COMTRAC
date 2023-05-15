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
            font.pixelSize: 17
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
            font.pixelSize: 17
        }
        Popup {
               id: popUpTimePicker
               width: 200
               height: 200
               contentItem:
                   Text{
                   id: txtReminderTime
                   anchors.bottom: row.top
                   anchors.bottomMargin: 10
                   text: "Erinnerungszeit"
                   font.family: "Arial"
                   font.pixelSize: 17

               }
               Row {
                   id: row

                   anchors.centerIn: popUpTimePicker.centerIn
                   Tumbler {
                       id: hoursTumbler
                       model: 24
                       delegate: delegateComponent
                   }

                   Tumbler {
                       id: minutesTumbler
                       model: 60
                       delegate: delegateComponent
                   }
               }
               closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
           }
        ComboBox{
            id: dropDownIntake
            model: ["Einmal am Tag", "Zweimal am Tag", "Dreimal am Tag", "Viermal am Tag"]
            anchors.top: txtIntake.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            onActivated: popUpTimePicker.open()


        }


        Text {
            id: txtReminder
            anchors.top: txtFieldTimer.bottom
            anchors.topMargin: 10
            anchors.left: parent.left
            text: qsTr("Erinnerung")
            font.family: "Arial"
            font.pixelSize: 17
        }
        SwitchTemplate{
            anchors.left: txtFieldTimer.right
            anchors.top: txtFieldTimer.bottom
            anchors.topMargin: 10
            anchors.leftMargin: 60
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
            font.pixelSize: 12
            anchors.top: radioButtonTenMinutesBefore.bottom
            anchors.topMargin: 10
            anchors.left: buttonBack.right
            text: "Eintragen"
        }


    }



}
