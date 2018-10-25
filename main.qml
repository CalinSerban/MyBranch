import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
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
        onProgressChanged: {
            progressAnimation.to = progress
            progressInfo.text = qsTr(progress + "%")
            progressAnimation.restart()
        }
    }

    Rectangle {
        id: rect
        width: myRect.width
        height: myRect.height
        color: "red"
        anchors.centerIn: parent

        RotationAnimation on rotation {
            id: myRotation
            loops: 2
            from: 0
            to: 360
            duration: 2000
            running: false
        }

        MouseArea {
            id: myArea
            anchors.fill: parent
            onClicked: {
                myRect.calculateStuff2()
            }
        }
    }

    ProgressBar {
        id: progressBar
        value: 0
        minimumValue: 0
        maximumValue: 100
        width: 210
        height: 30
        anchors {
            left: rect.right
            leftMargin: 10
            top: rect.verticalCenter
        }
        style: ProgressBarStyle {
            background: Rectangle {
                radius: 2
                color: "lightgray"
                border.color: "gray"
                border.width: 1
                implicitWidth: 200
                implicitHeight: 24
            }

            progress: Rectangle {
                color: "lightgreen"
                border.color: "steelblue"
            }
        }

        NumberAnimation {
            id: progressAnimation
            target: progressBar
            property: "value"
        }

        Text {
            id: progressInfo
            anchors.centerIn: parent
            color: "blue"
            text: qsTr("0%")
        }
    }
}
