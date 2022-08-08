import QtQuick 2.0
import QtQuick.Controls 2.15

Item {
    id: mainMenuScreen

    Rectangle{
        id: background
        anchors.fill: parent
        color: "#23001E"
    }

    GameTitle{
        id: titleText
        textTitle: "Doodle Drawer"
    }
    
    GameButton{
        id: playButton
        anchors.centerIn: parent
        buttonText: "Play"
        width: 336
        height: 105
        onButtonClicked: mainLoader.source = "GameSelectScreen.qml"
    } 

    GameButton{
        id: quitButton
        anchors{
            top: playButton.bottom
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }

        buttonText: "Quit"
        width: 336
        height: 105
        onButtonClicked: Qt.quit()
    }
}
