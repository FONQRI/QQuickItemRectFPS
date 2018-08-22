import QtQuick 2.6
import QtQuick.Window 2.0
import test 1.0
import test2 1.0

Rectangle {
    id: root
    width: 1200
    height: 1100
    property color col: "black"

    //NOTE 0 for QtQuick, 1 for paintedItem, 2 for canvas
    property int solution: 0

    property int rectangleSize: 512
    property int numberOfRectangles: 1000
    ColorAnimation on col {
        from: "red"
        to: "green"
        duration: 8000
        loops: 100
    }

    //NOTE if you want test post code comment on the code below
    PainterRectItemQQI {
        anchors.fill: parent
        color: root.col
    }
    //To here ****************************************************


    //NOTE if you want test post code Uncomment on the code below
//    Repeater {
//        model: 1
//        Loader {
//            width: root.rectangleSize
//            height:root.rectangleSize
//            opacity: 0.9 // even if overlap, drawing is needed
//            sourceComponent: root.solution == 0 ? qtquickComponent :
//                                  root.solution == 1 ?  paintedComponent :canvasComponent
//        }
//    }
    //to here ***************************************************

    // QtQuick OpenGL based solution
    Component {
        id: qtquickComponent
        Rectangle {

            color: root.col
        }
    }
    // QQuickPaintedItem based solution
    Component {
        id: paintedComponent
        PainterRectItem {
            color: root.col
        }
    }

    Component {
        id: paintedQQIComponent
        PainterRectItemQQI {
            color: root.col
        }
    }

    // Canvas based solution
    Component {
        id: canvasComponent
        Canvas {
            id: canvasRect
            Connections {
                target: root
                onColChanged: canvasRect.requestPaint();
            }
            onPaint: {
                var ctx = getContext("2d");
                ctx.fillStyle = root.col;
                ctx.fillRect(0, 0, width, height);
            }
        }
    }
}

