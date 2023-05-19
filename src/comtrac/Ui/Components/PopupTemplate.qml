import QtQuick
import QtQuick.Controls

Item {

    Popup{
        background: Rectangle{
            color: "grey"
            width: parent.width
            height: parent.height
        }
        Text {
            id: name
            text: qsTr("Test")
        }
    }

}


