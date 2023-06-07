import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts




ButtonTemplate{
    id: button
    property date selectedTime: new Date(0, 0, 0, 8, 0)
    property var intakeTime: []
    signal saveClicked(string text)
    text: selectedTime.toLocaleTimeString("hh:mm")

    onClicked: dialog.open()
    Popup {
        id: dialog

        width: 350
        height: 100


        Rectangle {
            width: parent.width
            height: parent.height
            color: "grey"
            radius: 10
            ColumnLayout {
                width: parent.width
                height: parent.height
                anchors.margins: 10
                Text {
                    anchors.margins: 10
                    text: "Einnahmezeit:"
                    color: "white"
                    font.family: "Arial"
                    font.weight: Font.Thin
                    font.pixelSize: 17
                }

                Row {
                    height: 100
                    spacing: 8
                    anchors.horizontalCenter: parent.horizontalCenter
                    Tumbler {
                        id: hourTumbler
                        visibleItemCount: 3
                        Layout.fillWidth: true
                        height: parent.height
                        model: 24
                        currentIndex: 8
                        delegate: Text {
                            text: index.toString().padStart(2, "0")

                            color: "white"
                            font.family: "Arial"
                            font.weight: Font.Thin
                            font.pixelSize: 25
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            opacity: 1.0 - Math.abs(Tumbler.displacement) / hourTumbler.visibleItemCount
                            scale: opacity

                        }

                    }

                    Tumbler {
                        id: minuteTumbler
                        visibleItemCount: 3
                        Layout.fillWidth: true
                        height: parent.height
                        model: 60
                        spacing: 2
                        delegate: Text {
                            text: index.toString().padStart(2, "0")
                            color: "white"
                            font.family: "Arial"
                            font.weight: Font.Thin
                            font.pixelSize: 25
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            opacity: 1.0 - Math.abs(Tumbler.displacement) / minuteTumbler.visibleItemCount
                            scale: opacity
                        }

                    }

                }
                RowLayout {
                    ButtonTemplate{
                        text: "Abbrechen"
                        Layout.fillWidth: true
                        buttonWidth: parent.width / 2
                        buttonHeight: parent.height * 0.25
                    }
                    ButtonTemplate{
                        text: "Speichern"
                        Layout.fillWidth: true
                        buttonWidth: parent.width / 2
                        buttonHeight: parent.height * 0.25
                        onClicked: {
                            selectedTime = new Date(0, 0, 0, hourTumbler.currentIndex, minuteTumbler.currentIndex)
                            console.log("Ausgewählte Zeit: " + selectedTime.toLocaleTimeString("hh:mm"))
                            onClicked: {
                                // ...

                                // Signal auslösen und den ausgewählten Text übergeben
                                saveClicked(selectedTime.toLocaleTimeString("hh:mm"))
                                dialog.close()
                            }

                        }
                    }
                }
            }
        }
    }
}




