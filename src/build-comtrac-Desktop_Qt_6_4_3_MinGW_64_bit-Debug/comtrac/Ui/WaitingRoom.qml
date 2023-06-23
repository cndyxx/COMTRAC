import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"
Item {
    id: waitingRoom
    property int dotCount: 1
    property int elapsedTime: 0
    width: parent.width
    height: parent.height

    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Videosprechstunde"
    }

    Timer {
            id: timer
            interval: 1000 // Interval in milliseconds (1 second)
            running: true
            repeat: true
            onTriggered: {
                elapsedTime += 1;
            }
        }
        Rectangle{
            id: elapsedTimeText
            width: 100
            height: 60
            anchors.top: header.bottom; anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Text {

                text: "00:0" + elapsedTime
                anchors.centerIn: parent
                font.pixelSize: 12
            }
        }


    Rectangle {
        id: messageBackground
        width: parent.width * 0.7
        height: parent.height * 0.5
        color: background.color
        radius: 10
        anchors.top: elapsedTimeText.bottom
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
