import QtCore
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import "./Components"
Page {
    id: homeScreen

    property string symptom_diary: "SymptomDiary.qml"
    property string medication: "Medication.qml"
    property string chat: "chat.qml"
    property string vidoe_telephony: "VideoTelephony.qml"

    property string stack_view: "Ui/StackViewPage.qml"

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
                stackView.push(symptom_diary)
            }
        }
        ButtonTemplate{
            id: medicationButton
            text: "Medikation"
            onClicked: {
                stackView.push(medication)
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


}
