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
//    CalendarTemplate {
//        id: calendar
//        anchors.top: header.bottom
//        anchors.topMargin: 50
//        anchors.left: parent.left; anchors.right: parent.right
//        anchors.leftMargin: 20; anchors.rightMargin: 20
//    }


    //List View
    SymptomList {
        id: symptomListView
        spacing: 15
        anchors.top: header.bottom
        anchors.topMargin: 30
        width: parent.width
        height: parent.height * 0.25
    }

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
        onClicked: stackView.push("findSymptom.qml")

    }


}
