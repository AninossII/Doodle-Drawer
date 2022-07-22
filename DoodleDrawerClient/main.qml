import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("DoodleDrawer")

    Loader{
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/ui/MainMenuScreen.qml"
    }

}
