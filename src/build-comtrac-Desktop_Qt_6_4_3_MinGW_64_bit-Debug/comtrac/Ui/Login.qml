import QtQuick
import QtQuick.Controls



Item{
   // anchors.fill: parent
    property string home_screen: "HomeScreen.qml"

    Loader{
        id: loader
    }

    Column{
        id: column
        spacing: 4
        anchors.centerIn: parent
        Rectangle{

            id: orangeRec
            color: "orange"
            width: 100
            height: 100

        }

        TextFieldTemplate{
            id: txtUserName
            placeholderText: "Benutzername"

        }

        TextFieldTemplate{
            id: txtPassword
            placeholderText: "Passwort"

        }

        ButtonTemplate{
            id: loginButton
            text: "Anmelden"
            onClicked: {
                login.checkLoginData(txtUserName.text, txtPassword.text)
                //loader.setSource(home_screen)
                stackView.replace(home_screen)
            }
        }




    }



}



