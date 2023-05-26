import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    //property für die nächste Seite die geöffnet werden soll
    property string nextPage

    //Text der im Header stehen soll
    property string headerTitle

    //Überschrift über TextFeld "Hier eingeben"
    property string title
    Background {id: background}
    HeaderTemplate {
        id: header
        pageTitle: headerTitle
    }

    ColumnLayout {

        y: 212
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: parent.left
        anchors.leftMargin: 10

        Text {
            text: title
            color: "black"
            font.pixelSize: 23
            Layout.fillWidth: true
            font.family: "Arial"

        }

        TextField {
            id: input
            Layout.fillWidth: true
            font.pixelSize: 17
            font.family: "Arial"
            color: "black"
            placeholderText: qsTr("Hier eingeben")
            background: Rectangle {
                id: recInput
                implicitWidth: 213
                implicitHeight: 30
                color: "white"
                Rectangle {
                    width: parent.width
                    height: 2
                    color: "grey"
                    anchors.top: recInput.bottom
                }
            }
            onAccepted: {
                stackView.push(nextPage, {"name" :input.text, "pageState": 0});
            }
        }
    }

}
