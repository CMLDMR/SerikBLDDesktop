import QtQuick 2.15
import QtQuick.Layouts
import com.belediye.global 1.0




Rectangle{

    signal pageChanged(string pageUrl)

    anchors.fill: parent
    color: "DarkCyan"


    RowLayout{

        Layout.fillWidth: parent

        Rectangle{

            width: 250
            height: 100
            color:"dimgray"

            Text {
                id: name
                text: qsTr("Personel Yönetimi")
                anchors.centerIn: parent
                color: "white"
                font.bold: true
                font.family: "Tahoma"
                font.pointSize: 14
            }

            MouseArea{
                anchors.fill: parent
                cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
                onClicked: {
                    pageChanged(Global.personelPage());
                }
                hoverEnabled: true
            }
        }
    }
}

