import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"


Item {
    id: symptomHistory

    function getWeeksInYear(year) {
        var date = new Date(year, 1, 1);
        var calendarWeek;
        console.log("Wochentag " + date.getDay())
        if(date.day === 4){ // Prüfen, ob der 01.01.yyyy ein Donnerstag ist (Do: 4)
            calendarWeek = 53;
        }
        else {
            calendarWeek = 52;
        }
        console.log("Kalenderwoche: " + calendarWeek)
        return calendarWeek;
    }

    property date currentDate: new Date()
    property var symptom: symptomModel.symptoms
    
    Background {
        id: background
    }
    HeaderTemplate {
        id: header
        pageTitle: "Symptomverlauf"
    }
    Label {
        id: yearLabel
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: header.bottom
        anchors.margins: 5
        text: currentDate.getFullYear().toLocaleString("yyyy")
        font.family: "Arial"
        font.pixelSize: 17
        color: "dimgrey"
    }
    Rectangle {
        id: borderRectangle
        anchors.top: yearLabel.bottom
        anchors.margins: 5
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.98
        height: parent.height * 0.3
        color: "white"
        border.width: 2
        border.color: "dimgrey"

        GridLayout {
            id: grid
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: borderRectangle.top
            anchors.topMargin: 20
            Layout.fillHeight: true
            Layout.fillWidth: true
            width: parent.width * 0.9
            height: parent.height * 0.7
            rows: 3
            columns: 4
            flow: GridView.FlowTopToBottom | GridView.FlowLeftToRight

            Repeater {

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.leftMargin: 20
                model: 8 // Das Model mit den Daten von 52 Elementen
                delegate: Rectangle {

                    id: rectCalendarWeek
                    color: "lightgrey"
                    width: grid.width * 0.2
                    height: rectCalendarWeek.width
                    radius: 10
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: "KW" + (index +1) // ANDERS ANORDNEN !!!!

                    }
                }
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }


        }

    }


    ListView {
        id: symptomListView
        //        flickableDirection: Flickable.VerticalFlick
        //        boundsBehavior: Flickable.StopAtBounds
        spacing: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        width: parent.width
        height: parent.height * 0.40
        model: symptom
        //        ScrollBar.vertical: ScrollBar {
        //            anchors.left: symptomListView.left
        //            anchors.leftMargin: 10
        //        }
        anchors.horizontalCenter: parent.horizontalCenter
        delegate: SymptomDelegate {
            anchors.margins: 10
            width: parent.width * 0.9
            height: 40

            onClicked: {
                symptomModel.setSingleSymptom(symptomListView.model[index]);
                stackView.push("EditSymptom.qml", {"pageState" : 1})
            }
        }
    }

    //    Rectangle {
    //        anchors.top: yearLabel.bottom
    //        anchors.margins: 5
    //        anchors.horizontalCenter: parent.horizontalCenter
    //        width: parent.width * 0.98
    //        height: parent.height * 0.3
    //        color: "white"
    //        border.width: 2
    //        border.color: "dimgrey"
    
    
    
    //    }
    
}

