import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Window {
    id: selectAvatar
    width: 350
    height: 260
    visible: false

    ColumnLayout {
        anchors.fill: parent
        Layout.margins: 15
        Layout.alignment: Qt.AlignCenter

        RowLayout {
            Layout.fillWidth: true
            spacing: 20
            Rectangle {
                width: 100
                height: 100
                Image {
                    id: img1
                    source: ""
                    anchors.fill: parent
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        onClicked: {
                            personalHead = img1.source
                            selectAvatar.visible = false
                        }
                    }
                }
            }
            Rectangle {
                width: 100
                height: 100
                Image {
                    id: img2
                    source: ""
                    anchors.fill: parent
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        onClicked: {
                            personalHead = img2.source
                            selectAvatar.visible = false
                        }
                    }
                }
            }
            Rectangle {
                width: 100
                height: 100
                Image {
                    id: img3
                    source: ""
                    anchors.fill: parent
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        onClicked: {
                            personalHead = img3.source
                            selectAvatar.visible = false
                        }
                    }
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: 20
            Rectangle {
                width: 100
                height: 100
                Image {
                    id: img4
                    source: ""
                    anchors.fill: parent
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        onClicked: {
                            personalHead = img4.source
                            selectAvatar.visible = false
                        }
                    }
                }
            }
            Rectangle {
                width: 100
                height: 100
                Image {
                    id: img5
                    source: ""
                    anchors.fill: parent
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        onClicked: {
                            personalHead = img5.source
                            selectAvatar.visible = false
                        }
                    }
                }
            }
            Rectangle {
                width: 100
                height: 100
                Image {
                    id: img6
                    source: ""
                    anchors.fill: parent
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        onClicked: {
                            personalHead = img6.source
                            selectAvatar.visible = false
                        }
                    }
                }
            }
        }
    }
}
