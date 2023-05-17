import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    id: medication
    width: 250
    height: 500
    anchors.centerIn: parent
    property string find_medication: "findMedication.qml"

    HeaderTemplate{
        id: headerMedication
        pageTitle: "Medikation"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

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
                stackView.push(find_medication)
            }
        }

        ButtonTemplate{
            id: medicationPlan
            text: "Mediaktionsplan"
            onClicked: {

            }
        }

    }






}
