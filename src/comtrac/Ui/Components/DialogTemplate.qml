import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
Dialog {
    id: dialog
    property bool dialogVisible: false
    property string dialogText
    property bool deleteSymptom: false
    width: parent.width * 0.9
    height: parent.height * 0.25
    visible: dialogVisible
    Material.background: "grey"
    Material.foreground: "white"
    Text {
        id: dialogTxt
        horizontalAlignment: Qt.AlignLeft
        verticalAlignment: Qt.AlignTop

        font.pixelSize: 17
        font.family: "Arial"
        color: "white"
        text: dialogText
    }

    RowLayout {
        anchors.bottom: parent.bottom
        anchors.margins: 10
        ButtonTemplate {
            text: "Abbrechen"
            Layout.fillWidth: true
            buttonWidth: parent.width / 2
            buttonHeight: parent.height * 0.25
            onClicked: {
                dialogVisible = false;
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
                    dialogVisible = false;
                    stackView.pop();
                }
            }
        }
    }

}
