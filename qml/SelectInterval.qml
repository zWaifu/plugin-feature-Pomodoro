import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.11

ColumnLayout {
    id: pageSelectInterval
    //anchors.fill: parent

    signal intervalSelected(int interval)

    property bool selected: false
    property var intervals: [ 5, 10, 15, 20, 25, 30, 45, 60, 90, 120 ]

    Rectangle {
        //anchors.horizontalCenter: parent.horizontalCenter
        //anchors.fill: parent
        //Layout.fillWidth: true
        //color: "#FF3300"

        GridLayout {
            id: grid
            //anchors.horizontalCenter: parent.horizontalCenter
            columns: 3
            rowSpacing: 10
            columnSpacing: 10
            anchors.margins: 5

            Layout.fillWidth: true

            Repeater {
                model: pageSelectInterval.intervals
                RoundButton {
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    Layout.minimumWidth: 100
                    radius: 5

                    onPressed: {
                        var interval = modelData
                        console.log(interval)
                        pageSelectInterval.selected = true
                        pageSelectInterval.intervalSelected(interval)
                    }

                    text: qsTr("%1 min").arg(modelData)
                    enabled: !pageSelectInterval.selected
                }
            }
        }
    }

    Item {
        id: spacer
        Layout.fillHeight: true
        Layout.fillWidth: true
    }
}


/*##^##
Designer {
    D{i:0;autoSize:false;height:200;width:200}
}
##^##*/
