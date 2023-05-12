import QtQuick

Item {
    property string edit_medication: "editMedication.qml"
    TextFieldTemplate{
        anchors.centerIn: parent
        placeholderText: "Hier eingeben"

        //***ÄNDERN ANDERES SIGNAL***

        onTextEdited: {
            //Function that pass value from textField to the next page
            stackView.replace(edit_medication)
        }
    }
}
