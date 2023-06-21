import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    property string inputText
    property string titleText
    property string textColor: "grey"


    ColumnLayout {
        Layout.fillHeight: true
        Layout.fillWidth: true
        Text {
            text: qsTr(titleText)
            color: textColor
            font.pixelSize: 12
            Layout.fillHeight: true

        }
        Text {
            anchors.topMargin: 5
            text: qsTr(inputText)
            color: textColor
            font.pixelSize: 15
            Layout.fillHeight: true
            Rectangle {
                color: textColor
                height: 2
                width: parent.width
                Layout.fillWidth: true
                anchors.top: parent.bottom
            }

        }
    }





}
