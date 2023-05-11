import QtQuick
import QtQuick.Controls


Item{
   // anchors.fill: parent
    property string home_screen: "HomeScreen.qml"
    Column{
    anchors.centerIn: parent
        Rectangle{
            id: orangeRec

            color: "orange"
            width: 100
            height: 100

        }
        Rectangle{
            color: "blue"
            width: 100
            height: 100

        }

        TextField{
            id: txtUserName
            placeholderText: "Benutzername"

        }

        TextField{
            id: txtPassword
            placeholderText: "Passwort"

        }

        RoundButton{
            id: buttonLogin
            text: "Anmelden"
            onClicked:{
                login.checkLoginData(txtUserName.text, txtPassword.text);
                stackView.replace(home_screen)
            }

        }

    }


}



