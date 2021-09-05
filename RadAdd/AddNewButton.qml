
import QtQuick.Controls
import Qt5Compat.GraphicalEffects
//import App 1.0
import Qt.labs.platform 1.1
//import QtGraphicalEffects 1.0
//import QtQuick.Controls.Material 2.12
import QtQuick
import App 1.0



// панель добавления
Rectangle {
    id: container
    property int  elemMargins5 : 5
    property int widthText: ( rectangleRadioContent.width  - elemMargins5*2 )

    property real  addNewButtonHeightVar1 : 7
    property real  addNewButtonHeightVar2 : 0.7
    property int maximumLengthName: 20

    property string addIcon:  "qrc:/app_icons/addIcon"


    //    color: "red"

    width: parent.width
    height:  Math.pow(delegatRadioHeightGlobal/5, 3/4)
    anchors.bottom: parent.bottom
    state: "start"

    border.width: 2
    radius: elemMargins5

    MouseArea {
        anchors.fill: parent
    }
    FileDialog {
        id: fileDialog
        nameFilters: [ "Image files (*.png *.jpg *.jpeg))", "All files (*)" ]
        //        selectedNameFilter: "All files (*)"
        title: "Please choose a file"
        onAccepted: {
            console.log("You chose: " +  file )
            var varPath =  file
            validator.url = file

            if ( validator.fileValid  )
            {
                imageIcon.source = varPath ;
                //                newIconExist = true
                console.log("valid image ")
            } else    console.log("not +++  image ")
        }
        onRejected: {
            console.log("Canceled")
        }
    }
    FileValidator {
        id: validator
        url: iconPathStandart
        treatAsImage: true
    }



    Button {
        id: buttonAdd

        anchors.horizontalCenter: parent.horizontalCenter
        height:  Math.pow(delegatRadioHeightGlobal/5, 3/4)
        anchors.top: parent.top

        font.pixelSize: height/2
        highlighted: true
        Material.foreground: "black"
        Material.accent: "lightgreen"
        icon.source: "qrc:/app_icons/plus2.svg"
        TapHandler {
            onTapped:  {
                console.log( "click " ) ;
                container.state == 'start' ? container.state = 'addNew' : container.state = 'start'
            }
        }
    }

    Rectangle { // input layout
        color: "yellow"
        id: recInputLayout

        anchors.top: buttonAdd.bottom
        anchors.bottom: parent.bottom
        anchors.margins: elemMargins5
        width: parent.width-20
        anchors.horizontalCenter:  parent.horizontalCenter
        visible: false

        Rectangle {
            id: rectangleRadioContent

            clip: true
            width:  parent.width
            height: columnId.height + elemMargins5*2
            radius: elemMargins5*2
            border.width: 2

            Column {
                id: columnId
                anchors.left:  parent.left
                spacing: elemMargins5
                anchors.margins: elemMargins5

                Column {
                    Label { //name
                        id: labelName

                        anchors.margins: 30
                        text: "Name:"
                        font.pixelSize:    Math.pow( recInputLayout.height/1.5  , 1/2)
                    }
                    ScrollView  {
                        width: nameId.width
                        TextField {
                            id: nameId
                            width:  widthText
                            font.pixelSize:    Math.pow( recInputLayout.height  , 1/2)
                            placeholderText: qsTr("Enter name")
                            onFocusChanged:{
                                if(focus)
                                    selectAll()
                            }
                            TapHandler {
                                grabPermissions: PointerHandler.TakeOverForbidden
                                onDoubleTapped:   nameId.selectAll()
                            }
                            validator: RegularExpressionValidator { regularExpression: /^([a-zA-Z0-9а-яА-я]+ )*[a-zA-Z0-9а-яА-я]+$/ }
                            maximumLength: maximumLengthName
                        }
                        //                        TextMetrics {
                        //                            id:     t_metricsNameId
                        //                            font:   nameId.font
                        //                            text:   "a"
                        //                        }
                    }

                    Flickable {
                        width: rectangleRadioContent.width
                        height: t_metrics.height * 2
                        clip: true

                        contentWidth: labelNameWarning.width
                        contentHeight: labelNameWarning.height

                        TextMetrics {
                            id:     t_metrics
                            font:   labelNameWarning.font
                            text:   labelNameWarning.text
                        }
                        Label { //name warning
                            id: labelNameWarning
                            font.pixelSize:    Math.pow( recInputLayout.height/3  , 1/2)
                            width: widthText
                            text: ""
                            color: "red"
                            wrapMode: Text.Wrap
                        }
                    }
                }

                Column {
                    spacing: 0
                    Label { //link
                        id: lableLink
                        text: "Url:"
                        font.pixelSize:    Math.pow( recInputLayout.height/1.5  , 1/2)
                    }
                    TextField {
                        id: linkId
                        width:  widthText
                        placeholderText: qsTr("Enter url")
                        verticalAlignment:  TextInput.AlignTop
                        //                            font.pointSize:  Math.pow( recInputLayout.height/25, 2)
                        font.pixelSize:    Math.pow( recInputLayout.height  , 1/2)
                        onFocusChanged:{
                            if(focus)
                                selectAll()
                        }
                        TapHandler {
                            grabPermissions: PointerHandler.TakeOverForbidden
                            onDoubleTapped:   linkId.selectAll()
                        }
                        maximumLength: 8192
                    }
                    //                    TextMetrics {
                    //                        id:     t_metricsLink
                    //                        font:   linkId.font
                    //                        text:   linkId.text
                    //                    }
                    Flickable {
                        width: rectangleRadioContent.width
                        height: t_metricsLabelLinkWarning.height * 2
                        clip: true
                        contentWidth: labelNameWarning.width
                        contentHeight: labelNameWarning.height
                        TextMetrics {
                            id:     t_metricsLabelLinkWarning
                            font:   labelLinkWarning.font
                            text:   labelLinkWarning.text
                        }
                        Label { //link warning
                            id: labelLinkWarning
                            width: widthText
                            font.pixelSize:    Math.pow( recInputLayout.height/3  , 1/2)
                            text: ""
                            color: "red"
                            wrapMode: Text.Wrap
                        }
                    }
                }
                Column {
                    Rectangle {
                        width: lableImage.width + imageIcon.width
                        height: imageIcon.height
                        Label { //image
                            id: lableImage
                            text: "Image:"
                            font.pixelSize:    Math.pow( recInputLayout.height/1.5  , 1/2)
                        }

                        Image {
                            id: imageIcon
                            source: iconPathStandart
                            property bool rounded: true
                            property bool adapt: true
                            anchors.left: lableImage.right

                            //                height: parent.height * 0.5 + parent.width/10
                            height:  Math.pow( (container.height + container.width/10)/2 , 3/4)
                            width:  height

                            anchors.margins: elemMargins5
                            //                    anchors.left: parent.left
                            //                    anchors.verticalCenter: parent.verticalCenter

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
                            MouseArea {
                                id: mouseArea
                                anchors.fill: parent
                                onClicked: {
                                    fileDialog.open()
                                }
                                hoverEnabled: true
                                onHoveredChanged:
                                {
                                    if (containsMouse)
                                    {
                                        addVisable.visible = true
                                    }
                                    else
                                    {
                                        addVisable.visible = false
                                    }
                                }
                            }
                        } // Image

                        Image {
                            id: addVisable
                            source:   addIcon
                            visible: false
                            width: imageIcon.width
                            height:  width
                            anchors.verticalCenter: imageIcon.verticalCenter
                            anchors.horizontalCenter: imageIcon.horizontalCenter

                            layer.enabled: rounded
                            layer.effect: OpacityMask {
                                maskSource: Item {
                                    width: addIcon.width * 1.1
                                    height: addIcon.height * 1.1
                                    Rectangle {
                                        anchors.centerIn: parent
                                        width: addIcon.adapt ? addIcon.width : Math.min(addIcon.width, addIcon.height)
                                        height: addIcon.adapt ? addIcon.height : width
                                        radius: Math.min(width, height)
                                    }
                                }
                            }

                        } // image
                    } // Rectangle
                    Flickable {
                        width: rectangleRadioContent.width
                        height: t_metricsLabelImageWarning.height * 2
                        clip: true
                        contentWidth: labelNameWarning.width
                        contentHeight: labelNameWarning.height
                        TextMetrics {
                            id:     t_metricsLabelImageWarning
                            font:   labelImageWarning.font
                            text:   labelImageWarning.text
                        }
                        Label { //link warning
                            id: labelImageWarning
                            width: widthText
                            font.pixelSize:    Math.pow( recInputLayout.height/3  , 1/2)
                            text: ""
                            color: "red"
                            wrapMode: Text.Wrap
                        }
                    }
                } // COlum
            } // Column
        }// Rectangle



        Rectangle {
            color: "red"
            anchors.top: rectangleRadioContent.bottom
            anchors.bottom: buttonAddMy.top
            anchors.left: parent.left
            anchors.right: parent.right
//            height: 100

            Label {
                id: informationId
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

            }
        }

        Button {
            id: buttonAddMy

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            height:  Math.pow(delegatRadioHeightGlobal/5, 3/4)
            highlighted: true
            Material.foreground: "black"
            Material.accent:  "lightgreen"
            icon.source: "qrc:/app_icons/plus2.svg"

            onClicked:  {
//                controller.addMyRadio( linkId.text, nameId.text,  "asd")
                controller.checkRadio( linkId.text, nameId.text,  "asd")
            }
        }
    }  // input layout

    states: [
        State {
            name: "start"
        },
        State {
            name: "addNew"
            PropertyChanges {
                target: buttonAdd
                Material.accent: "lightcoral"
                icon.source: "qrc:/app_icons/down-arrow.svg"
            }
            PropertyChanges {
                target: container
                height: parent.height
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

