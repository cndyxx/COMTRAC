import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"


Item {
    property date currentDate: new Date()
    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Symptomverlauf"
    }
    Label {
        id: yearLabel
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: header.bottom
        anchors.margins: 5
        text: currentDate.getFullYear().toLocaleString("yyyy")
        font.family: "Arial"
        font.pixelSize: 17
        color: "dimgrey"
    }

    Rectangle {
        anchors.top: yearLabel.bottom
        anchors.margins: 5
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.98
        height: parent.height * 0.3
        color: "white"
        border.width: 2
        border.color: "dimgrey"

        //Kalenderwochen anzeigen
        GridLayout {
            width: parent.width
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
            columns: 4
            rows: 2

            Repeater {
                model: 8
                delegate: Rectangle {
                    id: kwRectangle
                    color: "grey"
                    width: parent.width * 0.20
                    height: kwRectangle.width


                }
            }
        }
    }
}
