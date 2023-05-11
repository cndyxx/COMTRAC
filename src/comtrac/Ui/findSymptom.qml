import QtQuick

Item {
    property string edit_symptom: "editSymptom.qml"
    TextFieldTemplate{
        anchors.centerIn: parent
        placeholderText: "Hier eingeben"

        //***ÄNDERN ANDERES SIGNAL***

        onTextEdited: {
            //Function that pass value from textField to the next page
            stackView.replace(edit_symptom)
        }
    }
}
