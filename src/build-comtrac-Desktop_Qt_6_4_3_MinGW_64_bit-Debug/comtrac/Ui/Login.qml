import QtQuick
import QtQuick.Layouts
import QtQuick.Controls



Item{


    property string home_screen: "HomeScreen.qml"


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

        }

        TextFieldTemplate{
            id: txtPassword
            echoMode: TextInput.Password
            placeholderText: "Passwort"

        }

        ButtonTemplate{
            id: loginButton
            text: "Anmelden"
            onClicked: {
                login.checkLoginData(txtUserName.text, txtPassword.text)
                //loader.setSource(home_screen)
                stackView.push(home_screen)
            }
        }



    }

}



