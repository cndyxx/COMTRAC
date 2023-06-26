import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {
    property var calendarWeek: calendarWeekView.model[index]
    id: button
    width: 50
    height: 50
    contentItem: Text{
        text: "KW " + calendarWeek
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    background: Rectangle {
        id: rectCalendarWeek
        color: "lightgrey"
        width: 50
        height: rectCalendarWeek.width
        radius: 10

    }


}



