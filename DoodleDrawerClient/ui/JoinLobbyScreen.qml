import QtQuick 2.3

Item {
    id: joinLobbyScreen

    
    Rectangle {
        id: background
        anchors.fill: parent
        color: "#23001E"
    }
    
    GameTitle{
        id: titleText
        textTitle: "Enter Game Code"
    }

    GameTextInput{
        id: gameLobbyCode 
    }

    GameButton{
        id: playButton
        anchors.centerIn: parent
        buttonText: "Join Game"
        width: 336
        height: 105
        onButtonClicked: console.log("Join Button Clicked!")
    }

    GameButton{
        id: quitButton
        anchors{
            top: playButton.bottom
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }

        buttonText: "Back"
        width: 336
        height: 105
        onButtonClicked: console.log("Back Button Clicked!")
    }

}


