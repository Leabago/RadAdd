import QtQuick 2.0
import QtQuick.Controls 2.12

import QtQuick 2.12


//import QtQuick.Layouts 1.15
//import Qt5Compat.GraphicalEffects
import App 1.0

import Qt.labs.platform 1.1


Page {
    ListView{
        id: myId
        anchors.fill: parent
        model: my
        clip: true
        highlight: Rectangle {
            color: "skyblue"
        }
        highlightFollowsCurrentItem: true
        delegate: DelegatMy{}

        highlightMoveDuration : -1
        highlightMoveVelocity : 1000
        currentIndex: -1
    }
    AddNewButton{}
}
