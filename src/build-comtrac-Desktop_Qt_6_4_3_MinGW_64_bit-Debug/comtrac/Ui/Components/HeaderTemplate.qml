import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Material




ToolBar {
    property string pageTitle
    width: parent.width
    height: parent.height * 0.1
    Material.background: "white"
    Material.foreground: "dimgrey"

    RowLayout {
        anchors.fill: parent
        ToolButton {
            id: toolbtn
            Image {
                id: arrowBack
                source:"../../assets/x_Button.png"
                width: parent.width/2
                height: parent.height/2
                anchors.centerIn: parent
            }
            onClicked: stackView.pop()

        }
        Label {
            text: pageTitle
            color: "dimgrey"
            font.pixelSize: 16
            font.family: "Arial"
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
//            Layout.fillWidth: true
        }

    }
}











