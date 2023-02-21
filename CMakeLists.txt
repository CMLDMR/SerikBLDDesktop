cmake_minimum_required(VERSION 3.16)

set(PROJECT "SerikBLDDesktopQML")

project(${PROJECT} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

set(bsoncxx_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/mongo/lib/cmake/bsoncxx-3.7.0)
set(mongocxx_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../3rdParty/mongo/lib/cmake/mongocxx-3.7.0)


file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE QMLFILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qml)


source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

#list(APPEND QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
#list(APPEND QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/QML")

#set(QML_IMPORT_PATH ${QML_IMPORT_PATH}
#    CACHE STRING "Qt Creator extra qml import paths"
#    FORCE
#)

qt_add_resources(QT_RESOURCES qmlComponents.qrc)


add_executable(appSerikBLDDesktopQML
    ${HEADERS}
    ${SOURCES}
    ${QT_RESOURCES}
)

qt_add_qml_module(appSerikBLDDesktopQML
    URI SerikBLDDesktopQML
    VERSION 1.0
    QML_FILES main.qml
        QML/AnaMenu.qml
        PersonelManager/PersonelManager.qml
)


target_include_directories(appSerikBLDDesktopQML PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../MSVC2022x64noBoost/include")

target_link_directories(appSerikBLDDesktopQML PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../MSVC2022x64noBoost/lib")

target_include_directories(appSerikBLDDesktopQML PUBLIC "C:/Mongo/mongoCPPCore/install/include")
target_link_directories(appSerikBLDDesktopQML PUBLIC "C:/Mongo/mongoCPPCore/install/lib")
target_link_libraries(appSerikBLDDesktopQML PRIVATE MongoCore)

set_target_properties(appSerikBLDDesktopQML PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSerikBLDDesktopQML
    PRIVATE Qt6::Quick SerikBLDCore)


find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})

target_link_libraries(appSerikBLDDesktopQML PRIVATE mongo::bsoncxx_shared)

target_link_libraries(appSerikBLDDesktopQML PRIVATE mongo::mongocxx_shared)

install(TARGETS appSerikBLDDesktopQML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
