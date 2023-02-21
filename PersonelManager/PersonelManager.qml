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
        id: personelToolBarid
        width: parent.width
        height: 40
        color: "orange"

        ToolBar {
            anchors.fill: parent
            RowLayout {
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: parent.height
                ToolButton {
                    id: personemMenuID
                    text: qsTr("Personel")
                    onClicked: contextMenu.open()
                }

                ToolButton {
                    id: birimMenuID
                    text: qsTr("Müdürlükler")
                    onClicked: birimContextMenuID.open()
                }
            }
        }

    }


    Menu {
        id: contextMenu
        MenuItem { text: "Yeni Ekle" }
        y: personelToolBarid.height
    }

    Menu {
        id: birimContextMenuID
        MenuItem { text: "Yeni Birim Ekle" }
        y: personelToolBarid.height
        x: birimMenuID.x
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
                            Layout.preferredWidth: parent.width
                            Text {
                                text: adsoyad;
                                color: "white"
                            }
                            Text {
                                text: telefon;
                                color: "white"
                            }
                            Text {
                                text: birim;
                                color: "white"
                            }
                        }

                    }

                    MouseArea{
                        anchors.fill: parent

                        onClicked: personelItemContextMenuID.open()
                    }


                    Menu {
                        id: personelItemContextMenuID
                        y: personelPhotoID.height
                        x: personelPhotoID.x
                        MenuItem { text: "Bilgileri Değiştir" }
                        MenuItem { text: "Birim Değiştir" }
                        MenuItem { text: "Telefon No Değiştir Değiştir" }
                        MenuItem { text: "Ad Soyad Değiştir" }

                    }
                }
            }
        }
    }
}
