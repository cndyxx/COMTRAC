// MessageDelegate.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {

    property var messageData: messageListView.model[index]
    property int currentMessageIndex
    signal showNextMessage()
    width: parent.width // Dynamically adjust width based on content
    height: contentItem.height // Dynamically adjust height based on content

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
                return buttonsRow.height;
            default:
                return 0;
            }
        }

        Rectangle {

            width: parent.width
            height: parent.height
            color: "lightblue"
            ColumnLayout {
                Layout.fillWidth: true
                width: parent.width
                Text {
                    id: textItem
                    text: qsTr(messageData.text)
                    wrapMode: Text.WordWrap
                    width: parent.width
                    font.pixelSize: 16
                    Layout.preferredWidth: parent.width
                }

                // Buttons for the first message type
                Item {
                    visible: messageData.type === 1
                    ColumnLayout {
                        id: firstMessage
                        spacing: 10
                        Repeater {
                            model: buttonText
                            delegate: ButtonTemplate {
                                text: modelData
                                buttonWidth: contentItem.width * 0.75
                                backgroundDefaultColor: "white"
                                borderDefaultColor: "black"
                                contentItemTextColor: "black"
                                onClicked: {
                                    // Handle button click
                                    showNextMessage();
                                    timer.start()
                                }
                            }
                        }
                    }
                }

                // Text only for the second and fifth message types
                Item {
                    visible: messageData.type === 2 || messageData.type === 5
                    Timer {
                           id: timer
                           interval: 1000 // Timer-Intervall von 1 Sekunde (1000 Millisekunden)
                           repeat: false // Timer wird nicht wiederholt

                           onTriggered: {
                               // Timer abgelaufen, hier können Sie den Code für die Aktion ausführen
                               console.log("Timer abgelaufen");
                               showNextMessage();
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
                            delegate: RadioButtonTemplate {
                                text: medication.model[index].name
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
                                showNextMessage();
                            }

                        }
                    }
                }

                // Buttons in a row for the fourth message type
                Item {
                    visible: messageData.type === 4



                    RowLayout  {
                        id: buttonsRow
                        spacing: 10
                        ButtonTemplate {
                            text: "Abbrechen"
                            buttonWidth: contentItem.width * 0.8
                            borderDefaultColor: "black"
                            contentItemTextColor: "black"
                            onClicked: {
                                // Handle button click
                            }
                        }
                        ButtonTemplate {
                            text: "Bestätigen"
                            buttonWidth: contentItem.width * 0.8
                            backgroundDefaultColor: "white"
                            borderDefaultColor: "black"
                            contentItemTextColor: "black"
                            onClicked: {
                                showNextMessage();
                                // Handle button click
                            }
                        }
                    }

                }
            }
        }
    }
}

