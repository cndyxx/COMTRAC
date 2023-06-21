import QtQuick 2.15
import QtQuick.Controls 2.15
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


            onNextMessage: {
                currentMessage +=1
                messageListView.currentIndex += 1

                console.log("Current message: " + currentMessage + "- " + index);
            }
        }
        clip: true


    }





}
