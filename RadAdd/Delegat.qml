import QtQuick 2.0
import QtQuick.Controls 2.12

import App 1.0

import QtQuick
import QtQml.StateMachine as DSM
import Qt5Compat.GraphicalEffects
import QtQuick.Layouts


Component {
    id: delegatRadioComponent

    Item {
        id: delegatRadioItem
        property var isCurrent: ListView.isCurrentItem
        property ListView view: ListView.view 
        property var radio: controller.getRadio(link)

        Binding {
            target: favoriteSwitch
            property: "checked"
            value: radio.favorite
        }
        Binding {
            target: nameId
            property: "text"
            value: radio.name
        }
        Binding {
            target: linkId
            property: "text"
            value: radio.link
        }
        Binding {
            target: genreId
            property: "text"
            value: radio.genre+""
        }

        property var iconPath:    applicationDirPath + "/radio_icons/" +  icon + ".jpg"
        property var  elemMargins5 : 5

        width: delegatRadioWidth
        height: delegatRadioHeight

        function changeRadio(){
            currentLink = link
            stop_buttonId.clicked();
            play_pause_buttonId.clicked();
            //            console.log("cur url:" + link)
        }

        function changeIndex()
        {
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
                source: validator.fileValid ? validator.url :  iconPathStandart

                //                Component.onCompleted:
                //                {
                //                    console.log("Completed Running!")
                //                    console.log("validator.url       | "  + validator.url )
                //                    console.log("iconPathStandart    | "  + iconPathStandart )
                //                    console.log("itog finaly         | "  + imageIcon.source )
                //                }

                width: delegatRadioHeight / 1.1
                height: width
                anchors.margins: elemMargins5
                anchors.left: parent.left
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

            Column {
                anchors.left: imageIcon.right
                anchors.right: favoriteSwitch.left
                anchors.verticalCenter:  parent.verticalCenter

                Flickable {
                    width: parent.width
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
                            font.pointSize:  13
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("click Flickable")
                                changeIndex()
                            }
                        }
                    }
                } // Flickable name

                Flickable {
                    width: parent.width
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

                Flickable {
                    width: parent.width
                    height: genreId.height
                    contentWidth: genreId.width
                    contentHeight: genreId.height
                    clip: true

                    Rectangle{
                        width: rectangleRadioContent.width
                        height: genreId.height
                        Text {
                            id: genreId
                            text: genre + ""
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("click Flickable")
                                changeIndex()
                            }
                        }
                    }
                } // Flickable genre

                Flickable {
                    width: parent.width
                    height: listeningId.height
                    contentWidth: listeningId.width
                    contentHeight: listeningId.height
                    clip: true

                    Rectangle{
                        width: rectangleRadioContent.width
                        height: listeningId.height
                        Text {
                            id: listeningId
                            text: listening
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                console.log("click Flickable")
                                changeIndex()
                            }
                        }
                    }
                } // Flickable listening
            } // Column

            Switch {
                id: favoriteSwitch
                anchors.right: parent.right
                anchors.verticalCenter:   parent.verticalCenter
                anchors.margins: elemMargins5
                property bool loaded: false
                Component.onCompleted: loaded = true

                onCheckedChanged: { if (loaded) {
//                        enabled = false
                        if (freeSignal){
                            freeSignal = false
                            if (checked)
                            {
                                console.log("checked")
                                controller.addToFavoite(link) // adding to the list "favorite"
                            }
                            else
                            {
                                console.log("no checked")
                                controller.removeFromFavorite(link) // removal from the list "favorite"
                            }
                        } //   if (freeSignal)
                    } //  if (loaded)
                }
            }// Switch
        }// Rectangle
    } // Item
}
