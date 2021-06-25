import QtQuick 2.0
import QtQuick.Controls 2.12

Page {
    ListView{
        id: radioListMyRadio
        anchors.fill: parent
        model: stations
        clip: true
        highlight: Rectangle {
            color: "skyblue"
        }
        highlightFollowsCurrentItem: true
        delegate: Delegat{}

        highlightMoveDuration : -1
        highlightMoveVelocity : 1000
        currentIndex: -1
    }
}
