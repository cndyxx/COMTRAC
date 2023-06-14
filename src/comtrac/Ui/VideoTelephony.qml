import QtQuick 2.15
import "./Components"
Item {

    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Videotelefonie"
        navigationStyle: "menu"
    }

    ButtonTemplate {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        buttonWidth: parent.width * 0.9
        text: "Videotelefonie starten"
        onClicked: {
            stackView.push("WaitingRoom.qml")
        }
    }
}
