import QtCore
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import "./Components"
Item {
    id: homeScreen
    property date currentDate: new Date()
    Background{ id: background}
    ListModel {
        id: buttonModel
        ListElement{
            title: "Symptomtagebuch"
            text: "Symptome • Symptomverlauf "
            page: "SymptomDiary.qml"
        }
        ListElement{
            title: "Medikation"
            text: "Medikamente • Medikationsplan"
            page: "Medication.qml"
        }
        ListElement{
            title: "Chat"
            text: "Termine • Rezepte • Fragen"
            page: "Chat.qml"
        }
        ListElement{
            title: "Videotelefonie"
            text: "Videosprechstunde"
            page: "VideoTelephony.qml"
        }
    }

    ColumnLayout{
        anchors.centerIn: parent
        spacing: 10
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
                buttonWidth: homeScreen.width * 0.9
                Text {
                    text:  model.title
                    color: "white"
                    font.pixelSize: 20
                    font.family: "Arial"
                    font.weight: Font.Thin
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 8
                    elide: Text.ElideRight
                }

                Text {
                    text: model.text
                    font.pixelSize: 14
                    color: "white"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 8
                }

                onClicked: {
                    if(model.title === "Symptomtagebuch"){
                        var curDate = currentDate.toLocaleDateString(Qt.locale("de_DE"), "yyyy-MM-dd");
                        symptomModel.getSymptomsOfDate(curDate);
                    }

                    stackView.push(model.page)

                }
            }
        }
    }
}
