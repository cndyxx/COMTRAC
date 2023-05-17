import QtQuick
import QtQuick.Controls



Page {
    width: 250
    height: 500
    property string find_symptom: "findSymptom.qml"
    //Placeholder for Calendar
    HeaderTemplate{
        header.txtHeader.text: "Test"
//        Text {
//            id: txtHeader
//            text: "Symptomtagebuch"
//            font.pixelSize: 17
//            font.family: "Arial"
//            font.weight: Font.Thin
//            color: "dimgrey"
//        }
    }

    //nur als Probe
    RoundButton{
        text: "\u254B" //unicode Character '+'
        anchors {
            bottom: parent.bottom
            bottomMargin: 50
            right: parent.right
            rightMargin: 10
        }
        onClicked: {
            stackView.push(find_symptom)
        }
    }
    RoundButton{
        anchors {
            bottom: parent.bottom
            bottomMargin: 50
            left: parent.left
            leftMargin: 10
        }
        onClicked: {

        }
    }
    //Symptom list
    ListView{

    }

}
