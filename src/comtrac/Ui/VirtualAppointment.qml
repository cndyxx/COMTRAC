import QtQuick 2.15
import "./Components"
Item {
    Background {
        id: background
        color: "black"
    }
    HeaderTemplate{
        id: headerMedication
        pageTitle: "Videosprechstunde"
    }

    Rectangle {
        id: doctorPicture
        color: "white"
        width: parent.width
        height: parent.height * 0.25
        anchors.verticalCenter: parent.verticalCenter
        Image{
            source: "../assets/user-silhouette.png"
            width: parent.width * 0.4
            height: parent.height
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle{
            width: Text.width
            height: Text.height
            anchors.top: parent.top; anchors.topMargin: 10
            anchors.left: parent.left; anchors.leftMargin: 10
            color: "grey"
            Text{
                text: "Dr. Max Mustermann"
                font.family: "Arial"
                font.pixelSize: 12
                color: "white"
            }
        }
    }
    Rectangle {
        anchors.top: doctorPicture.bottom
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        color: "lightgrey"
        width: parent.width * 0.3
        height: parent.height * 0.2
        Image{
            source: "../assets/user-silhouette.png"
            width: parent.width * 0.5
            height: parent.height * 0.5
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Rectangle{
            anchors.top: parent.top
            anchors.left: parent.left
            width: Text.width
            height: Text.height
            color: "lightgrey"
            Text{
                text: "Du"
                font.family: "Arial"
                font.pixelSize: 12
                color: "white"
            }
        }
    }

    Rectangle {
        width: parent.width
        height: 50
        anchors.bottom: parent.bottom
        color: "grey"
    }
}
