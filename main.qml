import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import MyRectangle 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    CppRectangle{
        id: myRect
        width: 100
        height: 100
    }

    Rectangle {
        id: rect
        width: myRect.width
        height: myRect.height
        color: "red"
        anchors.centerIn: parent

        MouseArea{
            anchors.fill: parent
            onClicked: {
                myRect.width += 1
                myRect.height += 1
                myRect.showRectangleSize()
            }
        }
    }

}
