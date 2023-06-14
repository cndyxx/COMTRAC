import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Material

ToolBar {
    property string pageTitle
    property string navigationStyle

    width: parent.width
    height: parent.height * 0.10
    Material.background: "white"
    Material.foreground: "dimgrey"

    RowLayout {
        anchors.fill: parent
        ToolButton {
            id: toolbtn
            Image {
                source: {
                    if (navigationStyle === "menu")
                        return "../../assets/menu.png";
                    else
                        return "../../assets/plus.png";
                }
                width: parent.width/3
                height: parent.height/3
                anchors.centerIn: parent
                //anchors.rightMargin: 5
            }
// TODO: sliding menu
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
            Layout.fillWidth: true
        }
// deaktivierter Button, um das Label zu zentrieren
        ToolButton {
            id: toolbtn2
            text: qsTr("")
            enabled: false
        }

    }
}











