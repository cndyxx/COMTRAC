import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

//import Medication 1.0
import "./Components"

Item {


    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Medikationsplan"
    }

    ListView {
        spacing: 15
        anchors.top: header.bottom
        anchors.topMargin: 30
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        width: parent.width
        height: parent.height
        model: medModel.medications

        delegate: MedicationField {
            width: header.width
            height: 40
            medicationName:  medModel.medications[index].name
//            intakeTime: medModel.medications[index].intakeTime
        }


    }

}
