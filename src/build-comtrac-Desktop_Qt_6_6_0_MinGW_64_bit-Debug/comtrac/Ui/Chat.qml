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
        width: parent.width * 0.8
        height: parent.height - header.height
        anchors.top: header.bottom
        anchors.margins: 20
        model:  messageModel.messages
        spacing: 20
        delegate: MessageDelegate {
            anchors.left: parent.left
            anchors.leftMargin: 30
            visible: index <= currentMessage
            onNextMessage: {
                currentMessage +=1

            }
        }


    }



}
