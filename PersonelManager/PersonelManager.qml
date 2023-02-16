import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls
import com.belediye.personel 1.0
import com.belediye.global 1.0

Rectangle{
    anchors.fill: parent
    color:"red"
    property real _width: width
    property real _height: height

    property PersonelModel mPersonelModel: Global.getPersonelModel()



        Rectangle{
            width: 150
            height: parent.height
            color: "green"
        }

        ScrollView{
            anchors.fill: parent
            anchors.leftMargin: 150
            ColumnLayout{
                anchors.fill: parent

                Repeater{
                    Layout.fillWidth: true

                    model: mPersonelModel;

                    delegate: Rectangle{
                        color:"orange"
                        width: _width-170
                        height: 100

                        Rectangle{
                            anchors.centerIn: parent
                            width: parent.width-15
                            height: parent.height-15
                            border.color: "black"
                            border.width: 1

                            Text {
                                id: name
                                text: adsoyad;
                            }
                        }
                    }

                }

            }

        }





}
