import QtQuick 2.0

Item {
    id: gameSelectScreen

    Rectangle{
        id: background
        anchors.fill: parent
        color: "#23001E"
    }

    Text{
        id: titleText
        font.pixelSize: 72
        font.bold: true
        font.family: "ROBOTO"
        anchors{
            top: parent.top
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }
        color: "white"
        text: "Doodle Drawer"
    }

    GameButton{
        id: createGameButton
        anchors.centerIn: parent
        buttonText: "Create Game"
        buttonTextPixelSize: 48
        width: 336
        height: 105  
        onButtonClicked: gameManager.createGameRequest()
    }

    GameButton{
        id: joinGameButton
        anchors{
            top: createGameButton.bottom
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }
        buttonText: "Join Game"
        buttonTextPixelSize: 48
        width: 336
        height: 105
        onButtonClicked: console.log("Button Clicked!")
    }

    GameButton{
        id: backButton
        anchors{
            top: joinGameButton.bottom
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }
        buttonText: "Back"
        buttonTextPixelSize: 48
        width: 336
        height: 105
        onButtonClicked: mainLoader.source = "MainMenuScreen.qml"
    }
}
