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
        ListElement{calendarWeek: 1}
        ListElement{calendarWeek: 2}
        ListElement{calendarWeek: 3}
        ListElement{calendarWeek: 4}
        ListElement{calendarWeek: 5}
        ListElement{calendarWeek: 6}
        ListElement{calendarWeek: 7}
        ListElement{calendarWeek: 8}


    }

    Rectangle {
        id: borderRectangle
        anchors.top: yearLabel.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.98
        height: parent.height * 0.3
        color: "white"
        border.width: 2
        border.color: "dimgrey"
        Button {
            width: 10
            height: 10
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter
        }
        GridView {
            id: calendarWeekView
            anchors.left: parent.left
            anchors.leftMargin: 30
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

            model: ['24', '25', '26', '27', '28', '29', '30', '31']
            delegate: Button {
                width: 50
                height: 50
                contentItem: Text{
                    text: "KW " + /*(index + 1)*/ calendarWeekView.model[index]
                    font.pixelSize: 12
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }

                background: Rectangle {
                    id: rectCalendarWeek
                    color: "lightgrey"
                    width: 50
                    height: rectCalendarWeek.width
                    radius: 10

                }
                onClicked: {
                    console.log("Test")
                    symptomModel.getCalendarWeekDate(2023, calendarWeekView.model[index]);

                }
            }
        }

        //        CalendarWeeksTemplate {
        //            anchors.left: parent.left
        //            anchors.leftMargin: 20
        //            anchors.top: parent.top
        //            anchors.topMargin: 30
        //            anchors.right: parent.right
        //            anchors.rightMargin: 30
        //        }
        Button {
            width: 10
            height: 10
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {}
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
                        model: ["lightgrey", "grey", "darkgrey", "black"]
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
            height: 40

            onClicked: {
                symptomModel.setSingleSymptom(symptomListView.model[index]);
                stackView.push("EditSymptom.qml", {"pageState" : 1})
            }
        }
    }
    
}

