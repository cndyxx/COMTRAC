import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "./Components"

Item {

    property int intakeCount: 1
    property int pageState: 0
    property var medication: medModel.singleMedication
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
    DialogTemplate {
        id: dialog
        deleteSymptom: false
        dialogText: qsTr("Medikament wirklich löschen?")

        Layout.alignment: Qt.Vertical
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
            enabled: pageState === 0 || pageState === 2 //aktiviert wenn status 0 und 2
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
            enabled: pageState === 0 || pageState === 2 //aktiviert wenn status 0 und 2
            currentIndex: {
                if(pageState != 0){
                    return intakePerDay;
                } else {
                    return 1;
                }
            }

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
                text: "TEST"

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
                text: {
                    if(pageState === 0)
                        return qsTr("Abbrechen");
                    else if (pageState === 1)
                        return qsTr("Zurück");
                    else
                        return qsTr("Löschen");
                }
                buttonWidth: parent.width/2
                Layout.fillWidth: true
                onClicked: {
                    if(pageState === 0) {
                        stackView.pop();
                        stackView.pop();
                    }
                    else if(pageState ===1){
                        stackView.pop();
                    }

                    else if(pageState === 2){
                        dialog.open()
                    }

                }
            }
            ButtonTemplate {
                text:  {
                    if(pageState === 0)
                        return qsTr("Eintragen");
                    else if (pageState === 1)
                        return qsTr("Bearbeiten");
                    else
                        return qsTr("Ändern");
                }
                Layout.fillWidth: true
                buttonWidth: parent.width / 2
                onClicked: {
                    //Überpüfe welcher RadioButton ausgewählt
                    if (radioButtonTimeOfTaking.checked) {
                        var radioButtonValue = radioButtonTimeOfTaking.text
                    } else {
                        radioButtonValue = radioButtonTenMinutesBefore.text
                    }
                    //Neues Symptom zur Datenbank hinzufügen
                    if(pageState === 0) {
                        //medModel.addMedications(symptomInput.text, sliderIntensity.value, sliderFrequency.value, radioButtonValue, txtDate.text,  txtTime.text);
                        stackView.pop()
                        stackView.pop()
                    }
                    else if(pageState ===1){

                        pageState = 2;
                    }
                    //Symptom in der Datenbank ändern
                    else if(pageState === 2){
                        //symptomModel.updateSymptom(symptomInput.text, sliderIntensity.value, sliderFrequency.value, radioButtonValue);
                        stackView.pop()

                    }
                }
            }
        }
    }
}






