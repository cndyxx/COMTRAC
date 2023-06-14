import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"
Item {
    id: waitingRoom
    property int dotCount: 1
    width: parent.width
    height: parent.height

    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Videosprechstunde"
    }
    Rectangle {
        id: messageBackground
        width: parent.width
        height: parent.height - header.height
        color: background.color
        radius: 10
        anchors.top: header.bottom
        ColumnLayout {
            Layout.fillWidth: true
            width: parent.width
            Layout.alignment: Qt.AlignHCenter
            spacing: 10
            Text {
                id: textItem
                text: qsTr("Bitte warten Sie, ihr Arzt oder ihre Ärztin wird Sie gleich anrufen")
                wrapMode: Text.WordWrap
                width: parent.width
                font.pixelSize: 16
                Layout.preferredWidth: parent.width
                Layout.alignment: Qt.AlignHCenter
                anchors.left: parent.left
                anchors.leftMargin: textMargin
                anchors.top: header.top
                anchors.topMargin: 5

            }
            Text {
                id: waitingText
                font.pixelSize: 20
                font.family: "Arial"
                color: "dimgrey"
                text: ""
            }


        }

        Component.onCompleted: {
            dotTimer.start()
        }

        Timer {
            id: dotTimer
            interval: 1000 // 1 second interval
            running: true
            repeat: true
            onTriggered: {
                dotCount = (dotCount % 3) + 1 // Increment dot count cyclically from 1 to 3
                waitingText.text = ".".repeat(dotCount)
            }
        }


    }
}
