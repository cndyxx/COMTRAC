import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtQuick.Layouts
import "../"


GridLayout {
    readonly property date currentDate: new Date()
    width: parent.width * 0.9
    height: parent.height * 0.25
    columns: 2
    ToolBar {
        Layout.column: 1
        anchors.bottom: dayOfWeekRow.top
        width: parent.width
        height: parent.height
        Material.background: "white"
        Material.foreground: "black"
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("<")
                // onClicked: letzten Monat anzeigen
            }

            Label {
                text: currentDate.toLocaleString(Qt.locale("de_DE"), "MMMM yyyy")
                font.pixelSize: Qt.application.font.pixelSize * 1.25
                anchors.top: parent.top
            }
            ToolButton {
                text: qsTr(">")
                // onClicked: Nächsten Monat anzeigen
            }
        }
    }
    DayOfWeekRow {
        id: dayOfWeekRow
        locale: grid.locale
        Layout.fillWidth: true
        Layout.column: 1
        font.bold: false
    }

    WeekNumberColumn {
        month: grid.month
        year: grid.year
        locale: grid.locale
        font.bold: false
        Layout.fillHeight: true
        spacing: grid.spacing
    }

    MonthGrid {
        id: grid
        month: parent.currentDate.getMonth()
        year: parent.currentDate.getFullYear()
        locale: Qt.locale("de_DE")
        Layout.fillHeight: true
        Layout.fillWidth: true
        spacing: 10
        // Markiert den aktuellen Tag im Kalender
        delegate: Item {
            //            width: grid.cellWidth
            //            height: grid.cellWidth
            width: date.width
            height: date.height

            Rectangle {
                Layout.fillWidth: true
                Layout.fillHeight: true
                width: parent.width
                height: parent.height
                color: model.today ? "grey" : "transparent" // Farbe des aktuellen Tages
                radius: 5

                Text {
                    id: date
                    text: model.date.getDate().toString()
                    anchors.centerIn: parent
                    font.pixelSize: 12
                    font.family: "Arial"
                }
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    var datum = model.date.getDate() + "." + model.date.getMonth() + "." + model.date.getFullYear();
                    SymptomDiary.entryDate = datum
                    console.log("Day: " + model.date.getDate())
                    console.log("Month: " + model.date.getMonth())
                    console.log("Selected Year "+ model.date.getFullYear())
                    // SymptomDiary.symptomData =
                }
            }







        }
    }
}
