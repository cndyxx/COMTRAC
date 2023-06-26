import QtQuick 2.15
import "./Components"
Item {

    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Videotelefonie"
        navigationStyle: "menu"
    }
    Rectangle {
        width: parent.width * 0.8
        height: parent.height * 0.25
        border.color: "dimgrey"
        border.width: 2
        anchors.top: header.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
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
