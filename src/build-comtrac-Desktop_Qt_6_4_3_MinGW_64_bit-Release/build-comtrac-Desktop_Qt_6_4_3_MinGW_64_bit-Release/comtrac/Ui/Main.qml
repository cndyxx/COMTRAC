import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window

import "./Components"


Window {
    id: root

    visible: true
    title: qsTr("COMTRAC")

    property string stack_view: "Components/StackViewPage.qml"
        Rectangle{
            id: rectangle
            width: 300
            height: 550
            anchors.horizontalCenter: root
            anchors.verticalCenter: root
        }

    Loader{
        id: loader
        anchors.fill: rectangle
        source: stack_view


    }



}
