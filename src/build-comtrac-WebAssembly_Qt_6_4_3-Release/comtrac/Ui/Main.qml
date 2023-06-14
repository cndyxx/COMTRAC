import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import "./Components"


Window {
    id: root
    width: 300
    height: 550
    visible: true
    title: qsTr("COMTRAC")

    property string stack_view: "Components/StackViewPage.qml"

    Loader{
        id: loader
        anchors.fill: parent
//        source: stack_view


    }



}
