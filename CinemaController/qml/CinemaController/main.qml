import QtQuick 2.0
import QtDesktop 1.0
import uk.co.icucinema.ScreenControlPoint 1.0
import uk.co.icucinema.System 1.0

Rectangle {
    id: backgroundRectangle
    width: 1024
    height: 768
    color: "#ccc"

    ScreenControlPoint {
        id: screenControlPoint
    }

    System {
        id: system
    }

    Column {
        id: column
        anchors.fill: parent
        anchors.margins: 25

        Rectangle {
            id: screenControlsTitle
            width: column.width
            height: 50
            color: "#aaa"
            border.color: "#666"
            border.width: 5
            radius: 10

            Text {
                anchors.centerIn: parent
                text: "Screen Controls"
                font.pixelSize: 36
            }
        }

        Rectangle {
            width: column.width
            height: 25
            color: backgroundRectangle.color
        }


        Rectangle {
            id: raiseButton
            width: column.width
            height: Math.round((column.height - 125) / 2) - 25
            color: "#6f6"
            border.color: "#666"
            border.width: 5
            radius: 10

            Text {
                anchors.centerIn: parent
                text: "Raise Screen"
            }

            MouseArea {
                anchors.fill: parent

                onPressed: {
                    console.log("mouse button pressed")
                    raiseButton.color = "#afa"
                    screenControlPoint.startRaiseScreen()
                }

                onReleased: {
                    console.log("mouse button released")
                    raiseButton.color = "#6f6"
                    screenControlPoint.stopRaiseScreen()
                }

            }

        }

        Rectangle {
            width: column.width
            height: 25
            color: backgroundRectangle.color
        }

        Rectangle {
            id: lowerButton
            width: column.width
            height: Math.round((column.height - 125) / 2) - 25
            color: "#f66"
            border.color: "#666"
            border.width: 5
            radius: 10

            Text {
                anchors.centerIn: parent
                text: "Lower Screen"
            }

            MouseArea {
                anchors.fill: parent

                onPressed: {
                    console.log("mouse button pressed")
                    lowerButton.color = "#faa"
                    screenControlPoint.startLowerScreen()
                }

                onReleased: {
                    console.log("mouse button released")
                    lowerButton.color = "#f66"
                    screenControlPoint.stopLowerScreen()
                }

            }

        }

        Rectangle {
            width: column.width
            height: 25
            color: backgroundRectangle.color
        }

        Row {
            id: systemControlsRow
            width: column.width
            height: 50

            Rectangle {
                id: exitButton
                width: (systemControlsRow.width - 25) / 2
                height: 50
                color: "#66f"
                border.color: "#666"
                border.width: 5
                radius: 10

                Text {
                    anchors.centerIn: parent
                    text: "Exit"
                    font.pixelSize: 36
                }

                MouseArea {
                    anchors.fill: parent

                    onPressed: {
                        console.log("mouse button pressed")
                        exitButton.color = "#aaf"
                        system.exit()
                    }

                    onReleased: {
                        console.log("mouse button released")
                        exitButton.color = "#66f"
                    }

                }
            }

            Rectangle {
                width: 25
                height: systemControlsRow.height
                color: backgroundRectangle.color
            }

            Rectangle {
                id: shutdownButton
                width: (systemControlsRow.width - 25) / 2
                height: 50
                color: "#66f"
                border.color: "#666"
                border.width: 5
                radius: 10

                Text {
                    anchors.centerIn: parent
                    text: "Shutdown"
                    font.pixelSize: 36
                }

                MouseArea {
                    anchors.fill: parent

                    onPressed: {
                        console.log("mouse button pressed")
                        shutdownButton.color = "#aaf"
                        system.shutdown()
                    }

                    onReleased: {
                        console.log("mouse button released")
                        shutdownButton.color = "#66f"
                    }

                }
            }
        }
    }
}
