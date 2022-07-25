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
        text: "Lobby code: " + gameManager.roomLobbyCode
    }
}
