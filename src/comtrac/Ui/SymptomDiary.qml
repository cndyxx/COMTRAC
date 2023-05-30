import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"

//☰“ (U+2630)
//„☓“ (U+2613)
//„📈“ (U+1F4C8)

Item {

     property string selectedDate
    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Symptomtagebuch"
    }
    CalendarTemplate {
        id: calendar
        anchors.top: header.bottom
        anchors.margins: 10
    }

    ListView {
        id: symptomListView

        spacing: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: graphicButton.height * 2.2
        width: parent.width
        height: parent.height * 0.25
        model: symptomModel.symptoms
        anchors.horizontalCenter: parent.horizontalCenter
        delegate: SymptomDelegate {
            anchors.margins: 10
            width: parent.width * 0.9
            height: 40

            onClicked: {
                console.log(symptomListView.model[index].name + "DATUM: " + selectedDate);
                symptomModel.setSingleSymptom(symptomListView.model[index]);
                stackView.push("EditSymptom.qml", {"pageState" : "1"})

            }
        }
    }
    Connections {
        target: symptomModel  // Das Symptom-Modellobjekt in QML
        function onSymptomsChanged() {
            // Aktualisiere das Modell der ListView
            symptomListView.model.clear();
            symptomListView.model.append(symptomModel.symptoms);
        }
    }

    //Button
    RoundButtonTemplate {
        id: graphicButton
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 14
        buttonIcon: "\u2630" //muss noch geändert werden in eine Graphik

    }
    RoundButtonTemplate {
        buttonIcon: "\u254B"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 14
        onClicked: stackView.push("findSymptom.qml")

    }


}
