import QtQuick 2.15
import QtQuick.Controls 2.5



Item {
    height: 10 ? bubble.height + 25 : bubble.height
    width: bubble.width

    property bool shouldShowTime
    property date time: new Date()

    Rectangle{
        id: bubble
        width: Math.min(messageText.implicitWidth + 24, (parent.width * 0.8))
        height: messageText.implicitHeight + 24
        radius: 12

        gradient: Gradient {
            orientation: Gradient.Horizontal
            GradientStop { position: -0.2; color: "grey" }
            GradientStop { position: 1.0; color: "grey" }
        }

        Text{
            id: messageText
            text: "TEST"/*message.contents*/
            anchors.fill: parent
            anchors.margins: 12
            wrapMode: Label.Wrap
            color: CustomColors.plainWhite
            opacity: 0.75
            font.pixelSize: 12
            font.family: Poppins.medium
            verticalAlignment: Qt.AlignVCenter
            horizontalAlignment: sender ? Qt.AlignLeft : Qt.AlignRight
        }
    }
    Text{
        anchors.top: bubble.bottom; anchors.topMargin: 10
        anchors.right: sender ? undefined : parent.right
        horizontalAlignment: sender ? Qt.AlignLeft : Qt.AlignRight
        text: time.toLocaleTimeString("hh:mm")
        width: bubble.width
        height: 20
        color: CustomColors.plainWhite
        font.pixelSize: 10
        visible: shouldShowTime
        opacity: 0.3
        font.family: Poppins.medium
    }
}
