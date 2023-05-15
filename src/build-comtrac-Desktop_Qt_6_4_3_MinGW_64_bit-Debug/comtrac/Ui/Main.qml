import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window



Window {
    id: root
    width: 250
    height: 500
    visible: true
    title: qsTr("COMTRAC")

    property string stack_view: "Ui/StackViewPage.qml"


    Loader{
        id: loader
        anchors.centerIn: parent
        source: stack_view

    }



}
