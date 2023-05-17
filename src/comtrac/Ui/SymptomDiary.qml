import QtQuick
import QtQuick.Controls



Item {
    property string find_symptom: "findSymptom.qml"
    //Placeholder for Calendar
    Header{

    }
    CalendarTemplate{
        anchors.centerIn: parent
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
