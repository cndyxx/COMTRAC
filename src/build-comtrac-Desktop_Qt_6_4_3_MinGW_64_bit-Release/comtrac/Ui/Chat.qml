import QtQuick 2.15
import QtQuick.Controls 2.15
import "./Components"

Item {
    id: chat
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
    ListModel {
        id: messages
        ListElement {
            text: "Nachricht 1 "
        }
        ListElement{
            text: "Nachricht 2"
        }
    }

    ListView{
        id: messageListView
        width: parent.width * 0.9
        height: parent.height - header.height
        anchors.top: header.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 10
        model:  messageModel.messages
        spacing: 30
        delegate: MessageDelegate {
            anchors.horizontalCenter: parent.horizontalCenter
            visible: index <= currentMessage
            onNextMessage: {
                currentMessage +=1

            }
        }
        clip: true


    }



}
