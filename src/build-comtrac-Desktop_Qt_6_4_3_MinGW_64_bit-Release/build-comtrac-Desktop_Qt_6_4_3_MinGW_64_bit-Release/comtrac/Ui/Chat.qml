import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import "./Components"

Item {
    id: chat
    property int currentMessage: 0
    property var selectedMedications: []

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
        id: messageTest
        ListElement{textMessage: "Erste Nachricht"; type: 1}
        ListElement{textMessage: "Zweite Nachricht"; type: 2}
        ListElement{textMessage: "Dritte Nachricht"; type: 3}
        ListElement{textMessage: "Vierte Nachricht"; type: 4}
        ListElement{textMessage: "Fünfte Nachricht"; type: 5}
    }

        ListView{
            id: messageListView
            width: parent.width * 0.9
            height: parent.height - header.height - 20
            anchors.top: header.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 10
            model:  messageModel.messages
            spacing: 10

            delegate: MessageDelegate {
                anchors.horizontalCenter: parent.horizontalCenter
                visible:  index <= currentMessage;
                inputText: messageModel.messages[index].text
                textType: messageModel.messages[index].type
                onNextMessage: {
                    currentMessage +=1
                    messageListView.currentIndex += 1
                }
            }
            clip: true


        }





}
