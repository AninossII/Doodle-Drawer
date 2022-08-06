import QtQuick 2.0
import QtQuick.Controls 2.12

Item {
    id: gameSelectScreen
    
    property string listBackground: "#A4A9AD"
    

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
    
    Rectangle {
        id: roomLobbyListBackground
        radius: 5
        width: 360
        height: 420
        color: listBackground
        anchors{
            top: titleText.bottom
            left: parent.left
            topMargin: 20
            leftMargin: 40
        }  
            
    }   
    Rectangle{
        id: roomLobbyChatBackground
        radius: 5 
        color: listBackground
        anchors{
            top: roomLobbyListBackground.top
            bottom: roomLobbyListBackground.bottom
            left: roomLobbyListBackground.right
            right: parent.right
            leftMargin: 20
            rightMargin: 40
        }        
    } 
    GameButton{
        id: readdyGameButton        
        buttonText: "Ready"
        buttonTextPixelSize: 36
        width: 315
        height: 80
        anchors{
            top: roomLobbyListBackground.bottom
            topMargin: 20     
            horizontalCenter: roomLobbyListBackground.horizontalCenter
        }
        onButtonClicked: console.log("Ready Button Clicked!")
    }
    
    Rectangle {
        id: roomLobbyCharButtoncontainer
        width: roomLobbyChatBackground.width
        height: 80
        color: "transparent"
        anchors{
          top: roomLobbyChatBackground.bottom
          topMargin: 20  
          horizontalCenter: roomLobbyChatBackground.horizontalCenter        
        }
        
        GameButton{
            id: sendGameButton
            buttonText: "Send"
            buttonTextPixelSize: 36
            width: 140
            height: parent.height
            anchors.right: parent.right            
        }

        GameTextInput{
            id: chatTextInput
        }       
        
        //Ep 17 || 06:14
    }
}

    //acceptableInput: bool
    //activeFocusOnPress: bool
    //autoScroll: bool
    //bottomPadding: real
    //canPaste: bool
    //canRedo: bool
    //canUndo: bool
    //color: color
    //contentHeight: real
    //contentWidth: real
    //cursorDelegate: Component
    //cursorPosition: int
    //cursorRectangle: rectangle
    //cursorVisible: bool
    //displayText: string
    //echoMode: enumeration
    //effectiveHorizontalAlignment: enumeration
    //font.bold: bool
    //font.capitalization: enumeration
    //font.family: string
    //font.hintingPreference: enumeration
    //font.italic: bool
    //font.kerning: bool
    //font.letterSpacing: real
    //font.pixelSize: int
    //font.pointSize: real
    //font.preferShaping: bool
    //font.strikeout: bool
    //font.styleName: string
    //font.underline: bool
    //font.weight: enumeration
    //font.wordSpacing: real
    //horizontalAlignment: enumeration
    //inputMask: string
    //inputMethodComposing: bool
    //inputMethodHints: enumeration
    //leftPadding: real
    //length: int
    //maximumLength: int
    //mouseSelectionMode: enumeration
    //overwriteMode: bool
    //padding: real
    //passwordCharacter: string
    //passwordMaskDelay: int
    //persistentSelection: bool
    //preeditText: string
    //readOnly: bool
    //renderType: enumeration
    //rightPadding: real
    //selectByMouse: bool
    //selectedText: string
    //selectedTextColor: color
    //selectionColor: color
    //selectionEnd: int
    //selectionStart: int
    //text: string
    //topPadding: real
    //validator: Validator
    //verticalAlignment: enumeration
    //wrapMode: enumeration
    //accepted()
    //clear()
    //copy()
    //cut()
    //deselect()
    //editingFinished()
    //ensureVisible(intposition)
    //insert(intposition,stringtext)
    //isRightToLeft(intstart,intend)
    //moveCursorSelection(intposition,SelectionModemode=TextInput.SelectCharacters)
    //paste()
    //redo()
    //remove(intstart,intend)
    //select(intstart,intend)
    //selectAll()
    //selectWord()
    //textEdited()
    //undo()
    //
    //
    //activeFocus: bool
    //activeFocusOnTab: bool
    //anchors.alignWhenCentered: bool
    //anchors.baseline: AnchorLine
    //anchors.baselineOffset: real
    //anchors.bottom: AnchorLine
    //anchors.bottomMargin: real
    //anchors.centerIn: Item
    //anchors.fill: Item
    //anchors.horizontalCenter: AnchorLine
    //anchors.horizontalCenterOffset: real
    //anchors.left: AnchorLine
    //anchors.leftMargin: real
    //anchors.margins: real
    //anchors.right: AnchorLine
    //anchors.rightMargin: real
    //anchors.top: AnchorLine
    //anchors.topMargin: real
    //anchors.verticalCenter: AnchorLine
    //anchors.verticalCenterOffset: real
    //antialiasing: bool
    //baselineOffset: int
    //children: list<Item>
    //childrenRect.height: real
    //childrenRect.width: real
    //childrenRect.x: real
    //childrenRect.y: real
    //clip: bool
    //containmentMask: QObject*
    //data: list<Object>
    //enabled: bool
    //focus: bool
    //height: real
    //implicitHeight: real
    //implicitWidth: real
    //layer.effect: Component
    //layer.enabled: bool
    //layer.format: enumeration
    //layer.mipmap: bool
    //layer.samplerName: string
    //layer.samples: enumeration
    //layer.smooth: bool
    //layer.sourceRect: rect
    //layer.textureMirroring: enumeration
    //layer.textureSize: size
    //layer.wrapMode: enumeration
    //opacity: real
    //parent: Item
    //resources: list<Object>
    //rotation: real
    //scale: real
    //smooth: bool
    //state: string
    //states: list<State>
    //transform: list<Transform>
    //transformOrigin: enumeration
    //transitions: list<Transition>
    //visible: bool
    //visibleChildren: list<Item>
    //width: real
    //x: real
    //y: real
    //z: real
    //childAt(realx,realy)
    //forceActiveFocus()
    //forceActiveFocus(Qt: : FocusReasonreason)
    //nextItemInFocusChain(boolforward)
    //objectName: string
