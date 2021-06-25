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


        property var iconPathStandart:  "qrc:/app_icons/standartRadio.png"
        property var  elemMargins : 5

        width: delegatRadioWidth
        height: delegatRadioHeight

        MouseArea {
            anchors.fill: parent
            onClicked: {
                view.currentIndex = index
                console.log("click")
            }
        }


        Rectangle {
            id: rectangleRadioContent
            anchors.margins: elemMargins
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
                Component.onCompleted:
                {
                    console.log("Completed Running!")
                    console.log("validator.url | "  + validator.url )
                    console.log("iconPathStandart | "  + iconPathStandart )
                    console.log("itog finaly | "  + imageIcon.source )
                }

                width: delegatRadioHeight / 1.1
                height: width
                anchors.margins: elemMargins
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
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                view.currentIndex = index
                                console.log("click Flickable")
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
                                view.currentIndex = index
                                console.log("click Flickable")
                            }
                        }
                    }
                } // Flickable name

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
                                view.currentIndex = index
                                console.log("click Flickable")
                            }
                        }
                    }
                } // Flickable genre


            }




            //            Column {
            //                anchors.left: imageIcon.right
            //                anchors.right: favoriteSwitch.left
            //                anchors.verticalCenter:  parent.verticalCenter
            //                clip: true

            //                spacing: 5
            //                Flickable {
            //                    id: scrollName

            //                    Rectangle{
            //                         width: 100
            //                         height: 10
            //                         color: "red"
            //                    }
            //                }
            //            }
            //            }// ScrollView



            //            Column {
            //                anchors.left: imageIcon.right
            //                anchors.right: favoriteSwitch.left
            //                anchors.verticalCenter:  parent.verticalCenter
            //                clip: true

            //                spacing: 5
            //                ScrollView {
            //                    id: scrollName
            //                    width: parent.width


            //                        Text {

            //                            id: nameId
            //                            text: name + "aaaaaaaaaaaaaaaasdas asssssssssssd"

            //                        }
            //                }

            //                ScrollView {
            //                    Text {
            //                        id: linkId
            //                        text: link
            //                        MouseArea {
            //                            anchors.fill: parent
            //                            onClicked: {
            //                                view.currentIndex = index
            //                                console.log("click")
            //                            }
            //                        }
            //                    }
            //                }

            //                ScrollView {
            //                    Text {
            //                        id: genreId
            //                        text: ""+genre
            //                        MouseArea {
            //                            anchors.fill: parent
            //                            onClicked: {
            //                                view.currentIndex = index
            //                                console.log("click")
            //                            }
            //                        }
            //                    }
            //                }
            //            }
            //            //            }// ScrollView


            Switch {
                id: favoriteSwitch
                anchors.right: parent.right
                anchors.verticalCenter:   parent.verticalCenter
                anchors.margins: elemMargins
                text: "text"

                icon.source:  iconPathStandart

                checked:  favorite
                property bool loaded: false
                Component.onCompleted: loaded = true

                onCheckedChanged: { if (loaded) {
                        console.log( checked )
                        enabled = false
                        currentFavoriteSwitchList.push(favoriteSwitch)

                        if (freeSignal) // посылается только один сигнал, блокировка
                        {
                            freeSignal = false; // блокировка
                            if (checked){ // посылается один сигнал
                                CollectionController.addToFavoite(model.modelData) // добавить в список любимых
                            } else {

                                if (currentListView ===  constFavoriteListView)
                                {
                                    if (currentUrl  === url )
                                        currentListView.currentIndex = -1;
                                }
                                if (view.model ===  radioListFavorite) // если удаляется в списке любимых
                                    CollectionController.removeFromFavoriteByIndex(index)
                                else if  (view.model ===  radioListMyRadio) // удаление в списке custom radio
                                    CollectionController.removeFromMyRadioByIndex(index)
                                else // если удаляется в любом списке
                                    CollectionController.removeFromFavorite(model.modelData)
                            }
                        }// freeSignal
                    }// if (loaded)
                }// onCheckedChanged
            }// Switch
        }// Rectangle

    } // Item
}
