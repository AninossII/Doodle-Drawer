import QtQuick 2.3
import QtQuick.Controls 2.12

Rectangle {
    id: gameTextInput 
    property string backgroundColor: "#A4A9AD"
    property string textColor: "#fff"
    property string textFontFamily: "ROBOTO"
    property int textPixelSize: 24
    property bool textBold: true

    

    radius: 5        
    height: 80  
    color: backgroundColor              
    anchors{
        left: parent.left
        right: sendGameButton.left
        rightMargin: 20
    }

    Rectangle{
        width: chatTextInput.width
        height: 80                  
        color: "transparent"
        //clip: true     
        anchors{
            right: parent.right
            rightMargin: 10
            left: parent.left
            leftMargin: 10
        }
        TextField{     
            background: Item{ opacity: 0}
            width: parent.width                    
            font.family: textFontFamily
            font.pixelSize: textPixelSize
            font.bold: true
            placeholderText: "Text..."
            color: textColor
            anchors.verticalCenter: parent.verticalCenter 
        } 
    }           
} 