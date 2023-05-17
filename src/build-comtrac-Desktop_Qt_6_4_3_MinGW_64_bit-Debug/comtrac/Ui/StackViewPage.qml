import QtQuick
import QtQuick.Controls

Item {
    property string login_page: "Login.qml"
//    StackView{
//        id: stackView
//        initialItem: login_page

//    }


    StackView {
        id: stackView

        anchors.fill: parent
       // anchors.leftMargin: !parent.portraitMode ? drawer.width : undefined

        initialItem: login_page /*Pane {
            id: pane

            Label {
                text: qsTr("Qt Quick Controls provides a set of controls that can be used to build complete interfaces in Qt Quick.")
                anchors.margins: 20
                anchors.top: logo.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: arrow.top
                horizontalAlignment: Label.AlignHCenter
                verticalAlignment: Label.AlignVCenter
                wrapMode: Label.Wrap
            }

        }*/
    }

}
