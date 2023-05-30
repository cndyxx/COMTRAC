import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Material




ToolBar {
    property string pageTitle
    width: parent.width
    height: parent.height * 0.10
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

//Rectangle {
//    id: header
//    property string pageTitle
//    width: parent.width
//    height: parent.height * 0.10
//    color: "white"

//    Text{
//        id: txtPageTitle
//        text: pageTitle
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.verticalCenter: parent.verticalCenter
//        color: "dimgrey"
//        font.pixelSize: 16
//        Layout.fillWidth: true
//        opacity: 0.8
//        font.family: "Arial"
//        lineHeight: 0.5
//        Rectangle {
//            anchors.top: parent.bottom
//            anchors.topMargin: 10
//            anchors.horizontalCenter: parent.horizontalCenter
//            color: "dimgrey"
//            height: 2
//            width: header.width


//        }
//    }

//}










