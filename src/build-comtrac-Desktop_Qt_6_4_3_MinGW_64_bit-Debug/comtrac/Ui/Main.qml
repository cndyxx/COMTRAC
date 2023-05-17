import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window



ApplicationWindow {
    id: root
    width: 250
    height: 500
    visible: true
    title: qsTr("COMTRAC")

    property string stack_view: "StackViewPage.qml"


    footer: Rectangle{
        id: footer
        color: "dimgrey"
        width: parent.width
        height: 30
        visible: true
    }

    Loader{
        id: loader
        anchors.fill: parent
        source: stack_view

    }



}
