import QtQuick
import QtQuick.Controls 2.5

Rectangle {
    id: sideMenu
    height: parent / 0.5
    anchors.right: parent
    Column{

        Button{
            id: symptomDiaryButton
            text: "Symptomtagebuch"
        }
        Button{
            id: medicationButton
            text: "Medikation"
        }
        Button{
            id: chatButton
            text: "Chat"
        }
        Button{
            id: videotelephonyButton
            text: "Videotelefonie"
        }
    }




}
