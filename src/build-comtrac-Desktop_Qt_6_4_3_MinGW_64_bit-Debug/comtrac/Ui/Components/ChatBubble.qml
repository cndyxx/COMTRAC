import QtQuick
import QtQuick.Controls 2.0
import QtQuick.Layouts
// Custom ChatBubble component for displaying messages in the ListView
// Custom ChatBubble component

Rectangle  {
    property string inputText
    width: parent.width * 0.9
    implicitHeight: txt.implicitHeight
    radius: 10
    color: "darkgrey"
    Text {
        id: txt
        text: inputText
        color: "white"
        font.pixelSize: 17
        font.family: "Arial"
        wrapMode: Text.WordWrap
        width: parent.width
    }
}

