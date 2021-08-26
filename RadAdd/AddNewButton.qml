import QtQuick
import QtQuick.Controls


import QtQuick.Layouts 1.15
import Qt5Compat.GraphicalEffects
import App 1.0

import Qt.labs.platform 1.1


// панель добавления
Rectangle {
    property int  elemMargins5 : 5
    property int widthText: rectangleRadioContent.width - imageIcon.width - favoriteSwitch.width - elemMargins5*2

    id: container
    width: parent.width
    height: 50
    anchors.bottom: parent.bottom
    state: "start"

    Button {
        id: buttonAdd
        width: 50
        height: 50
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

        background: Rectangle {
            id: recBack
            border {
                color: "black"
                width: 2
            }
            radius: 10
            color: "#4000ff00"
        }

        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            id: iconOpenClose
            text: "<b>+</b>"
            font.pixelSize: 16
        }

        TapHandler {
            onTapped:  {
                console.log( "click " ) ;
                container.state === 'start' ? container.state = 'addNew' : container.state = 'start'
            controller.prepearGenre()
            }
        }
    }

    Rectangle { // input layout
        //        color: "red"
        id: recInputLayout

        anchors.top: buttonAdd.bottom
        anchors.bottom: parent.bottom
        anchors.margins: elemMargins5
        width: parent.width - 20
        anchors.horizontalCenter:  parent.horizontalCenter



        Rectangle {
            id: rectangleRadioContent
            anchors.margins: elemMargins5
            width:  delegatRadioWidth - 20
            height: delegatRadioHeight*1.3
            radius: height / 10

            border {
                color: "black"
                width: 2
            }

            Image {
                id: imageIcon
                source: iconPathStandart
                property bool rounded: true
                property bool adapt: true

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
                    width: nameId.width
                    height: nameId.height
                    clip: true
                    //                    Component.onCompleted:
                    //                    {
                    //                        var globalCoordinares = nameId.mapToItem(rectangleRadioContent, 0, 0)
                    //                          console.log("X: " + (globalCoordinares.x + nameId.width   ) +  " y: " + globalCoordinares.y)
                    //                          globalCoordinares = favoriteSwitch.mapToItem(rectangleRadioContent, 0, 0)
                    //                          console.log("X: " + globalCoordinares.x  +  " y: " + globalCoordinares.y)
                    //                    }
                    Rectangle{
                        //                            height: nameId.height
                        TextField {
                            id: nameId
                            width:  widthText
                            font {
                                bold: true
                                pointSize: 13
                            }
                            horizontalAlignment: TextInput.AlignLeft
                            Layout.fillWidth: true
                            placeholderText: qsTr("Enter name")
                            onFocusChanged:{
                                if(focus)
                                    selectAll()
                            }
                            TapHandler {
                                grabPermissions: PointerHandler.TakeOverForbidden
                                onDoubleTapped:   nameId.selectAll()
                            }
                        }
                    }
                } // Flickable name

                Flickable {
                    width: linkId.width
                    height: linkId.height
                    clip: true

                    Rectangle{
                        TextField {
                            id: linkId
                            horizontalAlignment: TextInput.AlignLeft
                            Layout.fillWidth: true
                            width:  widthText
                            placeholderText: qsTr("Enter url")
                            font {
                                pointSize: 10
                            }
                            onFocusChanged:{
                                if(focus)
                                    selectAll()
                            }
                            TapHandler {
                                grabPermissions: PointerHandler.TakeOverForbidden
                                onDoubleTapped:   nameId.selectAll()
                            }
                        }
                    }
                } // Flickable link

                Rectangle {
                    width: parent.width
                    height: 50
                    color: "green"
                }

                //                                    Flickable {
                //                                        width: genreId.width
                //                                        height: genreId.height
                //                                        clip: true

                //                                        Rectangle{
                //                                            TextField {
                //                                                id: genreId
                //                                                horizontalAlignment: TextInput.AlignLeft
                //                                                Layout.fillWidth: true
                //                                                width:  widthText
                //                                                placeholderText: qsTr("Enter awdawdawdawd")
                //                                                font {
                //                                                          pointSize: 10
                //                                                      }
                //                                                onFocusChanged:{
                //                                                    if(focus)
                //                                                        selectAll()
                //                                                }
                //                                                TapHandler {
                //                                                    grabPermissions: PointerHandler.TakeOverForbidden
                //                                                    onDoubleTapped:   nameId.selectAll()
                //                                                }
                //                                            }
                //                                        }
                //                                    } // Flickable genre

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


        Rectangle {
            id: genreToAdd
            width: 500
            height: 200
            anchors.top: rectangleRadioContent.bottom
            color: "#999900"

            property  variant array: [1, 2, 3, 4, 5, 6]

//            Component.onCompleted: {
////               array = controller.getGenreToAdd()
//                console.log("aaray size "  + controller.getGenreToAdd() )
//            }

//            ListView{
////                model:  controller.getGenreToAdd()
//                model: genreToAdd.array

//                delegate: Rectangle{
//                    width: 100
//                    height: 100
//                    Text {
//                        width: 100
//                        height: 20
//                        id: name
//                        text:  "asd" +   modelData
//                        font.pointSize: 30 + index*5
//                        MouseArea {
//                            anchors.fill: parent
//                            onClicked: console.log("modelData")
//                        }
//                    }
//                }
//            }
            Item {
                id: root
                property variant colors: ["red", "white", "blue"]

                Component.onCompleted: {
                colors = controller.getGenreToAdd()  
                }

                width: 640; height: 480

                ListView {
                    id: _listView
                    anchors.fill: parent

                    model: root.colors
                    delegate: Rectangle {
                        id: _rectangleDelegate
                        width: 20
                        height: 20
                        Text {
                            id: name
                            text: model.modelData
                        }
                    }
                }
            }
        }

        Rectangle {
            id: genreAll
            width: 500
            height: 200
            anchors.top: genreToAdd.bottom
            color: "red"
            ListView{
                model: controller.genreAll
                clip: true
                delegate: Rectangle {
                    width: 100
                    height: 20
                    Text {
                        text: "modelData"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: console.log("modelData" + index)
                        }
                    }
                }
            }
        }


        Button {
            id: buttonAddMy
            width:buttonAdd.width
            height: buttonAdd.height
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            onClicked:  { console.log("test asdasdasdasd")
                controller.testPop();
            }

            background: Rectangle {
                border {
                    color: "black"
                    width: 2
                }
                radius: 10
                color: "#4000ff00"
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: "<b>+</b>"
                font.pixelSize: 16
            }
        }
    }

    border {
        color: "black"
        width: 2
    }
    radius: 10

    states: [
        State {
            name: "start"
            PropertyChanges {
                target: radioListMyRadio
                visible: true
            }
            PropertyChanges {
                target: recInputLayout
                visible: false
            }
        },
        State {
            name: "addNew"
            PropertyChanges {
                target: buttonAdd
                width: parent.width / 2
            }
            PropertyChanges {
                target: recBack
                color: "#40ff0000"
            }

            PropertyChanges {
                target: iconOpenClose
                text:  "<b>↓</b>"
            }

            PropertyChanges {
                target: container
                height: parent.height
            }
            PropertyChanges{
                target: rectangleRadioContent
                width: recInputLayout.width
            }

            PropertyChanges {
                target: radioListMyRadio
                visible: false
            }
            PropertyChanges {
                target: recInputLayout
                visible: true
            }
        }
    ]

    transitions: [
        Transition {
            NumberAnimation { properties: "height, width, visible" }
        }
    ]

}

