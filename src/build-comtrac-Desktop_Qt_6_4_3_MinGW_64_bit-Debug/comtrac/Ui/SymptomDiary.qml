import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"
//☰“ (U+2630)
//„☓“ (U+2613)
//„📈“ (U+1F4C8)

Item {

    Background { id: background}
    HeaderTemplate {
        id: header
        pageTitle: "Symptomtagebuch"
    }
    CalendarTemplate {
        id: calendar
        anchors.top: header.bottom
        anchors.topMargin: 50
        anchors.left: parent.left; anchors.right: parent.right
        anchors.leftMargin: 20; anchors.rightMargin: 20
    }

//    ColumnLayout {
//        id: column
//        anchors.centerIn: parent
//        anchors.top: header.bottom
//        anchors.topMargin: 10

//        spacing: 4
//        //KALENDER


//        //Symptomliste
//        ListView {

//            width: parent.width
//            height: parent.height
//            model: symptomModel.symptoms

//            delegate: SymptomEntry {
//                width: header.width
//                height: 40
//                symptomName:  symptomModel.symptoms[index].name
//                //            intakeTime: medModel.medications[index].intakeTime
//            }


//        }

//    }

    //Button
    RoundButtonTemplate {
       id: graphicButton
       anchors.left: parent.left
       anchors.bottom: parent.bottom
       anchors.margins: 14
       buttonIcon: "\u2630" //muss noch geändert werden in eine Graphik
    }
    RoundButtonTemplate {
        buttonIcon: "\u254B"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 14


    }
}
