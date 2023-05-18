import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

//import Medication 1.0


Page {
    width: 250
    height: 500
    title: "Medikationsplan"

    function test(){
        console.log(medModel.name + " - " + medModel.intakePerDay);
    }


    ListView {
        width: parent.width
        model: medModel // Verwenden Sie das registrierte SQL-Modell

        delegate: Text {
            text: medModel.name + " - " + medModel.intakePerDay



        }

    }
    Button{
        anchors.top: parent.top
        text: "TEst"
        onClicked: test();
    }
}
