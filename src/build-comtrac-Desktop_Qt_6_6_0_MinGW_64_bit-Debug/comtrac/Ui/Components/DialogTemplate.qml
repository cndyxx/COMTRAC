import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
Popup {
    id: dialog
    property string dialogText
    property bool deleteSymptom: false

    width: parent.width * 0.9
    height: parent.height * 0.25
    background: Rectangle{
        width: parent.width
        height: parent.height
        color: "lightgrey"
    }

    ColumnLayout {
        width: parent.width
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            id: dialogTxt
            font.pixelSize: 17
            font.family: "Arial"
            color: "white"
            text: dialogText
        }

        RowLayout {
            width: parent.width
            Layout.margins: 10
            ButtonTemplate {
                text: "Abbrechen"
                Layout.fillWidth: true
                buttonWidth: parent.width / 2
                buttonHeight: parent.height * 0.25
                onClicked: {
                    dialog.close()
                }
            }
            ButtonTemplate {
                id: deleteButton
                text: "Löschen"
                Layout.fillWidth: true
                buttonWidth: parent.width / 2
                buttonHeight: parent.height * 0.25
                onClicked: {
                    if(!deleteSymptom) {
                        //Medikament löschen
                    }
                    else {
                        symptomModel.deleteSymptom();
//                        dialogVisible = false;
                        dialog.close()
                        stackView.pop();
                    }
                }
            }
        }
    }

}
