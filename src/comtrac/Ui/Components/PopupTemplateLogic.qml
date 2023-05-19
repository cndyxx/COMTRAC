import QtQuick
import QtQuick.Controls
Item {
    signal yes_clicked
    signal no_clicked

    /* Yes button */
    Button{
        id:yes_button
        width: 100
        height: 50
        color: "teal"
        anchors.top: dialogDesc.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 30

        Text {
            id: button_yes_text
            anchors.centerIn: parent
            font.pixelSize: 14
            font.bold: true
            color: "white"
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                quitDialog.yes_clicked();
            }
        }
    }

    /* No button */
    Button{
        id:no_button
        width: 100
        height: 50
        color: "teal"
        anchors.left: yes_button.right
        anchors.leftMargin: 20
        anchors.top: dialogDesc.bottom
        anchors.topMargin: 20

        Text {
            id: button_no_text
            anchors.centerIn: parent
            font.pixelSize: 14
            font.bold: true
            color: "white"
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                quitDialog.no_clicked();
            }
        }
    }
}
