import QtQuick
import QtQuick.Controls

Item {
    //Einnahmezeiten
    ListView {
        implicitWidth: parent.width
        implicitHeight: 50
        model: ListModel {
            ListElement {

            }
            ListElement {

            }
            ListElement {

            }
            ListElement {

            }
        }

        delegate: Button {
            width: header.width
            height: 40
            text: model
        }

        spacing: 5
    }
}
