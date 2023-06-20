import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
Popup {
    id: dialog
    anchors.centerIn: parent

    property string dialogText
    property bool deleteSymptom: false
    property color backgroundColor: "grey"

    width: parent.width * 0.9
    height: parent.height * 0.25
    background: Rectangle{
        width: parent.width
        height: parent.height
        color: backgroundColor
        radius: 5
        border.color: "black"
        border.width: 2

    }


    ColumnLayout {
        width: parent.width
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            id: dialogTxt
            anchors.top: dialog.top
            font.pixelSize: 20
            font.family: "Arial"
            color: "white"
            text: qsTr(dialogText)
            wrapMode: Text.WordWrap
            width: parent.width
            Layout.preferredWidth: parent.width
            Layout.alignment: Qt.AlignHCenter
            anchors.left: parent.left
            anchors.leftMargin: textMargin
            anchors.topMargin: 5
        }

        RowLayout {
            width: parent.width
            Layout.margins: 10
            ButtonTemplate {
                text: "Abbrechen"
                contentItemTextColor: "black"
                Layout.fillWidth: true
                buttonWidth: parent.width / 2
                buttonHeight: parent.height * 0.3
                backgroundDefaultColor: backgroundColor
                borderDefaultColor: "black"

                onClicked: {
                    dialog.close()
                }

            }
            ButtonTemplate {
                id: deleteButton
                text: "Löschen"
                contentItemTextColor: "black"
                Layout.fillWidth: true
                buttonWidth: parent.width / 2
                buttonHeight: parent.height * 0.3
                backgroundDefaultColor: "white"

                onClicked: {
                    if(!deleteSymptom) {
                        //Medikament löschen
                        medModel.deleteMedication();
                        dialog.close();
                        stackView.pop();
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
