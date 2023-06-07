import QtQuick
import QtQuick.Controls
import "./Components"

Item {
    Background {
        id: background
        color: "lightgrey"
    }

    HeaderTemplate {
        id: header
        pageTitle: "Chat"
        navigationStyle: "menu"

    }
}
