import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "./Components"

Item {
    property var initialTime: new Date()
    property int intakeCount: 1
    property int pageState: 0
    property var list: []
    property var medication: medModel.singleMedication
    property string name: medication.name
    property var intakeTime: medication.intakeTime
    property int intakePerDay: medication.intakePerDay
    property date reminderTime: medication.reminderTime

    Connections {
        target: medModel  // Das Symptom-Modellobjekt in QML
        function onSingleMedicationChanged() {
            // Aktualisiere das Modell der ListView
            intakeTimeListView.model = intakeTime;
            //symptomListView.model.append(symptomModel.symptoms);
        }
    }
    function getIntakeTime(){
        for(var i = 0; i < intakeCount; i++){
            list.push(intakeTimeList[i].text)
            console.log("TESTAUSGABE: " + intakeTimeList[i].text);
        }
    }

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
                    return 0;
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
                medModel.initializeIntakeTimeList(intakeCount);

            }
        }

        ListView {
            id: intakeTimeListView
            width: parent.width
            height: parent.height * 0.2
            model:  intakeTime
            currentIndex: 0
            ScrollBar.vertical: ScrollBar { active: true }
            clip: true
            spacing: 10
            delegate: ButtonTemplate{
                id: intakeTimeBtn

                property string time: "08:00 AM"

                onClicked: {
                    timePicker.currentIndex = index;
                    timePicker.open();
                }

                text: intakeTimeListView.model[index].toLocaleTimeString("hh:mm")

                TimePickerTemplate {
                    id: timePicker
//                    onSaveClicked: {
////                        time = text
////                        list.push(time)
//                    }
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
                        medModel.addMedication(medicationInput.text, intakeCount, intakeTime, radioButtonValue);
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






