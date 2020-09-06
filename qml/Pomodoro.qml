import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQml 2.12

Rectangle {
    id: pomodoroClock
    visible: true
    width: 400
    height: 400
    color: "#A0e0c3fc"

    anchors.centerIn: parent

    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#A0e0c3fc"
        }

        GradientStop {
            position: 1
            color: "#A08ec5fc"
        }
    }

    StackView {
        id: stack
        initialItem: pageSelectInterval
        //anchors.fill: parent
        //anchors.centerIn: parent

        SelectInterval {
            id: pageSelectInterval
            onIntervalSelected: function(interval) {
                console.log(`interval selected: ${interval}`)
                stack.push(pageClock)
                pageClock.visible = true
                pageClock.pomodoroInterval = interval
                pageClock.startPomodoro()
            }
        }

        Clock {
            id: pageClock
            visible: false
            onPomodoroEnd: {
                stack.pop(pageClock)
                pageClock.visible = false
            }
        }
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:3}
}
##^##*/
