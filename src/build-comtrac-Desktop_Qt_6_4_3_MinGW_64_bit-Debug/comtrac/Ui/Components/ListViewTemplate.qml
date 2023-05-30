import QtQuick

Item {
    property string headerTitle
    property var modelName
    property string textInput

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
        model: modelName

        delegate: MedicationField {
            width: header.width
            height: 40
            medicationName:  textInput
//            intakeTime: medModel.medications[index].intakeTime
        }


    }
}
