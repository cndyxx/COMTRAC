import QtQuick
import QtQuick.Layouts
import QtQuick.Controls 2.5

Item {

    property string symptom_diary: "SymptomDiary.qml"
    property string medication: "Medication.qml"
    property string chat: "chat.qml"
    property string vidoe_telephony: "VideoTelephony.qml"


    ColumnLayout{
        anchors.centerIn: parent
        Rectangle{
            Layout.alignment: Qt.AlignCenter
            id: orangeRec
            color: "orange"
            width: 150
            height: 150

        }
        ButtonTemplate{
            id: symptomDiaryButton
            text: "Symptomtagebuch"
            Layout.topMargin: 10
            onClicked: {
                stackView.replace(symptom_diary)
            }
        }
        ButtonTemplate{
            id: medicationButton
            text: "Medikation"
            onClicked: {
                stackView.replace(medication)
            }

        }
        ButtonTemplate{
            id: chatButton
            text: "Chat"
            onClicked: {
                stackView.replace(chat)
            }
        }
        ButtonTemplate{
            id: videoTelephonyButton
            text: "Videotelefonie"
            onClicked: {
                stackView.replace(video_telephony)
            }

        }
    }
    Dialog {
            id: settingsDialog
            x: Math.round((window.width - width) / 2)
            y: Math.round(window.height / 6)
            width: Math.round(Math.min(window.width, window.height) / 3 * 2)
            modal: true
            focus: true
            title: qsTr("Settings")

            standardButtons: Dialog.Ok | Dialog.Cancel
            onAccepted: {
                settings.style = styleBox.displayText
                settingsDialog.close()
            }
            onRejected: {
                styleBox.currentIndex = styleBox.styleIndex
                settingsDialog.close()
            }

            contentItem: ColumnLayout {
                id: settingsColumn
                spacing: 20

                RowLayout {
                    spacing: 10

                    Label {
                        text: qsTr("Style:")
                    }

                    ComboBox {
                        id: styleBox
                        property int styleIndex: -1
                        model: window.builtInStyles
                        Component.onCompleted: {
                            styleIndex = find(settings.style, Qt.MatchFixedString)
                            if (styleIndex !== -1)
                                currentIndex = styleIndex
                        }
                        Layout.fillWidth: true
                    }
                }

                Label {
                    text: qsTr("Restart required")
                    color: "#e41e25"
                    opacity: styleBox.currentIndex !== styleBox.styleIndex ? 1.0 : 0.0
                    horizontalAlignment: Label.AlignHCenter
                    verticalAlignment: Label.AlignVCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                }
            }
        }

}
