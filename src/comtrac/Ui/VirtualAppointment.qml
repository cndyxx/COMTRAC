import QtQuick 2.15
import "./Components"
Item {
    Background {
        id: background
        color: "black"
    }
    HeaderTemplate{
        id: header
        pageTitle: "Videosprechstunde"

    }

    Rectangle {
        id: doctorPicture
        anchors.top: header.bottom
        anchors.topMargin: 150
        color: "white"
        width: parent.width
        height: 150
        Image{
            source: "../assets/user-silhouette.png"
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 7
            width: parent.width * 0.4
            height: parent.height * 0.9
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        Rectangle{
            width: txtDoctor.width * 0.9
            height: 20
            anchors.top: parent.top; anchors.topMargin: 5
            anchors.left: parent.left; anchors.leftMargin: 5
            color: "white"
            Text{
                id: txtDoctor
                text: "Dr. Max Mustermann"
                font.family: "Arial"
                font.pixelSize: 12
                color: "black"
            }
        }
    }
    Rectangle {
        anchors.top: doctorPicture.bottom
        anchors.topMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 10
        color: "lightgrey"
        width: parent.width * 0.3
        height: parent.height * 0.2
        Image{
            source: "../assets/user-silhouette.png"
            width: parent.width * 0.7
            height: parent.height * 0.7
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom; anchors.bottomMargin: 5
        }
        Rectangle{
            anchors.top: parent.top; anchors.topMargin: 10
            anchors.left: parent.left; anchors.leftMargin: 10
            width: txtUser.width
            height: 20
            color: "lightgrey"

            Text{
                id: txtUser
                text: "Du"
                font.family: "Arial"
                font.pixelSize: 12
                color: "black"
            }
        }
    }

    Rectangle {
        width: parent.width
        height: 50
        anchors.bottom: parent.bottom
        color: "grey"
        Image {
            id: videoIcon
            width: 50
            height: 50
            source: "../assets/video_icon.png"
            anchors.left: parent.left; anchors.leftMargin: 25

        }
        Image {
            id: microphoneIcon
            width: 50
            height: 50
            source: "../assets/microphone.png"
            anchors.left: videoIcon.right; anchors.leftMargin: 15

        }
        Image {
            id: chancelIcon
            width: 50
            height: 50
            source: "../assets/circle.png"
            anchors.left: microphoneIcon.right; anchors.leftMargin: 15
        }
        Image {
            id: chatIcon
            width: 50
            height: 50
            source: "../assets/chat.png"
            anchors.left: chancelIcon.right; anchors.leftMargin: 20

        }
    }
}
