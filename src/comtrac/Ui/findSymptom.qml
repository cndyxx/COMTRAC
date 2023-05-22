import QtQuick
import "./Components"

Item {
    anchors.centerIn: parent.centerIn
    SearchTemplate {

        width: parent.width
        height: parent.height
        nextPage: "../editSymptom.qml"
        headerTitle: "Symptom hinzufügen"
        title: "Symptom"
    }
}
