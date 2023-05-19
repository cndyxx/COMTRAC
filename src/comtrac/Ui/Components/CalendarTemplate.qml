//import QtQuick 2.15
//import QtQuick.Controls 2.15
//import QtQuick.Layouts 1.15
//import QtQuick.Controls.Material 2.15


import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Rectangle {


    GridLayout {
        id: calendarLayout
        anchors.top: parent.top
        columns: 7
       // spacing: 2

        Repeater {
            id: daysOfWeek
            model: ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
            Text {
                text: modelData
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Repeater {
            id: calendarDays
            model: 31 // oder die Anzahl der Tage des aktuellen Monats
            Text {
                text: modelData
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#000000"
                opacity: enabled ? 1.0 : 0.3
            }
        }
    }
}
/*
Rectangle {
    id: root

    property int month: selectedDate.getMonth()
    property int year: selectedDate.getFullYear()
    property int day: selectedDate.getDate()
    property int weekday: selectedDate.getDay()
    property int daysInMonth: new Date(year, month + 1, 0).getDate()

    property date selectedDate: new Date()

    property int _start_weekday: new Date(year, month, 1).getDay()

    implicitWidth: layout.width
    implicitHeight: layout.height
    color: "transparent"

    ColumnLayout {
        id: layout

        Rectangle {
            id: title
            implicitHeight: 20
            Layout.fillWidth: true
            color: "transparent"

            Text {
                anchors.fill: parent
                anchors.leftMargin: 8

                text: selectedDate.toLocaleDateString(Qt.locale(), "ddd, MMM d")
                font.pixelSize: 40
            }
        }

        Rectangle {
            color: "transparent"
            implicitHeight: 28
            Layout.fillWidth: true
        }

        Rectangle {
            id: controls
            color: "transparent"
            implicitHeight: 24

            RowLayout {
                anchors.fill: parent
                anchors.leftMargin: 8
                spacing: 16
                Layout.alignment: Qt.AlignHCenter

                Text {
                    text: selectedDate.toLocaleDateString(Qt.locale(), "MMMM yyyy")
                    font.pixelSize: 16
                }

                RoundButton {
                    id: monthButton
//
                    Material.elevation: 0
                    onClicked: {
                        monthMenu.open()
                    }

                    Menu {
                        id: monthMenu
                        Repeater {
                            model: 12
                            MenuItem {
                                text: new Date(2020, index, 1).toLocaleDateString(Qt.locale(), "MMMM")
                                onTriggered: {
                                    set_month(index)
                                    monthMenu.close()
                                }
                            }
                        }
                    }
                }


                // 2 button to change month <>
                RowLayout {
                    Layout.alignment: Qt.AlignRight
                    spacing: 8

                    RoundButton {
                        Material.background: 'transparent'
//                        contentItem: MIcon {
//                            icon: 'navigate_before'
//                            color: 'black'
//                            size: 16
//                        }
                        onClicked: {
                            set_month(month - 1)
                        }
                    }

                    RoundButton {
                        Material.background: 'transparent'
//                        contentItem: MIcon {
//                            icon: 'navigate_next'
//                            color: 'black'
//                            size: 16
//                        }
                        onClicked: {
                            set_month(month + 1)
                        }
                    }
                }
            }
        }

        Rectangle {
            color: "transparent"
            implicitHeight: 16
            Layout.fillWidth: true
        }

        Rectangle {
            color: Material.accent
            implicitHeight: 1
            Layout.fillWidth: true
        }

        // Sunday - Saturday
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            spacing: 4

            Repeater {
                model: 7
                Rectangle { // just for spacing
                    width: 40
                    height: 40
                    color: "transparent"

                    Text {
                        anchors.centerIn: parent
                        Layout.fillWidth: true
                        text: new Date(2020, 0, index - 2).toLocaleDateString(Qt.locale(), "ddd").slice(0, 1)
                        font.pixelSize: 16
                        horizontalAlignment: Text.AlignHCenter
                    }
                }
            }
        }

        // calendar
        GridLayout {
            id: grid
            columns: 7
            rows: 6
            columnSpacing: 4
            rowSpacing: 4

            Repeater {
                model: 42

                delegate: Rectangle {
                    color: default_color()
                    radius: 20

                    border.width: 1
                    border.color: is_selected() ? Material.accent : "transparent"

                    width: 40
                    height: 40

                    Text {
                        anchors.centerIn: parent
                        text: get_day()
                        color: in_current_month() ? 'black' : 'gray'
                    }

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {
                            cursorShape = Qt.PointingHandCursor
                            color = Material.color(Material.accent, Material.Shade200)
                        }
                        onExited: {
                            cursorShape = Qt.ArrowCursor
                            color = default_color()
                        }
                        onClicked: {
                            var _day = get_day()
                            if (!in_current_month()){
                                if (index < _start_weekday) {
                                    set_month(month - 1)
                                } else {
                                    set_month(month + 1)
                                }
                            }
                            set_day(_day)
                        }
                    }

                    function default_color() {
                        return 'transparent'
                    }

                    function in_current_month() {
                        return index >= _start_weekday && (index - _start_weekday) < daysInMonth
                    }

                    function is_selected() {
                        return day == get_day() && in_current_month()
                    }

                    function get_day() {
                        var this_day = index - _start_weekday + 1
                        if (this_day > daysInMonth) {
                            return this_day - daysInMonth
                        } else if (this_day < 1) {
                            return new Date(year, month, 0).getDate() + this_day
                        } else {
                            return this_day
                        }
                    }
                }
            }
        }
    }

    function set_month(month) {
        var days_in = new Date(year, month + 1, 0).getDate()
        var new_day = Math.min(day, days_in)
        selectedDate = new Date(year, month, new_day)
    }

    function set_day(day) {
        day = Math.min(day, daysInMonth)
        selectedDate = new Date(year, month, day)
    }
} */
