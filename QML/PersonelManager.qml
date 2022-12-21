import QtQuick 2.15

Item {


    Rectangle{
        anchors.fill: parent
        color:"red"

        MouseArea{
            anchors.fill: parent

            onClicked: {
                console.log("RESD");
            }
        }
    }

}
