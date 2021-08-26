//import QtQuick


import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQml.Models
import QtQml.StateMachine as DSM

//import QtQml.StateMachine 1.15 as DSM


ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Radadd")

    property var delegatRadioWidth: width  // ширина приложения
    property var delegatRadioHeight: 100  // высота 1 радио в листе
    property var iconPathStandart:  "qrc:/app_icons/standartRadio"  // стандартная иконка
    property var freeSignal: true // блокировка добавления/удаления из любимых в c++
//    property list<Switch> currentFavoriteSwitchList // лист switch для выкючения/включения
    property ListView currentListView // текущий лист
    property var currentModel // текущяя модель
    property var currentLink // текущяее радио
//    property ListView constFavoriteListView // для сравнения с listFavorite

    property Button play_pause_buttonId: play_pause_button  //кнопка плей/пауза глобальня
    property Button stop_buttonId: stop_button  //кнопка стоп глобальня



    Connections {
        target: bassController
//        function onSendToQmlCurrSong(currSong) {
//            textForUrl.text = currSong;
//        }
    }

//    Connections {
//        target: controller
//        function onSentToQml() {
//            console.log("onSentToQml")
//            freeSignal = true;
//            for (var i=0; i<currentFavoriteSwitchList.length; i++)
//            {
//                currentFavoriteSwitchList[i].enabled = true
//                 console.log(" | " + currentFavoriteSwitchList )
//            } currentFavoriteSwitchList = [];
//        }
//    } // Connections


    Connections {
        target: controller
        function onSentToQml() {
            console.log("onSentToQml")
            freeSignal = true;
//            favoriteSwitch.enabled = true
        }
    } // Connections


//    Component.onCompleted:
//    {
//        let map = new Map();

//        map.set(1, 'str1');   // ключ-строка
//        map.set(1, 'num1');     // число


//        console.log(map.get(1) + " +++++++++++++++++++++++" );
//        console.log(map.size + " +++++++++++++++++++++++" );
//    }


    property string testF:  "F" + "link4"



//    Component.onCompleted: console.log("++++++++++++++++ " +  (Flink4.favorite))


    DSM.StateMachine {  // управление плеером
        id: stateMachine
        initialState: stopState
        running: true

        DSM.State {
            id: stopState
            DSM.SignalTransition {
                targetState: playState
                signal: play_pause_button.clicked
            }
            onEntered: {
                play_pause_button.icon.source =  "qrc:/app_icons/play.svg"
                bassController.stop();
                console.log("stopState")
            }
        }
        DSM.State {
            id: playState
            DSM.SignalTransition {
                targetState: pauseState
                signal:  play_pause_button.clicked
            }
            DSM.SignalTransition {
                targetState: stopState
                signal: stop_button.clicked
            }
            onEntered: {
                bassController.play(currentLink);
                console.log("playState")
                play_pause_button.icon.source =   "qrc:/app_icons/pause.svg"
            }
        }

        DSM.State {
            id: pauseState
            DSM.SignalTransition {
                targetState: playState
                signal:   play_pause_button.clicked
            }
            DSM.SignalTransition {
                targetState: stopState
                signal: stop_button.clicked
            }
            onEntered: {
                bassController.pasue();
                console.log("pauseState")
                play_pause_button.icon.source =  "qrc:/app_icons/play.svg"
            }
        }
    }


    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        My{
        }
        Favorite{
        }
        Stations {
        }
    }
    header: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("My")
        }
        TabButton {
            text: qsTr("Favorite")
        }
        TabButton {
            text: qsTr("Stations")
        }
    }


    footer:
        Rectangle {
        visible: false
        //           color: "green"
        height: delegatRadioHeight + 30

        Rectangle {
            anchors.top: parent.top
            height: 30
            width: parent.width
            color: "pink"

        Rectangle {
            id: rectangleButtonPanel
            width: parent.width
            height: delegatRadioHeight
            anchors.bottom: parent.bottom

            LayoutForButton {
                id: layoutForButton
                height: delegatRadioHeight
                width:   (play_pause_button.width )*3 + marginsButton*5
                anchors.left:  radioIconDele.right

                property var marginsButton: 5

                Button {
                    id: play_pause_button
                    width: delegatRadioHeight - 10
                    height: width
                    anchors.left: parent.left
                    anchors.margins: 5
                    anchors.verticalCenter: parent.verticalCenter
                    background: Rectangle {
                        border.width: 1
                        radius: height / 10
                    }
                }
                Button {
                    id: stop_button
                    width: delegatRadioHeight - 10
                    height: width
                    anchors.left: play_pause_button.right
                    anchors.margins: 5
                    anchors.verticalCenter:  parent.verticalCenter
                    background: Rectangle {
                        border.width: 1
                        radius: height / 10
                    }
                    icon.source: "qrc:/app_icons/stop.svg"
                }
                Button {
                    id: stopPause2
                    width: delegatRadioHeight - 10
                    height: width
                    anchors.left: stop_button.right
                    text: "asd"
                    anchors.margins: 5
                    anchors.verticalCenter:  parent.verticalCenter
                    background: Rectangle {
                        border.width: 1
                        radius: height / 10
                    }
                }

            }
        }
        }
    }//  footer: Rectangle

}



//DelegateModel {
//    id: visualModel
//    model:  radio
//    delegate: Rectangle {
//        color: "red"
//        height: 25
//        width: 100


//        ListView {
//             width: 500
//             height: 500

//            model: genre
//            orientation: ListView.Horizontal
//            delegate:   Column   {
//                Rectangle{
//                  border.color: "darkblue"
//                  border.width: 1
//                  radius: 5
//                    color: "deepskyblue";
//                    width:  textId.width * 1.2
//                    height: textId.height * 1.2
//                    Text {
//                        anchors.centerIn: parent
//                        id: textId
//                        text: genre[index]
//                    }
//                }
//            }
//        }
//    }
//}
