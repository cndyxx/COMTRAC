import QtQuick
import QtQuick.Controls
import "./Components"


Item {

    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Symptomtagebuch"
    }

    ListView {
        spacing: 15
        anchors.top: header.bottom
        anchors.topMargin: 30
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        width: parent.width
        height: parent.height
        model: symptomModel.symptoms

        delegate: SymptomEntry {
            width: header.width
            height: 40
            symptomName:  symptomModel.symptoms[index].name
//            intakeTime: medModel.medications[index].intakeTime
        }


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
