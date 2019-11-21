import QtQuick 2.0
import QtWebKit 3.0
import QtWebKit.experimental 1.0
import com.syberos.basewidgets 2.0
import com.syberos.filemanager.filepicker 1.0

CPageStackWindow {
    id: rootWindow

    initialPage:CPage{
        id:mainPageView
        width:parent.width
        height:parent.height

        Connections{
            target: syberH5Helper
            onResultStr:{

                listModel.append({"logStr": str})

                console.log(" ----- str: ", str)
            }
        }

        contentAreaItem: Item {
            id: itemHandel

            anchors.fill: parent

            property int itemHeight: 100
            property int fontSize: 30

            Column {
                id: columnRoot
                width: parent.width

                Item {
                    id: sendDataLengthItem
                    width: parent.width
                    height: itemHandel.itemHeight

                    function getDataLength() {
                        var temp = selectSendDataText.text

                        return temp
                    }

                    Text {
                        id: sendDataLengthText
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        font.pixelSize: itemHandel.fontSize
                        text: qsTr("循环数量:")
                    }

                    TextEdit {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: sendDataLengthText.right
                        anchors.leftMargin: 15

                        width: 750
                        height : 100
                        verticalAlignment: TextEdit.AlignVCenter

                        text: "40"
                        font.pixelSize: itemHandel.fontSize

                        onTextChanged: {
                            syberH5Helper.setFib2Number(text);

                        }
                    }

                    Rectangle {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        height:1
                        color: "#000000"
                    }
                }


                Item {
                    id: sendTimesItem
                    width: parent.width
                    height: itemHandel.itemHeight

                    Text {
                        id: sendTimesText
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        font.pixelSize: itemHandel.fontSize
                        text: qsTr("运行几次:")
                    }

                    TextEdit {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: sendTimesText.right
                        anchors.leftMargin: 15

                        width: 750
                        height : 100
                        verticalAlignment: TextEdit.AlignVCenter

                        text: "5"
                        font.pixelSize: itemHandel.fontSize

                        onTextChanged: {
                            syberH5Helper.setRunNumber(text);
                        }
                    }

                    Rectangle {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        height:1
                        color: "#000000"
                    }


                    Rectangle {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        height:1
                        color: "#000000"
                    }
                }

                Item {
                    id: sendNumberItem
                    width: parent.width
                    height: itemHandel.itemHeight

                    Text {
                        id: numberText
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        font.pixelSize: itemHandel.fontSize
                        text: qsTr("数组循环数量:")
                    }

                    TextEdit {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: numberText.right
                        anchors.leftMargin: 15

                        width: 750
                        height : 100
                        verticalAlignment: TextEdit.AlignVCenter

                        text: "10000000"
                        font.pixelSize: itemHandel.fontSize

                        onTextChanged: {
                            syberH5Helper.setArrNumber(text);

                        }
                    }

                    Rectangle {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        height:1
                        color: "#000000"
                    }
                }

                Item {
                    width: parent.width
                    height: itemHandel.itemHeight

                    Rectangle {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 80

                        width: 250
                        height : 80

                        color: "lightblue";
                        radius: 10

                        Text {
                            anchors.centerIn: parent
                            font.pixelSize: itemHandel.fontSize
                            text: qsTr("斐波那契数列")
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                syberH5Helper.fib2Start();
                            }
                        }
                    }

                    Rectangle {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.right: parent.right
                        anchors.rightMargin: 80

                        width: 200
                        height : 80

                        color: "lightblue";
                        radius: 10

                        Text {
                            anchors.centerIn: parent
                            font.pixelSize: itemHandel.fontSize
                            text: qsTr("创建数组")
                        }

                        MouseArea {
                            anchors.fill: parent

                            onClicked: {
                                syberH5Helper.newArrStart()
                            }
                        }
                    }

                    Rectangle {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        height:1
                        color: "#000000"
                    }
                }
            }

            ListView {
                id: listView
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: columnRoot.bottom
                anchors.bottom: parent.bottom

                model: listModel
                clip: true
                delegate: Text {
                    font.pixelSize: itemHandel.fontSize
                    text: logStr
                }

                onCountChanged: {
                    positionViewAtEnd()
                }
            }

            ListModel {
                id: listModel
            }
        }

        Component.onCompleted: {
        }
    }
}
