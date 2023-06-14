import QtCore
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import "./Components"
Item {
    id: homeScreen
    width: parent.width
    property date currentDate: new Date()
    Background{ id: background}
    ListModel {
        id: buttonModel
        ListElement{
            text: "Symptomtagebuch"
            page: "SymptomDiary.qml"
        }
        ListElement{
            text: "Medikation"
            page: "Medication.qml"
        }
        ListElement{
            text: "Chat"
            page: "Chat.qml"
        }
        ListElement{
            text: "Videotelefonie"
            page: "VideoTelephony.qml"
        }
    }

    ColumnLayout{
        anchors.centerIn: parent
        Rectangle{
            Layout.alignment: Qt.AlignCenter
            id: orangeRec
            color: "orange"
            width: 150
            height: 150
        }

        Repeater {
            model: buttonModel
            delegate: ButtonTemplate {
                text: model.text
                buttonWidth: homeScreen.width * 0.9
                onClicked: {
                    if(model.text === "Symptomtagebuch"){
                        var curDate = currentDate.toLocaleDateString(Qt.locale("de_DE"), "yyyy-MM-dd");
                        symptomModel.getSymptomsOfDate(curDate);
                    }

                    stackView.push(model.page)

                }
            }
        }
    }
}
