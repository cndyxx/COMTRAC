import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "./Components"

Item {

    // 0: Leer (Eingabe)
    // 1: Datenanzeige
    // 2: Datenanzeige mit aktivierten Feldern
    property int pageState: 0
    property var symptom: symptomModel.singleSymptom
    property string name: symptom.name
    property string intensity: symptom.intensity
    property int frequency: symptom.frequency
    property string duration: symptom.duration
    property date entryTime: symptom.entryTime
    property date entryDate: symptom.entryDate
    property date currentTime: new Date()
    property date currentDate: new Date()



    Background { id: background}

    HeaderTemplate {
        id: header
        pageTitle: "Symptom hinzufügen"

    }
    DialogTemplate {
        id: dialog
        //dialogVisible: false
        dialogText: qsTr("Symptomeintrag wirklich löschen?")

        Layout.alignment: Qt.Vertical
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.top: header.bottom
        anchors.topMargin: header.height
        anchors.margins: 15

        spacing: 10

        //Auslagern !!
        GridLayout {
            columns: 2
            rows: 2
            Label {
                text: "Datum"
                color: "grey"
                font.pixelSize: 12
            }
            Label {
                text: "Uhrzeit"
                color: "grey"
                font.pixelSize: 12
            }
            Text {
                id: txtDate
                text:  {
                    if(pageState !== 0)
                        return entryDate.toLocaleDateString("dd.MM.yyyy");
                    else
                        return currentDate.toLocaleDateString("dd.MM.yyyy");
                }
                color: "grey"
                font.pixelSize: 15
            }

            Text {
                id: txtTime
                text: {
                    if(pageState !== 0)
                        return entryDate.toLocaleTimeString(Qt.locale("de_DE"), "hh:mm");
                    else
                        return currentTime.toLocaleTimeString(Qt.locale("de_DE"), "hh:mm");
                }
                color: "grey"
                font.pixelSize: 15
            }
        }

        Label {
            id: txtSymptom
            text: "Symptom"
            color: "black"
            font.pixelSize: 23
            font.family: "Arial"
        }
        TextEdit {
            id: symptomInput
            Layout.fillWidth: true
            font.pixelSize:17
            font.family: "Arial"
            color: "black"
            //            text: symptomName
            text: name
            focus: true
            enabled: pageState === 0 || pageState === 2 //aktiviert wenn status 0 und 2
            Rectangle {
                width: header.width * 0.9
                height: 2
                color: "grey"
                anchors.top: parent.bottom

            }

        }

        RowLayout {
            Text {
                text: "Intensität: "
                color: "black"
                font.pixelSize: 17
                Layout.fillWidth: true
                font.family: "Arial"
            }
            Text {
                Layout.fillWidth: true
                text: {
                    if (sliderIntensity.value === 0)
                        return "leicht";
                    else if (sliderIntensity.value === 1)
                        return "mäßig";
                    else if (sliderIntensity.value === 2)
                        return "schwer";
                }
                font.pixelSize: 16
            }
        }

        SliderTemplate {
            id: sliderIntensity
            width: parent.width
            from: 0
            to: 2
            stepSize: 1
            Layout.fillWidth: true
            enabled: pageState === 0 || pageState === 2 //aktiviert wenn status 0 und 2
            value: intensity

        }

        RowLayout {
            Text {
                text: "Häufigkeit pro Tag: "
                color: "black"
                font.pixelSize: 17
                Layout.fillWidth: true
                font.family: "Arial"
            }
            Text {
                text: sliderFrequency.value.toFixed(0)
                font.pixelSize: 16
                Layout.fillWidth: true
            }
        }
        SliderTemplate {
            id: sliderFrequency
            from: 0
            to: 9
            stepSize: 1
            Layout.fillWidth: true
            enabled: pageState === 0 || pageState === 2 //aktiviert wenn status 0 und 2
            value: {
                if (pageState !== 0)
                    return frequency;
                else
                    return 1;
            }

        }

//        Text {
//            text: "Dauer des Auftretens: "
//            Layout.topMargin: 20
//            color: "black"
//            font.pixelSize: 17
//            Layout.fillWidth: true
//            font.family: "Arial"
//        }

//        RadioButtonTemplate{
//            id: radioButtonLessThen
//            text: qsTr("Seit weniger als 24 Stunden")
//            font.pixelSize: 15
//            enabled: pageState === 0 || pageState === 2
//            checked: {
//                if (pageState !== 0)
//                    if (duration === radioButtonLessThen.text)
//                        return true;
//                    else
//                        return false;
//            }

//        }
//        RadioButtonTemplate{
//            id: radioButtonMoreThen
//            text: qsTr("Seit mehr als 24 Stunden")
//            font.pixelSize: 15
//            enabled: pageState === 0 || pageState === 2 //aktiviert wenn status 0 und 2
//            checked: {
//                if (pageState !== 0)
//                    if (duration === radioButtonMoreThen.text)
//                        return true
//                    else
//                        return false
//            }
//        }
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
                        dialog.deleteSymptom = true;
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
//                    //Überpüfe welcher RadioButton ausgewählt
//                    if (radioButtonMoreThen.checked) {
//                        var radioButtonValue = radioButtonMoreThen.text
//                    } else {
//                        radioButtonValue = radioButtonLessThen.text
//                    }
                    //Neues Symptom zur Datenbank hinzufügen
                    if(pageState === 0) {
                        symptomModel.addSymptoms(symptomInput.text, sliderIntensity.value, sliderFrequency.value, 0, txtDate.text,  txtTime.text);
                        stackView.pop()
                        stackView.pop()
                    }
                    else if(pageState ===1){
                        console.log("Wert: " + symptom.id);
                        pageState = 2;
                    }
                    //Symptom in der Datenbank ändern
                    else if(pageState === 2){
                        symptomModel.updateSymptom(symptomInput.text, sliderIntensity.value, sliderFrequency.value, 0);
                        stackView.pop()

                    }
                }
            }
        }
    }

}









