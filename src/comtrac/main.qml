import QtQuick
import QtQuick.Controls
import QtQuick.Window

ApplicationWindow {
    width: 300
    height: 600
    visible: true
    title: qsTr("COMTRAC")
    Column{
        spacing: 2
        anchors.centerIn: parent
        Rectangle{

        }

        TextField{
            id: txtUserName
            placeholderText: "Benutzername"


        }
        TextField{
            id: txtPassword
            placeholderText: "Passwort"
        }


        Button{
            id: buttonLogin
            text: "Login"
            onClicked:{
                login.checkLoginData(txtUserName.text, txtPassword.text);
            }
        }
    }
}
