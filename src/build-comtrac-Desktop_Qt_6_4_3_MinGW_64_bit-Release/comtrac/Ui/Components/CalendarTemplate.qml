import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material

import QtQuick.Layouts
import "../"


//Kalender


ColumnLayout {
    id: calendar
    property date currentDate: new Date()
    property var symptomEntry: symptomModel.symptomsOfMonth
    property bool isEntry
    property var selectedDate: "dd.MM"
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.margins: 20
    width: parent.width * 0.9
    height: parent.height * 0.25
    //columns: 2
    //Functions
    function daysInMonth(date) {
        return new Date(date.getFullYear(), date.getMonth() + 1, 0).getDate();
    }

    function setMonth(date, month) {
        var oldDay = date.getDate();
        var newDate = new Date(date);
        newDate.setDate(1);
        newDate.setMonth(month);
        newDate.setDate(Math.min(oldDay, daysInMonth(newDate)));
        return newDate;
    }

    function previousMonth() {
        calendar.currentDate = setMonth(calendar.currentDate, calendar.currentDate.getMonth() - 1);

    }
    function nextMonth() {
        calendar.currentDate = setMonth(calendar.currentDate, calendar.currentDate.getMonth() + 1);

    }

    function checkSymptomsForDate(date, month) {
        // Führe eine Datenbankabfrage durch, um zu überprüfen, ob Symptome für das angegebene Datum vorhanden sind
        // Gib true zurück, wenn Symptome vorhanden sind, andernfalls false
        symptomModel.getEntryDates(month);
        var retVal = symptomModel.findDate(date);
        return retVal;
    }

    ToolBar {
        Layout.alignment: Qt.AlignHCenter
        Layout.fillWidth: true
        //        width: parent.width
//        height: parent.height * 0.10
        Material.foreground: "dimgrey"

        background: Rectangle {
            color: "white"
            width: parent.width
            height: parent.height
        }

        RowLayout {
            anchors.fill: parent
            width: calendar.width
            ToolButton {
                id: toolbtn
                Layout.alignment: Qt.LeftEdge
                Image {
                    source: "../../assets/triangle_back.png"
                    width: parent.width/3
                    height: parent.height/3
                    anchors.centerIn: parent
                }
                onClicked: previousMonth();

            }
            Label {
                text: calendar.currentDate.toLocaleString(Qt.locale("de_DE"), "MMMM yyyy")
                color: "black"
                font.pixelSize: 16
                font.family: "Arial"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                id: toolbtn2
                Layout.alignment: Qt.RightEdge
                Image {
                    source: "../../assets/triangle_next.png"
                    width: parent.width/3
                    height: parent.height/3
                    anchors.centerIn: parent
                }
                onClicked: nextMonth();
            }

        }
    }


    DayOfWeekRow {
        id: dayOfWeekRow
        locale: grid.locale
        font.bold: false
        delegate: Label {
            text: model.shortName
            font: dayOfWeekRow.font
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Layout.fillWidth: true
    }

//    //Kalenderwochenanzeige
//        WeekNumberColumn {
//            month: grid.month
//            year: grid.year
//            locale: grid.locale
//            font.bold: false
//            Layout.fillHeight: true
//            spacing: grid.spacing
//        }


    MonthGrid {
        id: grid
        month: parent.currentDate.getMonth()
        year: parent.currentDate.getFullYear()
        locale: Qt.locale("de_DE")
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: 20

        // Markiert den aktuellen Tag im Kalender
        delegate: Item {
            property bool isSelected: model.date.getDate().toString() + "." + model.date.getMonth().toString() === selectedDate
            property bool isEntry: checkSymptomsForDate(model.date.toLocaleString(Qt.locale("de_DE"), "yyyy-MM-dd"), model.date.toLocaleString(Qt.locale("de_DE"), "MM") )
            width: date.width
            height: date.height

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                width: 24
                height: 24

                color: isSelected ? "lightgrey" : "transparent"
                border.color: {
                    if(isSelected) {
                        if (model.today){
                            return "grey"
                        }
                        return "transparent"
                    }else if (model.today){
                        return "grey"
                    }
                    else{
                        return "transparent"
                    }
                }
                /*
                color: isSelected ? "lightgrey" : (model.today ? "transparent" : "transparent")
                border.color: isSelected ? "transparent" : (model.today ? "grey" : "transparent")
                border.width: isSelected ? 0 : (model.today ? 1 : 0)
                */
                radius: 90

                Text {
                    id: date
                    text: model.date.getDate().toString()
                    anchors.centerIn: parent
                    font.pixelSize: 12
                    font.family: "Arial"
                }
                // Kreis für Ereignisse
                Rectangle {
                    width: 5
                    height: 5
                    radius: width / 2
                    color: isEntry ? "black" : "transparent" // Farbe des Kreises anpassen

                    // Positionierung des Kreises
                    anchors {
                        top: parent.top
                        right: parent.right
//                        topMargin: 5
//                        rightMargin: 5
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        //Markierung ändern
                        selectedDate = model.date.getDate().toString() + "." + model.date.getMonth().toString();
                        //ListView anpassen - Symptomliste für den aktuell markierten Tag anzeigen
                        symptomModel.getSymptomsOfDate(model.date.toLocaleDateString(Qt.locale("de_DE"), "yyyy-MM-dd"));
                    }
                }
            }

        }

    }
}

