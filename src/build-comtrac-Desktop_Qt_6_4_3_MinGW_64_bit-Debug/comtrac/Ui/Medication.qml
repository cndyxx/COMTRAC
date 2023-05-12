import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    property string edit_medication: "editMedication.qml"
    ColumnLayout{
        anchors.centerIn: parent
        spacing: 4
        ButtonTemplate{
            id: addMedication
            text: "Medikament hinzufügen"
            anchors.bottom: parent
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                stackView.replace(edit_medication)
            }
        }

        ButtonTemplate{
            id: medicationPlan
            text: "Mediaktionsplan"
            anchors.bottom: parent
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {

            }
        }

    }






}
