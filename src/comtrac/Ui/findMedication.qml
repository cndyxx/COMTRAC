import QtQuick
import "./Components"

Item {
    anchors.centerIn: parent.centerIn
    SearchTemplate {
        width: parent.width
        height: parent.height
        nextPage: "../editMedication.qml"
        headerTitle: "Medikamente"
        title: "Medikament"
    }
}
