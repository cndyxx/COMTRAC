// MessageDelegate.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {

    property var messageData: messageListView.model[index]
    property int textMargin: 15
    property color messageColor: "silver"

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
            default:
                return 0;
            }
        }

        Rectangle {
            id: messageBackground
            width: parent.width
            height: parent.height +20
            color: messageColor
            radius: 10
            ColumnLayout {
                Layout.fillWidth: true
                width: parent.width
                Layout.alignment: Qt.AlignHCenter
                spacing: 10
                Text {
                    id: textItem
                    text: qsTr(messageData.text)
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
//                        anchors.left: parent.left
//                        anchors.leftMargin: 15
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
                                    messageColor = "darkgrey"

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
                            // Timer abgelaufen, hier können Sie den Code für die Aktion ausführen
                            console.log("Timer abgelaufen");
                        nextMessage()
                            messageColor= "silver"
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
                                meessageData.text = "Rezept(e) für " +  " bestellen?"

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
            }
        }
    }
}

