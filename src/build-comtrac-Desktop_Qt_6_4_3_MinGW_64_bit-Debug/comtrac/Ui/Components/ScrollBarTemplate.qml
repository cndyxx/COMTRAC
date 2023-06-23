import QtQuick


Rectangle { // ScrollBar to be placed as a direct child of a ListView or GridView (ScrollBar won't run by itself and gives errors)
    color: 'grey'
    width: 0.01 * parent.width;
    radius: 0.5 * width
    anchors{right: parent.right;  margins: radius + 5}

    height:  parent.height   / parent.contentHeight * parent.height
    y:       parent.contentY / parent.contentHeight * parent.height
    visible: parent.height   < parent.contentHeight
}

