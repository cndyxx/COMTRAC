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
        onBackButton: medModel.deleteOrderedMedicationList();
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
            height: parent.height - header.height - 80
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
                onCancelAction: {
                    messageListView.model = messageModel.messages;
                    currentMessage = 0;
                    messageListView.currentIndex = 0;
                    medModel.deleteOrderedMedicationList();
                }
            }
            clip: true


        }

        Rectangle {
            width: parent.width
            height: 50
            anchors.bottom: parent.bottom
            color: "dimgrey"
            Rectangle {
                width: parent.width * 0.7
                height: parent.height * 0.8
                anchors.left: parent.left; anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                color: "white"
                radius: 15
                Text {
                    text: "Nachricht"
                    font.pixelSize: 20
                    font.family: "Arial"
                    color: "dimgrey"
                    anchors.left: parent.left; anchors.leftMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle{
                id: button
                width: parent.height * 0.8
                height: button.width
                color: "grey"
                radius: 50
                anchors.right: parent.right; anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                Image {
                    width: parent.width * 0.5
                    height: parent.height * 0.5
                    source: "../assets/arrow.png"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
}
