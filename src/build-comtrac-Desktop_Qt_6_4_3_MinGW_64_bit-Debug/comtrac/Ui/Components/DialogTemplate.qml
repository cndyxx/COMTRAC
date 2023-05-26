import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Dialog {
    id: dialog
    property bool dialogVisible: false
    property var symptom: symptomModel.singleSymptom
    property int id: symptom.id()
    width: parent.width * 0.9
    height: parent.height * 0.25
    visible: dialogVisible
    Text {
        anchors.margins: 15
        anchors.top: parent.top
        font.pixelSize: 17
        font.family: "Arial"
        text: qsTr("Symptomeintrag wirklich löschen?")
    }
    standardButtons: Dialog.Yes | Dialog.No
}
