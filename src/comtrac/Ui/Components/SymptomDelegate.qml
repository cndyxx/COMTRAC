import QtQuick
import QtQuick.Controls
import QtQuick.Layouts


Button {
    property var symptomData: symptomListView.model[index]
    property color symptomColor: "lightgrey"
    property bool setBackgroundColor: false

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
        id: backgroundRectangle
        width: parent.width
        height: 60
        border.color: "darkgrey"
        border.width: 2
        color: "lightgrey"

        radius: 5

    }
    Button {
        width: 25
        height: 25
        anchors {
            top: parent.top
            right: parent.right
            topMargin: 5
            rightMargin: 5
        }
        contentItem: Image  {

            source: "../../assets/pencil.png";

            // Positionierung des Bildes

        }
        background: Rectangle {
            color: backgroundRectangle.color
        }

        onClicked: {
            symptomModel.setSingleSymptom(symptomData);
            stackView.push("../EditSymptom.qml", {"pageState" : 2})
        }
    }

}

