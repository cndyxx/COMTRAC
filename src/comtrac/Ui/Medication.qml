import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"

Page {
    id: medication
    Background { id: background}
    HeaderTemplate{
        id: headerMedication
        pageTitle: "Medikation"
    }
    ColumnLayout {
        anchors.centerIn: parent
        anchors.top: headerMedication.bottom
        anchors.topMargin: 10
        spacing: 4

        Rectangle{
            Layout.alignment: Qt.AlignCenter
            id: orangeRec
            color: "orange"
            width: 200
            height: 200
            radius: 20
        }
        ButtonTemplate{
            Layout.topMargin: 80
            id: addMedication
            text: "Medikament hinzufügen"
            onClicked: {
                stackView.push("findMedication.qml")
            }
        }

        ButtonTemplate{
            id: medicationPlan
            text: "Mediaktionsplan"
            onClicked: {
                stackView.push("MedicationPlan.qml")

            }
        }

    }






}
