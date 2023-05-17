import QtQuick
import QtQuick.Controls


Item{
    width: parent.width
    height: parent.height

    readonly property bool portraitMode: homeScreen.width < homeScreen.height
    Action {
        id: navigateBackAction
        icon.name: stackView.depth > 1 ? "back" : "drawer"
        onTriggered: {
            if (stackView.depth > 1) {
                stackView.pop()
                listView.currentIndex = -1
            } else {
                drawer.open()
            }
        }
    }
    header: ToolBar {
        RowLayout {
            spacing: 20
            anchors.fill: parent
           // anchors.leftMargin: !parent.portraitMode ? drawer.width : undefined

            ToolButton {
                action: navigateBackAction
                visible: parent.portraitMode
            }

            Label {
                id: titleLabel
                //text: listView.currentItem ? (listView.currentItem as ItemDelegate).text : qsTr("COMTRAC")
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton {
                action: optionsMenuAction

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    Action {
                        text: qsTr("Settings")

                    }
                    Action {
                        text: qsTr("Help")

                    }
                    Action {
                        text: qsTr("About")

                    }
                }
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

}
