// MessageDelegate.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {

    property var messageData: messageListView.model[index]
    property int textMargin: 15
    property date currentTime: new Date()
    property string inputText: messageData.text
    property int dotCount: 1

    width: parent.width
    height: contentItem.height
    signal  nextMessage()

    ListModel {
        id: buttonText
        ListElement {
            text: "Termin vereinbaren"
        }
        ListElement {
            text: "Termin ändern"
        }
        ListElement {
            text: "Rezept bestellen"
        }
        ListElement {
            text: "'Fragen klären'"
        }
    }

    Item {
        id: contentItem
        implicitWidth: parent.width
        implicitHeight: {
            switch (messageData.type) {
            case 1:
                return textItem.implicitHeight + firstMessage.height;
            case 2:
                return textItem.implicitHeight;
            case 3:
                return textItem.implicitHeight + buttonsColumn.height;
            case 4:
                return textItem.implicitHeight +buttonsRow.height;
            case 5:
                return textItem.implicitHeight;
            default:
                return 0;
            }
        }

        Rectangle {
            id: messageBackground
            width: parent.width
            height: parent.height +20
            color: switch (messageData.type) {
                   case 2:
                       return "grey";
                   default:
                       return "silver";
                   }
            radius: 10
            ColumnLayout {
                Layout.fillWidth: true
                width: parent.width
                Layout.alignment: Qt.AlignHCenter
                spacing: 10
                Text {
                    id: textItem
                    text: qsTr(inputText)
                    wrapMode: Text.WordWrap
                    width: parent.width
                    font.pixelSize: 16
                    Layout.preferredWidth: parent.width
                    Layout.alignment: Qt.AlignHCenter
                    anchors.left: parent.left
                    anchors.leftMargin: textMargin
                    anchors.top: parent.top
                    anchors.topMargin: 5

                }

                // Buttons for the first message type
                Item {
                    visible: messageData.type === 1
                    width: parent.width
                    height: parent.height - textItem.height

                    ColumnLayout {
                        id: firstMessage
                        spacing: 10

                        Layout.alignment: Qt.AlignHCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                        Repeater {

                            model: buttonText
                            delegate: ButtonTemplate {
                                text: modelData
                                buttonWidth: contentItem.width * 0.8
                                backgroundDefaultColor: "white"
                                borderDefaultColor: "black"
                                contentItemTextColor: "black"
                                onClicked: {
                                    // Handle button click
                                    timer.start()
                                    nextMessage()

                                    //messageColor: "darkgrey"


                                }
                            }
                        }
                    }
                }

                // Text only for the second and fifth message types
                Item {

                    visible: messageData.type === 2


                    //                    visible: true
                    Timer {
                        id: timer
                        interval: 3000 // Timer-Intervall von 1 Sekunde (1000 Millisekunden)
                        repeat: false // Timer wird nicht wiederholt
                        onTriggered: {
                            nextMessage();
                            dotTimer.stop();
                            dotTimer.running = false;
                            repeatTimer.visible = false;
                        }
                    }


                }

                // Radio buttons and buttons for the third message type
                Item {
                    visible: messageData.type === 3

                    ColumnLayout {
                        id: buttonsColumn
                        spacing: 10

                        Repeater {
                            id: medication
                            model: medModel.medications
                            delegate: CheckBoxTemplate {
                                text: medication.model[index].name
                                onClicked: {
                                    if (checked) {
                                        // Hinzufügen des Medikaments zur Bestellung
                                        medModel.addOrderedMedication(medication.model[index].name)
                                    } else {
                                        // Entfernen des Medikaments aus der Bestellung
                                        medModel.deleteOrderedMedication(medication.model[index].name)
                                    }
                                    dotTimer.start()
                                }
                            }
                        }

                        ButtonTemplate {
                            text: "Auswahl bestätigen"
                            backgroundDefaultColor: "white"
                            borderDefaultColor: "black"
                            contentItemTextColor: "black"
                            buttonWidth: contentItem.width * 0.8
                            onClicked: {
                                // Handle button click
                                nextMessage()
                                medModel.getOrderedMedication()
                            }

                        }
                    }
                }

                // Buttons in a row for the fourth message type
                Item {
                    visible: messageData.type === 4
                    anchors.left: parent.left
                    anchors.leftMargin: 15
                    RowLayout  {
                        id: buttonsRow
                        spacing: 10
                        width: contentItem.width * 0.75
                        anchors.margins: 10
                        ButtonTemplate {
                            text: "Abbrechen"
                            buttonWidth: parent.width / 2
                            Layout.fillHeight: true
                            borderDefaultColor: "black"
                            contentItemTextColor: "black"
                            onClicked: {
                                // Handle button click

                            }
                        }
                        ButtonTemplate {
                            text: "Bestätigen"
                            buttonWidth: parent.width / 2
                            Layout.fillHeight: true
                            backgroundDefaultColor: "white"
                            borderDefaultColor: "black"
                            contentItemTextColor: "black"
                            onClicked: {
                                // Handle button click
                                nextMessage();
                            }
                        }
                    }

                }
                Item {
                    visible:  messageData.type === 5
                }

                Item {
                    id: repeatTimer
                    visible: messageData.type === 2

                    Text {
                        id: waitingText
                        font.pixelSize: 20
                        font.family: "Arial"
                        color: "dimgrey"
                        text: ""
                    }

                    Timer {
                        id: dotTimer
                        property int count: 0
                        interval: 1000 // 1 second interval
                        running: true
                        repeat: true
                        onTriggered: {
                            dotCount = (dotCount % 3) + 1 // Increment dot count cyclically from 1 to 3
                            waitingText.text = ".".repeat(dotCount)
                            count += 1;
                            if(count === 4){
                                dotTimer.running = false;
                                repeatTimer.visible = false;
                            }
                        }
                    }
                }

            }
        }
        Text {
            anchors.top: messageBackground.bottom
            anchors.topMargin: 2
            anchors.right: if(messageData.type === 2) return parent.right
            font.family: "Arial"
            font.pixelSize: 12

            text: if(messageData.type !== 2){
                      return currentTime.toLocaleTimeString(Qt.locale("de_DE"), "hh:mm") + " von Chatbot"
                  } else {

                      return currentTime.toLocaleTimeString(Qt.locale("de_DE"), "hh:mm")
                  }
        }
    }
}

