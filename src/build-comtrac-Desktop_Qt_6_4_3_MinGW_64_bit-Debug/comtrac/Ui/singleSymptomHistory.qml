import QtQuick
import QtQuick.Controls
import "./Components"



Item {
    property var symptom: symptomModel.symptomEntries

    Background {
        id: background
    }
    HeaderTemplate {
        id: header
        pageTitle: "Symptomverlauf"
    }
    //Säulendiagramm
    Image {
        source: "../assets/singleSymptom_Diagramm.PNG";
        width: parent.width * 0.9
        height: parent.height * 0.4
        anchors.top: header.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
    }

    //SymtpomListe
    ListView {
        id: symptomListView
        spacing: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        width: parent.width
        height: parent.height * 0.35
        model: symptom
        ScrollBarTemplate {}
        anchors.horizontalCenter: parent.horizontalCenter
        delegate: SymptomDelegate {
            setBackgroundColor: true
            anchors.margins: 10
            width: parent.width * 0.9
            height: 40

            onClicked: {
                symptomModel.setSingleSymptom(symptomListView.model[index]);
                stackView.push("EditSymptom.qml", {"pageState" : 1})
            }
        }
    }

}
