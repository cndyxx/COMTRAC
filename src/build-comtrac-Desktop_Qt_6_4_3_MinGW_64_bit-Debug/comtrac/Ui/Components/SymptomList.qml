import QtQuick

ListView {
    id: symptomListView
    model: symptomModel.symptoms
    anchors.horizontalCenter: parent.horizontalCenter
    delegate: SymptomDelegate {
        anchors.margins: 10
        width: parent.width * 0.9
        height: 40
        property int symptomId: symptomModel.symptoms[index].id

//

//
    }

}
