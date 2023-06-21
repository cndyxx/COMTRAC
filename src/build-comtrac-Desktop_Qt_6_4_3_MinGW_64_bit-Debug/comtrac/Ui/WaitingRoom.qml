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
        width: parent.width * 0.7
        height: parent.height * 0.5
        color: background.color
        radius: 10

        anchors.centerIn: parent

        Text {
            id: textItem
            text: qsTr("Bitte warten Sie, ihr Arzt oder ihre Ärztin wird Sie gleich anrufen")
            wrapMode: Text.WordWrap
            width: parent.width
            font.pixelSize: 25
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.fill: parent

        }
        Text {
            id: waitingText
            font.pixelSize: 60
            font.family: "Arial"
            color: "dimgrey"
            text: ""
            anchors.top: textItem.bottom
            anchors.topMargin: 5
            anchors.horizontalCenter: parent.horizontalCenter
        }


        Component.onCompleted: {
            dotTimer.start()
            t
        }

        Timer {
            id: dotTimer
            property int count: 0
            interval: 1000 // 1 second interval
            running: true
            repeat: true
            onTriggered: {
                dotCount = (dotCount % 3) + 1;
                waitingText.text = ".".repeat(dotCount);             
                count += 1;
                if(count === 11){
                    dotTimer.running = false;
                    stackView.push("VirtualAppointment.qml")
                }

            }
        }



    }
}
