import QtQuick
import QtQuick.Controls
import QtQml.Models

Item {

    Popup {
           id: popUpTimePicker
           width: 200
           height: 200
           closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
           Tumbler {
               id: hoursTumbler
               model: 24
               delegate: delegateComponent
           }

           Tumbler {
               id: minutesTumbler
               model: 60
               delegate: delegateComponent
           }
       }

}
