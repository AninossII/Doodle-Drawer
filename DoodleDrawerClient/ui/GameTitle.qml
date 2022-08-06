import QtQuick 2.3

Item{
    id: gameTitle
    width: parent.width
    height: titleText.height * 1.5
    
    property string textTitle: ""
    property int fontPixelSize: 72     
    property alias textItem: titleText
            
    Text{
        id: titleText
        text: textTitle
        font{
            pixelSize: fontPixelSize
            bold: true
            family: "ROBOTO"    
        }    
        anchors{            
            top: parent.top
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }
        color: "white"
    }
}




