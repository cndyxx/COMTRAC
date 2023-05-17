import QtQuick
import QtQuick.Layouts
import QtQuick.Controls


Item{
    width: 250
    height: 40
    property string pageTitle: ""


    Rectangle {

        id: header
        width: parent.width
        height: parent.height
        color: "#00000000"

        Text {
            id: txtHeader
            text: pageTitle
            font.pixelSize: 17
            font.family: "Arial"
            font.weight: Font.Thin
            anchors.centerIn: parent
            anchors.topMargin: 3
            color: "dimgrey"

        }

        Rectangle {
            id: line
            width: parent.width
            height: 1
            anchors.top: header.bottom
            anchors.topMargin: 3
            color: "dimgrey"
        }

    }

}
//    Drawer {
//        id: drawer

//        width: Math.min(parent.width, parent.height) / 3 * 2
//        height: parent.height
//        modal: parent.portraitMode
//        interactive: parent.portraitMode ? (stackView.depth === 1) : false
//        position: parent.portraitMode ? 0 : 1
//        visible: !parent.portraitMode

//        ListView {
//            id: listView

//            focus: true
//            currentIndex: -1
//            anchors.fill: parent

//            model: ListModel {
//                ListElement { title: qsTr("Symptomtagebuch"); source: "Ui/SymptomDiary.qml" }
//                ListElement { title: qsTr("Medikation"); source: "Ui/Medication.qml" }
//                ListElement { title: qsTr("Chat"); source: "Ui/Chat.qml"}
//                ListElement { title: qsTr("Videotelefonie"); source: "Ui/VideoTelephony.qml" }
//            }

//            delegate: ItemDelegate {
//                id: delegateItem
//                width: ListView.view.width
//                text: title
//                highlighted: ListView.isCurrentItem

//                required property int index
//                required property var model
//                required property string title
//                required property string source

//                onClicked: {
//                    listView.currentIndex = index
//                    stackView.push(source)
//                    if (parent.portraitMode)
//                        drawer.close()
//                }
//            }

//            ScrollIndicator.vertical: ScrollIndicator { }
//        }
//    }


