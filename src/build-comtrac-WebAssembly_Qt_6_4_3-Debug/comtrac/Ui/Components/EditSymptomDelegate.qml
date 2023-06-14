import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {

    readonly property date currentDate: new Date()
    property string symptomName

    Layout.fillWidth: true
    Layout.fillHeight: true
    RowLayout {
        id: dateTime
        spacing: 60
        TextTemplate {
            id: entryDate
            titleText: "Datum"
            inputText: "25.05.2023" //muss automatisch eingetragen werde
        }

        TextTemplate {
            id: entryTime
            titleText: "Uhrzeit"
            inputText: "13:37" //muss automatisch eingetragen werden
        }
    }


    Text {
        anchors.top: dateTime.bottom
        text: "Symptom"
        color: "black"
        font.pixelSize: 23
        Layout.fillWidth: true
        font.family: "Arial"
    }
    TextInput {
        id: symptomInput
        Layout.fillWidth: true
        font.pixelSize: 17
        font.family: "Arial"
        color: "black"
        text: symptomName
        focus: true
        Rectangle {
            width: header.width
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
        value: 1

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

    }

    Text {
        text: "Dauer des Auftretens: "
        Layout.topMargin: 20
        color: "black"
        font.pixelSize: 17
        Layout.fillWidth: true
        font.family: "Arial"
    }

    RadioButtonTemplate{
        id: radioButtonLessThen
        text: qsTr("Seit weniger als 24 Stunden")
        font.pixelSize: 15
    }
    RadioButtonTemplate{
        id: radioButtonMoreThen
        text: qsTr("Seit mehr als 24 Stunden")
        font.pixelSize: 15
    }
    RowLayout {
        ButtonTemplate {
            text: qsTr("Abbrechen")
            buttonWidth: parent.width/2
            Layout.fillWidth: true
            onClicked: {
                stackView.pop();
                stackView.pop()
            }
        }
        ButtonTemplate {
            text: qsTr("Eintragen")
            Layout.fillWidth: true
            buttonWidth: parent.width / 2
            onClicked: {
                //Überpüfe welcher RadioButton ausgewählt
                if (radioButtonMoreThen.checked) {
                    var radioButtonValue = radioButtonMoreThen.text
                } else {
                    radioButtonValue = radioButtonLessThen.text
                }
                symptomModel.addSymptom(symptomInput.text, sliderIntensity.value, sliderFrequency.value, radioButtonValue, "25.05.2023", "11:24")
            }
        }
    }
}

