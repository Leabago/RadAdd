import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    Button {
        width: delegatRadioHeight - 10
        height: width
        anchors.left: parent.left
        anchors.margins: 5
        anchors.verticalCenter: parent.verticalCenter
        background: Rectangle {
            border.width: 1
            radius: height / 10
        }
    }
}
