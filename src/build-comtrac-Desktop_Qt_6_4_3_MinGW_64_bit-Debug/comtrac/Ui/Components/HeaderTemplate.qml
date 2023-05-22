import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


Item {
    id: header
    width: parent.width

    property string pageTitle
    anchors.top: parent.top
    anchors.left: parent.left; anchors.right: parent.right
    anchors.margins: 14

    ColumnLayout{
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20

        Text{
            id: txtPageTitle
            text: pageTitle

            color: "dimgrey"
            font.pixelSize: 16
            Layout.fillWidth: true
            opacity: 0.8
            font.family: "Arial"
            lineHeight: 0.5
            Rectangle {
                anchors.top: txtPageTitle.bottom
                anchors.horizontalCenter: txtPageTitle.horizontalCenter
                color: "dimgrey"
                height: 2
                width: header.width


            }
        }

    }
}

