import QtQuick
import QtQuick.Controls

Page {
    property string edit_medication: "editMedication.qml"

//    HeaderTemplate{
//        pageTitle: "Medikation"
//        anchors.top: parent.top
//        anchors.horizontalCenter: parent.horizontalCenter

//    }
    header.visible: true
    TextFieldTemplate{
        anchors.topMargin: 5
        anchors.centerIn: parent
        placeholderText: "Hier eingeben"

        //***ÄNDERN ANDERES SIGNAL***
        onTextEdited: {
            //Function that pass value from textField to the next page
            stackView.push(edit_medication)
        }
    }
}
