import QtQuick 2.3
import QtQuick.Controls 2.12

Item {
    id: joinLobbyScreen
    property string listBackground: "#A4A9AD"
    property string backgroundColor: "#A4A9AD"
    
    Rectangle {
        id: background
        anchors.fill: parent
        color: "#23001E"
    }
    
    GameTitle{
        id: titleText
        textTitle: "Enter Game Code"
    }

    Rectangle{
        id: roomLobbyIDBackground
        width: parent.width
        height: parent.hight
        color: "transparent"
        anchors{
            top: titleText.bottom 
            topMargin: 40                 
        }

        Rectangle {
            id: roomLobbyCharButtoncontainer
            width: parent.width/2
            height: width/8            
            color: listBackground
            radius: 5 
            anchors{
                top: roomLobbyIDBackground.top                
                horizontalCenter: roomLobbyIDBackground.horizontalCenter        
            } 

            Rectangle {
                id: chatTextInput
                radius: 5        
                height: parent.height  
                color: backgroundColor              
                anchors{
                    right: parent.right
                    left: parent.left
                    rightMargin: 20
                    leftMargin: 20
                }               
                TextField{     
                    background: Item{ opacity: 0}                    

                    font.family: "ROBOTO"
                    font.pixelSize: 36
                    font.bold: true
                    placeholderText: "Lobby ID..."
                    color: "#fff"

                    anchors.verticalCenter: parent.verticalCenter                     
                    anchors.horizontalCenter: parent.horizontalCenter
                    
                    maximumLength: 4
                    validator: IntValidator {bottom: 1000; top: 9999}
                }                    
            }        

        }      
    } 

    GameButton{
        id: joinButton
        anchors.centerIn: parent
        buttonText: "Join Game"
        width: 336
        height: 105
        buttonTextPixelSize: 60
        onButtonClicked: console.log("Join Button Clicked!")
    }

    GameButton{
        id: backButton
        anchors{
            top: joinButton.bottom
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }

        buttonText: "Back"
        width: 336
        height: 105
        onButtonClicked: mainLoader.source = "GameSelectScreen.qml"
    }

}


