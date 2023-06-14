import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "./Components"


Item {
    id: login
    width: parent.width
    Background{
        color: "lightgrey"
    }

    ColumnLayout{
        id: column
        spacing: 4
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }

        Rectangle{
            Layout.alignment: Qt.AlignCenter
            id: orangeRec
            color: "orange"
            width: 150
            height: 150

        }

        TextFieldTemplate{
            Layout.topMargin: 10
            id: txtUserName
            placeholderText: "Benutzername"
            textFieldWidth: login.width *0.9

        }

        TextFieldTemplate{
            id: txtPassword
            echoMode: TextInput.Password
            placeholderText: "Passwort"
            textFieldWidth: login.width *0.9

        }

        ButtonTemplate{
            id: loginButton
            text: "Anmelden"
            buttonWidth: login.width * 0.9
            onClicked: {
                stackView.push("HomeScreen.qml")
            }
        }

    }



}



