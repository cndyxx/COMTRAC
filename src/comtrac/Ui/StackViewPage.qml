import QtQuick
import QtQuick.Controls

Item {
    property string login_page: "Login.qml"

    StackView {
        id: stackView
        anchors.fill: parent     
        initialItem: login_page
    }
}
