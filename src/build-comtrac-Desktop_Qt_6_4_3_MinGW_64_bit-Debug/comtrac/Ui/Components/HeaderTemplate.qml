import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


Item {
    property string pageTitle: ""
    anchors.top: parent.top
    // anchors.bottom: contactList.top
    anchors.left: parent.left; anchors.right: parent.right
    anchors.margins: 14

    ColumnLayout{
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

            Text{
                text: pageTitle
                color: "dimgrey"
                font.pixelSize: 16
                Layout.fillWidth: true
                opacity: 0.8
                font.family: "Arial"
                lineHeight: 0.5
            }

    }
}

