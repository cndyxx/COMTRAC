import QtQuick 2.0
import QtQuick.Controls 2.0


RadioButton {
    id: root


    property color checkedColor: "grey"
    //text: qsTr("RadioButton")


    hoverEnabled: true
    indicator: Rectangle {
        x: root.leftPadding
        anchors.verticalCenter: parent.verticalCenter
        width: 26; height: width
        antialiasing: true
        radius: width/2
        border.width: 2
        border.color: root.checkedColor


        Rectangle {
            anchors.centerIn: parent
            width: parent.width*0.7; height: width
            antialiasing: true
            radius: width/2
            color: {
                if (checked)
                    return checkedColor


                if (hovered)
                    return "#BDC3C7"


                return "#00000000"
            }
            visible: {
                if (checked)
                    return true


                if (hovered)
                    return true


                return false
            }
            opacity: visible


            Behavior on opacity {
                NumberAnimation {
                    duration: 250
                }
            }
        }
    }
}
