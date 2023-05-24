import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


Rectangle {
    id: header
    property string pageTitle
    width: parent.width
    height: parent.height * 0.10
    color: "white"

    Text{
        id: txtPageTitle
        text: pageTitle
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "dimgrey"
        font.pixelSize: 16
        Layout.fillWidth: true
        opacity: 0.8
        font.family: "Arial"
        lineHeight: 0.5
        Rectangle {
            anchors.top: parent.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            color: "dimgrey"
            height: 2
            width: header.width


        }
    }

}


