import QtQuick
import QtQuick.Controls

Item {
    //Einnahmezeiten
    ListView {
        implicitWidth: parent.width
        implicitHeight: 50
        model: ComboBoxTemplate.intke
        delegate: Button {

        }

        spacing: 5
    }
}
