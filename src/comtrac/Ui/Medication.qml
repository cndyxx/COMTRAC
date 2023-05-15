import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {

    property string find_medication: "findMedication.qml"
    ColumnLayout{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.bottom
        anchors.topMargin: -200
        anchors.bottomMargin: 60
        spacing: 4

        Rectangle{
            Layout.alignment: Qt.AlignCenter
            id: orangeRec
            color: "orange"
            width: 200
            height: 200
        }
        ButtonTemplate{
            Layout.topMargin: 100
            id: addMedication
            text: "Medikament hinzufügen"
            Layout.alignment: Qt.AlignBottom

            //anchors.bottom: parent
           // anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                stackView.replace(find_medication)
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
