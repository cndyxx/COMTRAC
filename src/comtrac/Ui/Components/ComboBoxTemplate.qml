import QtQuick 2.0
import QtQuick.Controls 2.0


ComboBox {

    property int intakeNumber
    model: ListModel {
        id: intakePerDayModel
        ListElement { text: "Einmal pro Tag"; intakeNumber: 1}
        ListElement { text: "Zweimal pro Tag"; intakeNumber: 2}
        ListElement { text: "Dreimal pro Tag"; intakeNumber: 3}
        ListElement { text: "Viermal pro Tag"; intakeNumber: 4}
    }

}
