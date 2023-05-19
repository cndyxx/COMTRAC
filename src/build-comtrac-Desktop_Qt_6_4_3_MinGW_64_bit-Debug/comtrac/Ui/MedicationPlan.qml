import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

//import Medication 1.0
import "./Components"

Item {
    width: parent.width
    height: parent.height
    title: "Medikationsplan"

    function test(){
        console.log(medModel.name + " - " + medModel.intakePerDay);
    }

    Background { id: background}
    HeaderTemplate { id: header; pageTitle: "Medikationsplan"}

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
