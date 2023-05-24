import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

GridLayout {

    readonly property date currentDate: new Date()
    anchors.fill: parent
    columns: 2

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

        Layout.column: 1
        Layout.fillWidth: true
    }

    WeekNumberColumn {
        month: grid.month
        year: grid.year
        locale: grid.locale
        font.bold: false

//        Layout.fillHeight: true
    }

    MonthGrid {
        id: grid
        month: parent.currentDate.getMonth()
        year: parent.currentDate.getFullYear()
        spacing: 0

        readonly property int gridLineThickness: 0

        Layout.fillWidth: true
//        Layout.fillHeight: true

        delegate: MonthGridDelegate {
            id: gridDelegate
            visibleMonth: grid.month
            //eventDatabase: window.eventDatabase -> Datenbank: Symptome verbinden
        }

//        background: Item {
//            x: grid.leftPadding
//            y: grid.topPadding
//            width: grid.availableWidth
//            height: grid.availableHeight

//            // Vertical lines
////            Row {
//////                spacing: (parent.width - (grid.gridLineThickness * rowRepeater.model)) / rowRepeater.model

////                Repeater {
////                    id: rowRepeater
////                    model: 7
////                    delegate: Rectangle {
////                        width: 1
////                        height: grid.height
////                        color: "#ccc"
////                    }
////                }
////            }

//            // Horizontal lines
////            Column {
//////                spacing: (parent.height - (grid.gridLineThickness * columnRepeater.model)) / columnRepeater.model

////                Repeater {
////                    id: columnRepeater
////                    model: 6
////                    delegate: Rectangle {
////                        width: grid.width
////                        height: 1
////                        color: "#ccc"
////                    }
////                }
////            }
//        }
    }
}

//ColumnLayout {
//    width: parent.width
//    height: parent.height * 0.25
//    DayOfWeekRow {
//        locale: grid.locale
//        Layout.fillWidth: true
//    }

//    MonthGrid {
//        id: grid
//        month: Calendar.December // this is how the Calendar can be used
//        year: 2022
//        locale: Qt.locale("de_DE")
//        Layout.fillWidth: true
//        delegate: Text {
//            horizontalAlignment: Text.AlignHCenter
//            verticalAlignment: Text.AlignVCenter
//            opacity: model.month === control.month ? 1 : 0
//            text: model.day
//            font: control.font

//            required property var model
//        }

//    }
//}
