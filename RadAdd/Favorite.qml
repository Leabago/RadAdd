import QtQuick 2.12
import QtQuick.Controls 2.12


import "./Switch" as MySwitch

import QtQuick.Shapes 1.12

Page {
    ListView{
        id: radioListMyRadio
        anchors.fill: parent
        model: favorite
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
