import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Button {
    property var medication: medicationListView.model[index]
    property string medicationName: medication.name
    property var intakeTime

    anchors.horizontalCenter: parent.horizontalCenter
    width: parent.width
    implicitHeight:  parent.height
    contentItem: ColumnLayout {
        width: parent.width
        height: parent.height
        spacing: 8
        Text {
            id: txtMedication
            text: medicationName
            color: "black"
            font.pixelSize: 18
            Layout.fillWidth: true
            font.family: "Arial"
            lineHeight: 0.5
        }
        Text {
            id: txtIntake
            text: {
                var result = ""
                for (var i = 0; i < intakeTime.length; i++) {
                    result += intakeTime[i].toLocaleTimeString("hh:mm");
                    if (i < intakeTime.length - 1) {
                        result += ", "
                    }
                }
                return "Einnahme: " + result
            }
            wrapMode: Text.WordWrap
            width: parent.width
            color: "black"
            font.pixelSize: 16
            Layout.fillWidth: true
            font.family: "Arial"
            lineHeight: 0.5
        }
    }

    background: Rectangle {
        id: backgroundRectangle
        width: parent.width
        height: 60
        border.color: "darkgrey"
        border.width: 2
        color: "lightgrey"
        radius: 5

    }
    Button {
        width: 25
        height: 25
        anchors {
            top: parent.top
            right: parent.right
            topMargin: 5
            rightMargin: 5
        }
        contentItem: Image  {

            source: "../../assets/pencil.png";

            // Positionierung des Bildes

        }
        background: Rectangle {
            color: backgroundRectangle.color
        }

        onClicked: {
            medModel.setSingleMedication(medication);
            stackView.push("../editMedication.qml", {"pageState" : 2})
        }
    }



}

