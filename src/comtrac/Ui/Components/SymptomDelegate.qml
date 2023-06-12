import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Button {
    property var symptomData: symptomListView.model[index]
    property color symptomColor: "lightgrey"

    anchors.horizontalCenter: parent.horizontalCenter
    width: parent.width
    height: parent.height
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: symptomData.name
        color: "black"
        font.pixelSize: 18
        Layout.fillWidth: true
        font.family: "Arial"
        lineHeight: 0.5
    }
    background: Rectangle {
        width: parent.width
        height: 50
        border.color: "darkgrey"
        border.width: 2
        color: switch (symptomData.name) {
               case "Fieber":
                   return "red";
               case "Kopfschmerzen":
                   return "blue";
               case "Übelkeit":
                   return "green";
               default:
                   return "gray";
           }
        radius: 5

    }
    Image  {

        source: "../../assets/pencil.png";
        width: 18
        height: 18
        // Positionierung des Bildes
        anchors {
            top: parent.top
            right: parent.right
            topMargin: 5
            rightMargin: 5
        }
    }

}

