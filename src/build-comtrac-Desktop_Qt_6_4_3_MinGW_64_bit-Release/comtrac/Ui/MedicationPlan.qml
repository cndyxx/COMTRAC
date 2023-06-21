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

    Connections {
        target: medModel  // Das Symptom-Modellobjekt in QML
        function onMedicationsChanged() {
            // Aktualisiere das Modell der ListView
            medicationListView.model = medModel.medications;
            //symptomListView.model.append(symptomModel.symptoms);
        }
    }
    ListView {
        id: medicationListView
        spacing: 10
        anchors.top: header.bottom
        anchors.topMargin: 30
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        width: parent.width
        height: parent.height
        model: medModel.medications

        delegate: MedicationDelegate {
            width: parent.width * 0.9
            height: 60
            medicationName:  medModel.medications[index].name
            intakeTime: medModel.medications[index].intakeTime
            onClicked: {
                console.log("ID " + medModel.medications[index].id)
                medModel.setSingleMedication(medicationListView.model[index]);
                stackView.push("editMedication.qml", {"pageState" : 1})
            }
        }


    }

}
