
import QtQuick.Controls 2.12

import App 1.0

import QtQuick 2.12
//import QtQml.StateMachine 2.12 as DSM
import QtQml.StateMachine 1.0 as DSM

import Qt5Compat.GraphicalEffects
//import QtGraphicalEffects 1.0

//import QtQuick.Layouts 2.12


Component {
    id: delegatRadioComponent

    Item {
        id: delegatRadioItem
        property var isCurrent: ListView.isCurrentItem
        property ListView view: ListView.view
        //        property var radio: controller.getRadio(link)

        Binding {
            target: nameId
            property: "text"
            value: name
        }
        Binding {
            target: linkId
            property: "text"
            value: link
        }

        property string iconPath:    applicationDirPath + "/radio_icons/" +  icon + ".jpg"
        property real  elemMargins5 : 3

        property real delegatRadioItemHeightVar1: 1.5
        property real delegatRadioItemHeightVar2: 0.7
        property real rectangleRadioContentRadius: 10
        property real rectangleRadioContentBorderWidth: 2
        property real imageIconWidth: 1.2
        property real nameIdVar1: 3
        property real nameIdVar2: 0.8


        width: delegatRadioWidth
        //        height: delegatRadioHeight
        //                height:  Math.pow((delegatRadioHeightGlobal*50), 0.5)
        height:   Math.pow(delegatRadioHeightGlobal/delegatRadioItemHeightVar1, delegatRadioItemHeightVar2)


        function changeRadio(){
            currentLink = link
            stop_buttonId.clicked();
            play_pause_buttonId.clicked();
            //            console.log("cur url:" + link)
        }

        function changeIndex()
        {
             console.log("changeIndex")
            if (currentListView != view)
            {
                //                console.log("currentListView != view " + currentListView  + "|" + view)

                if (currentListView != null)
                    currentListView.currentIndex  = -1

                currentListView = view
            }
            //            else  console.log("currentListView == view " + currentListView  + "|" + view)

            view.currentIndex = index
            if (currentLink !== link)
                changeRadio()
        }

        FileValidator {
            id: validator
            url: iconPath
            treatAsImage: true
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("click")
                changeIndex()
            }
        }

        Rectangle {
            id: rectangleRadioContent
            anchors.margins: elemMargins5/1.2
            anchors.leftMargin: elemMargins5*1.5
            anchors.rightMargin:  elemMargins5*1.5
            anchors.fill: parent
            radius: height / rectangleRadioContentRadius



            border {
                color: "black"
                width: rectangleRadioContentBorderWidth
            }

            Image {
                id: imageIcon;
                property bool rounded: true
                property bool adapt: true
                source: validator.fileValid ? validator.url :  iconPathStandart

                width: delegatRadioItem.height / imageIconWidth
                height: width
                anchors.verticalCenter: parent.verticalCenter
                x: elemMargins5/1.2

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

            Column {
                anchors.left: imageIcon.right
                width: rectangleRadioContent.width - imageIcon.width - elemMargins5*2
                anchors.verticalCenter:  parent.verticalCenter

                anchors.margins:  elemMargins5/1.2

                Flickable {
                    width: parent.width  -  imageIcon.x  - anchors.margins
                    height: nameId.height
                    contentWidth: nameId.width
                    contentHeight: nameId.height
                    clip: true

                    Rectangle{
                        width: rectangleRadioContent.width
                        height: nameId.height

                        Text {
                            id: nameId
                            text: name
                            font.bold: true
                            font.pointSize:  Math.pow(delegatRadioItem.height /nameIdVar1, nameIdVar2)

                            Component.onCompleted: {
                                console.log( "name = " +  name )
                            }
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("click Flickable1")
                                changeIndex()
                                console.log("click Flickable2")
                            }
                        }
                    }
                } // Flickable name

                Flickable {
                    width: parent.width  -  imageIcon.x  - anchors.margins
                    height: linkId.height
                    contentWidth: linkId.width
                    contentHeight: linkId.height
                    clip: true

                    Rectangle{
                        width: rectangleRadioContent.width
                        height: linkId.height
                        Text {
                            id: linkId
                            text: link
                            font.pointSize:  Math.pow(delegatRadioItem.height /(nameIdVar1*2), nameIdVar2)
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("click Flickable")
                                changeIndex()
                            }
                        }
                    }
                } // Flickable link
            } // Column
        }// Rectangle
    } // Item
}
