import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls
import com.serik.personel 1.0
import com.serik.global 1.0

Rectangle{
    anchors.fill: parent
    color:"red"
    property real _width: width

    property PersonelModel mPersonelModel: Global.getPersonelModel()

    ScrollView{
        anchors.fill: parent
        ColumnLayout{
            anchors.fill: parent

            Repeater{
                Layout.fillWidth: true

                model: mPersonelModel;

                delegate: Rectangle{
                    color:"orange"
                    width: _width
                    height: 50

                    Rectangle{
                        anchors.centerIn: parent
                        width: parent.width-15
                        height: parent.height-15
                        border.color: "black"
                        border.width: 1
                    }
                }

            }

        }

    }

}
