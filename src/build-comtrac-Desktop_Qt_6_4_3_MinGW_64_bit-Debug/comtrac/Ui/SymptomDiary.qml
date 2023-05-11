import QtQuick
import QtQuick.Controls



Item {
    property string find_symptom: "findSymptom.qml"
    //Placeholder for Calendar
    Rectangle {
        width: 300
        height: 300
    }
    //nur als Probe
    Button{
        text: "Symptom hinzufügen"
        onClicked: {
            stackView.replace(find_symptom)
        }
    }
    //Symptom list
    ListView{

    }

}
