import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material

import QtQuick.Layouts
import "../"



//    ToolBar {
//        Layout.column: 1
//        anchors.bottom: dayOfWeekRow.top
//        width: parent.width
//        height: parent.height
//        Material.background: "white"
//        Material.foreground: "black"
//        RowLayout {
//            anchors.fill: parent
//            ToolButton {
//                text: qsTr("<")
//                // onClicked: letzten Monat anzeigen
//            }

//            Label {
//                text: currentDate.toLocaleString(Qt.locale("de_DE"), "MMMM yyyy")
//                font.pixelSize: Qt.application.font.pixelSize * 1.25
//                anchors.top: parent.top
//            }
//            ToolButton {
//                text: qsTr(">")
//                // onClicked: Nächsten Monat anzeigen
//            }
//        }
//    }
//Kalender


ColumnLayout {
    id: calendar
    readonly property date currentDate: new Date()
    property date currentMonth: currentDate.getMonth()
    property date currentYear: currentDate.getFullYear()
    property var selectedDate
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.margins: 20
    width: parent.width * 0.9
    height: parent.height * 0.25
    //columns: 2

    ToolBar {
        width: parent.width
        height: parent.height * 0.5
        background: Rectangle {
            color: "white"
            width: parent.width
            height: parent.height
        }
        RowLayout {
            anchors.fill: parent
            Material.foreground: "black"
            ToolButton {
                id: toolButtonBack
                Image {
                    id: arrowBack
                    source:"../../assets/triangle_back.png"
                    width: parent.width/4
                    height: parent.height/4
                    anchors.centerIn: parent
                }
                //onClicked: stackView.pop()

            }
            Text {
                text: calendar.currentDate.toLocaleString(Qt.locale("de_DE"), "MMMM yyyy")
                font.pixelSize: Qt.application.font.pixelSize * 1.25
                color: "black"
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
            }
            ToolButton {
                id: toolButtonNext
                Image {
                    id: arrowNext
                    source:"../../assets/triangle_next.png"
                    width: parent.width/4
                    height: parent.height/4
                    anchors.centerIn: parent
                }
                onClicked: {
                    var nextDate = new Date(currentYear, currentMonth, 1)
                    nextDate.setMonth(nextDate.getMonth() + 1)
                    currentMonth = nextDate.getMonth()
                    currentYear = nextDate.getFullYear()
                }

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
            width: date.width
            height: date.height

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                width: parent.width
                height: parent.height
                color: model.today ? "lightgrey" : "transparent" // Farbe des aktuellen Tages
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

