import QtQuick 2.0

Item {
    property var  marginsAll: 5
    Rectangle {
        anchors.bottomMargin: marginsAll
        anchors.topMargin: marginsAll
        anchors.rightMargin: marginsAll

        anchors.fill: parent
        radius: height / 10

        border {
            color: "black"
            width: 2
        }
    }
}
