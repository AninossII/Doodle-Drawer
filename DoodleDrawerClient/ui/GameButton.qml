import QtQuick 2.0

Rectangle {
    id: gameButton
    property string buttonColor: "#FFBA49"
    property string buttonPressedColor: "#c48f39"
    property string buttonText: ""
    property int buttonTextPixelSize: 72

    signal buttonClicked()

    radius: 5
    color: buttonColor

    Text{
        anchors.centerIn: parent
        color: "white"
        text: buttonText
        font.pixelSize: buttonTextPixelSize
    }

    MouseArea{
        anchors.fill: parent
        onPressed: gameButton.color = buttonPressedColor
        onReleased: gameButton.color = buttonColor
        onClicked: gameButton.buttonClicked()
    }
}
