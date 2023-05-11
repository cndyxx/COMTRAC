import QtQuick
import QtQuick.Controls 2.5

Item {
    property string symptom_diary: "SymptomDiary.qml"
    property string medication: "Medication.qml"
    property string chat: "chat.qml"
    property string vidoe_telephony: "VideoTelephony.qml"


    Column{
        spacing: 4
        anchors.centerIn: parent
        Rectangle{
            id: orangeRec
            color: "orange"
            width: 100
            height: 100

        }
        ButtonTemplate{
            id: symptomDiaryButton
            text: "Symptomtagebuch"
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

}
