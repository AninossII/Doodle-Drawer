import QtQuick 2.0

Item {
    id: gameSelectScreen

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
        onButtonClicked: mainLoader.source = "JoinLobbyScreen.qml"
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
