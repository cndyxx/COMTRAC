import QtQuick 2.15
import QtQuick.Controls 2.15
import "./Components"

Item {
    property int currentMessage: 0
    property var visibleMessages: [true, false, false, false]
    Background {
        id: background
        color: "lightgrey"
    }

    HeaderTemplate {
        id: header
        pageTitle: "Chat"
        navigationStyle: "menu"
    }
    ListView{
        id: messageListView
        width: parent.width * 0.8
        height: parent.height
        anchors.top: header.bottom
        anchors.margins: 20
        model: messageModel.messages
        spacing: 80
        delegate: MessageDelegate {
            currentMessageIndex: currentMessage
            visible: visibleMessages[index]
            onShowNextMessage: {

            }

        }

    }


}
