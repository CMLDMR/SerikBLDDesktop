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
        width: parent.width
        height: 40
        color: "orange"

        ToolBar {
            anchors.fill: parent
            RowLayout {
                anchors.fill: parent
                ToolButton {
                    id: personemMenuID
                    text: qsTr("Personel")
                    onClicked: contextMenu.popup()
                    Menu {
                        id: contextMenu
                        MenuItem { text: "Cut" }
                        MenuItem { text: "Copy" }
                        MenuItem { text: "Paste" }
                    }
                }

                ToolButton {
                    text: qsTr("Müdürlükler")
                }
            }
        }





    }



    ScrollView{
        anchors.fill: parent
        anchors.topMargin: 50
        contentWidth: parent.width
        leftPadding: 15
        rightPadding: 15
        Flow{
            anchors.fill: parent
            Layout.preferredWidth: parent.parent.width
            spacing: 5

            Repeater{

                model: mPersonelModel;

                delegate: Rectangle{
                    color:"orange"
                    width: 280
                    height: 100


                    Image {
                        id: personelPhotoID
                        width: 80
                        height: 100
                        fillMode: Image.PreserveAspectCrop
                        source: foto
                        clip: true
                        anchors.leftMargin: 0
                    }

                    Rectangle{
                        width: 200
                        anchors.left: personelPhotoID.right
                        height: parent.height
                        color: "#AA553344"

                        ColumnLayout{
                            anchors.fill: parent
                            Text {
                                text: adsoyad;
                            }
                            Text {
                                text: telefon;
                            }
                            Text {
                                text: birim;
                            }
                        }

                    }

                }
            }
        }
    }
}
