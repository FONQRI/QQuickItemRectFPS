# QQuickItemRectFPS
## QtQuick Custom Item Performance 
This is an example for  showing fps of showing 10000 rectangles in qquickitem .
- draw in opengl 
- show in qml 
I implemented example of [QtQuick Custom Item Performance](https://www.vikingsoftware.com/qtquick-custom-item-performance/) . And after that i implemented my own approach on it . if you want to see post approach only need to comment :
``` qml
//NOTE if you want test post code comment on the code below
PainterRectItemQQI {
    anchors.fill: parent
    color: root.col
}
```
And uncomment :
```qml
//NOTE if you want test post code Uncomment on the code below
Repeater {
    model: 1
    Loader {
        width: root.rectangleSize
        height:root.rectangleSize
        opacity: 0.9 // even if overlap, drawing is needed
        sourceComponent: root.solution == 0 ? qtquickComponent :
                              root.solution == 1 ?  paintedComponent :canvasComponent
    }
}
```

And after that by changing solution from 0 to 2 test post wayes (0 for QtQuick, 1 for paintedItem, 2 for canvas).
If you have any questions, please feel free to ask
