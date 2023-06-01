import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material

import QtQuick.Layouts
import "../"


//Kalender


ColumnLayout {
    id: calendar
    property date currentDate: new Date()

    property var selectedDate
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
    ToolBar {
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width
        height: parent.height * 0.10
        Material.background: "white"
        Material.foreground: "dimgrey"

        background: Rectangle {
            color: "white"
            width: parent.width
            height: parent.height
        }

        RowLayout {
            anchors.fill: parent
            ToolButton {
                id: toolbtn
                anchors.left: parent.left
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
                anchors.right: parent.right
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

    //Kalenderwochenanzeige
    //    WeekNumberColumn {
    //        month: grid.month
    //        year: grid.year
    //        locale: grid.locale
    //        font.bold: false
    //        Layout.fillHeight: true
    //        spacing: grid.spacing
    //    }

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
            property bool isSelected: model.date.getDate() === selectedDate
            width: date.width
            height: date.height

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                width: 24
                height: 24

                color: isSelected ? "lightgrey" : (model.today ? "lightgrey" : "transparent")
                radius: 90

                Text {
                    id: date
                    text: model.date.getDate().toString()
                    anchors.centerIn: parent
                    font.pixelSize: 12
                    font.family: "Arial"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        //Markierung ändern
                        selectedDate = model.date.getDate()
                        console.log("SelectedDate: " + selectedDate);
                        EditSymptom.selectedDate = model.date.toLocaleDateString(Qt.locale("de_DE"), "dd.MM.yyyy");
                        console.log("Ganzes Datum " + model.date.toLocaleDateString(Qt.locale("de_DE"), "dd.MM.yyyy"));
                        //ListView anpassen
                        symptomModel.getSymptomsOfDate(model.date.toLocaleDateString(Qt.locale("de_DE"), "yyyy-MM-dd"));
                    }
                }
            }

        }

    }
}

