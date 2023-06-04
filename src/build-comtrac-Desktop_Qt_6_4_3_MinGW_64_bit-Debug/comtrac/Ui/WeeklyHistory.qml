import QtQuick
import QtQuick.Controls
import "./Components"



Item {
    property var symtpom: symptomModel.weekSymptoms
    //Säulendiagramm
    ListView {
        id: symptomListView

        spacing: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        width: parent.width
        height: parent.height * 0.40
        model: symptom

        anchors.horizontalCenter: parent.horizontalCenter
        delegate: SymptomDelegate {
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
