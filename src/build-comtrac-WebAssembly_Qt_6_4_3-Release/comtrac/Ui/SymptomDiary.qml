import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"

//☰“ (U+2630)
//„☓“ (U+2613)
//„📈“ (U+1F4C8)

Item {

    property var symptom: symptomModel.daySymptoms

    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Symptomtagebuch"
        navigationStyle: "menu"
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
        anchors.bottomMargin: graphicButton.height * 1.3
        width: parent.width
        height: parent.height * 0.25
        model: symptom
        anchors.horizontalCenter: parent.horizontalCenter
        clip: true
        ScrollBarTemplate {}
        delegate: SymptomDelegate {
            anchors.margins: 10
            width: parent.width * 0.9
            height: 50

            onClicked: {                
                symptomModel.setSingleSymptom(symptomListView.model[index]);
                stackView.push("EditSymptom.qml", {"pageState" : 1})
            }
        }


    }
    Connections {
        target: symptomModel  // Das Symptom-Modellobjekt in QML
        function onDaySymptomsChanged() {
            // Aktualisiere das Modell der ListView
            symptomListView.model = symptomModel.daySymptoms;
            //symptomListView.model.append(symptomModel.symptoms);
        }
    }

    // Button zum Öffnen des Symptomverlaufs
    RoundButtonTemplate {
        id: graphicButton
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.margins: 14

        Image {
            anchors.centerIn: parent
            source: "../assets/chart.png"
            width: parent.width/2
            height: parent.height/2
        }


        onClicked: {
            symptomModel.getCalendarWeekDate(2023, 26); //Kalenderwoche 26
            stackView.push("SymptomHistory.qml")
        }

    }
    //Button zum Öffnen des Symptomtagebuchs
    RoundButtonTemplate {
        //buttonIcon: "\u254B"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 14

        Image {
            anchors.centerIn: parent
            source: "../assets/plus.png"
            width: parent.width/2
            height: parent.height/2
        }

        onClicked: stackView.push("findSymptom.qml");

    }


}
