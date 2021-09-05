import QtQuick 2.12
import QtQuick.Controls 2.12
import Qt5Compat.GraphicalEffects
//import QtGraphicalEffects 1.0


import App 1.0

Item {
    property var elemMargins5: 5
    property var elemMargins: 5

    property Image  imageIconId: imageIcon
    property Label textForNameId: textForName
    property Label textForUrlId: textForUrl

    Rectangle {
        anchors.margins: elemMargins5
        anchors.fill: parent
        radius: height / 10

        border {
            color: "black"
            width: 2
        }

        Image {
            id: imageIcon;
            property bool rounded: true
            property bool adapt: true
//            source: validator.fileValid ? validator.url :  iconPathStandart

            width: delegatRadioHeight / 1.1
            height: width
            anchors.margins: elemMargins5
//                anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter

            layer.enabled: rounded
            layer.effect: OpacityMask {
                maskSource: Item {
                    width: imageIcon.width * 1.1
                    height: imageIcon.height * 1.1
                    Rectangle {
                        anchors.centerIn: parent
                        width: imageIcon.adapt ? imageIcon.width : Math.min(imageIcon.width, imageIcon.height)
                        height: imageIcon.adapt ? imageIcon.height : width
                        radius: Math.min(width, height)
                    }
                }
            }
        } // Image


        ScrollView {
            anchors.top: parent.top
            anchors.left: imageIcon.right
            anchors.right: parent.right
            anchors.margins:  elemMargins
            clip: true
            Label {
                id: textForName
            }
        }// ScrollView

        ScrollView  {
            anchors.bottom:  parent.bottom
            anchors.left: imageIcon.right
            anchors.right: parent.right
            anchors.margins:  elemMargins
            clip: true
            Label {
                id: textForUrl
            }
        }// ScrollView

    }
}
