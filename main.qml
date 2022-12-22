import QtQuick
import "qrc:/../QML"
import com.serik 1.0
import com.serik.global 1.0

Window {
    width: 1024
    height: 640
    visible: true
    title: qsTr("Hello World")

    SerikBLDBackend{
        id: backendManager
        anchors.fill: parent
        Loader{
            id: myLoader
            anchors.fill: parent
            source: backendManager.currentPage
        }

        Connections {
                target: myLoader.item
                ignoreUnknownSignals: true
                function onPageChanged(pageUrl){
                    console.log(pageUrl);
                    backendManager.setCurrentPage( pageUrl );
                }
            }

    }



}
