import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "./Components"

Item {

    property int intakeCount: 1
    property int pageState: 0
    property var medication: medModel.medications
    property string name: medication.name
    property var intakeTime: medication.intakeTime
    property int intakePerDay: medication.intakePerDay
    property date reminderTime: medication.reminderTime

    Background {
        id: background
    }

    HeaderTemplate {
        id: header
        pageTitle: "Medikamente"

    }

    ColumnLayout {
        anchors.fill: parent
        anchors.top: header.bottom
        anchors.topMargin: header.height
        anchors.margins: 15
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
            text: name
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
        ComboBox {

            property int intakeNumber
            textRole: "text"
            valueRole: "intakeNumber"
            model: ListModel {
                id: intakePerDayModel
                ListElement { text: "Einmal am Tag"}
                ListElement { text: "Zweimal am Tag"}
                ListElement { text: "Dreimal am Tag"}
                ListElement { text: "Viermal am Tag"}
            }
            onActivated: {
                console.log("ComboBox: " + currentIndex)
                intakeCount = currentIndex + 1;


            }

        }

        TimePickerTemplate {
            id: timePickerPopup
            popUpVisible: false
        }

        ListView {
            id: intakeTimeList
            width: parent.width
            height: parent.height * 0.2
            model:  intakeCount
            delegate: Button{
                width: parent.width
                height: 50
                text: timePickerPopup.selectedTime.toLocaleTimeString("hh:mm")
                onClicked: {
                    timePickerPopup.popUpVisible = true;
                }
            }
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

}




