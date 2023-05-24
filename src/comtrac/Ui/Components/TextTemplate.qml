import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    property string inputText
    property string titleText
    property string textColor: "grey"

    ColumnLayout {
        Text {
            text: qsTr(titleText)
            color: textColor
            font.pixelSize: 12

        }
        Text {
            text: qsTr(inputText)
            color: textColor
            font.pixelSize: 15
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
