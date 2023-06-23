import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "./Components"


Item {
    id: symptomHistory

    function getWeeksInYear(year) {
        var date = new Date(year, 1, 1);
        var calendarWeek;
        console.log("Wochentag " + date.getDay())
        if(date.day === 4){ // Prüfen, ob der 01.01.yyyy ein Donnerstag ist (Do: 4)
            calendarWeek = 53;
        }
        else {
            calendarWeek = 52;
        }
        console.log("Kalenderwoche: " + calendarWeek)
        return calendarWeek;
    }

    property date currentDate: new Date()
    property var symptom: symptomModel.weekSymptoms
    
    Background {
        id: background
    }
    HeaderTemplate {
        id: header
        pageTitle: "Symptomverlauf"
    }

    Connections {
        target: symptomModel  // Das Symptom-Modellobjekt in QML
        function onWeekSymptomsChanged() {
            // Aktualisiere das Modell der ListView
            symptomListView.model = symptomModel.weekSymptoms;
            //symptomListView.model.append(symptomModel.symptoms);
        }
    }
    Label {
        id: yearLabel
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: header.bottom
        anchors.margins: 5
        text: currentDate.getFullYear().toLocaleString("yyyy")
        font.family: "Arial"
        font.pixelSize: 17
        color: "dimgrey"
    }

    ListModel{
        id: calendarWeekModel
        ListElement{calendarWeek: '24'; backgroundColor: "lightgrey"; borderColor: "lightgrey"}
        ListElement{calendarWeek: '25'; backgroundColor: "darkgrey"; borderColor: "darkgrey"}
        ListElement{calendarWeek: '26'; backgroundColor: "darkgrey"; borderColor: "black"}
        ListElement{calendarWeek: '27'; backgroundColor: "lightgrey"; borderColor: "lightgrey"}
        ListElement{calendarWeek: '28'; backgroundColor: "grey"; borderColor: "grey"}
        ListElement{calendarWeek: '29'; backgroundColor: "darkgrey"; borderColor:  "darkgrey"}
        ListElement{calendarWeek: '30'; backgroundColor: "lightgrey"; borderColor: "lightgrey"}
        ListElement{calendarWeek: '31'; backgroundColor: "lightgrey"; borderColor: "lightgrey"}


    }

    Rectangle {
        id: borderRectangle
        anchors.top: yearLabel.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.9
        height: parent.height * 0.3
        color: "white"
        border.width: 2
        border.color: "lightgrey"
        Rectangle {
            width: 12
            height: 12
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            Image {
                width: parent.width
                height: parent.height
                source: "../assets/triangle_back.png"
            }
        }
        GridView {
            id: calendarWeekView
            anchors.left: parent.left
            anchors.leftMargin: 18
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.right: parent.right
            anchors.rightMargin: 30
            cellWidth: 60; cellHeight: 60
            Layout.fillHeight: true
            Layout.fillWidth: true
            focus: true
            width: 350
            height: 150
            flow: Qt.LeftToRight | GridView.FlowTopToBottom

            model: calendarWeekModel
            delegate: Button {
                width: 55
                height: 55
                contentItem: Text{
                    text: "KW " + /*(index + 1)*/ /*calendarWeekView.model[index].*/calendarWeek
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle {
                    id: rectCalendarWeek
                    color: backgroundColor
                    width: 55
                    height: rectCalendarWeek.width
                    radius: 10
                    border.color: borderColor
                    border.width: 2

                }
                onClicked: {
                    console.log("Test")
                    symptomModel.getCalendarWeekDate(2023, calendarWeek);

                }
            }
        }


        Rectangle {
            width: 12
            height: 12
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            Image {
                width: parent.width
                height: parent.height
                source: "../assets/triangle_next.png"
            }
        }

        Rectangle {
            width: parent.width *0.5
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20

            RowLayout {
                Text {
                    id: txtLittle
                    text: "wenig"
                    font.family: "Arial"
                    font.pixelSize: 12
                    anchors.left: parent.left

                }
                RowLayout {
                    Repeater {
                        anchors.left: txtLittle.right
                        model: ["lightgrey", "darkgrey", "grey", "black"]
                        delegate: Rectangle {
                            width: 10
                            height:10
                            color: modelData
                        }
                    }
                }
                Text {
                    text: "viel"
                    font.family: "Arial"
                    font.pixelSize: 12
                    anchors.right: parent.right
                }
            }
        }
    }


    ListView {
        id: symptomListView
        spacing: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        width: parent.width
        height: parent.height * 0.40
        model: symptom
        clip: true
        anchors.horizontalCenter: parent.horizontalCenter
        delegate: SymptomDelegate {
            anchors.margins: 10
            width: parent.width * 0.9
            height: 50

            onClicked: {
                symptomModel.getSymptomEntries(symptomListView.model[index].name);
                stackView.push("singleSymptomHistory.qml")
            }
        }
    }
    
}

