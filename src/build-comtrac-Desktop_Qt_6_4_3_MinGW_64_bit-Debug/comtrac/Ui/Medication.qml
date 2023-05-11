import QtQuick

Item {

    Column{
        spacing: 4
        anchors.centerIn: parent
        ButtonTemplate{
            id: addMedication
            text: "Medikament hinzufügen"

            onClicked: {
                stackView.pop
            }
        }

        ButtonTemplate{
            id: medicationPlan
            text: "Mediaktionsplan"

            onClicked: {

            }
        }


    }


}
