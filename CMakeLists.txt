cmake_minimum_required(VERSION 3.16)

set(PROJECT "SerikBLDDesktopQML")

project(${PROJECT} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)



file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})



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
)

set_target_properties(appSerikBLDDesktopQML PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSerikBLDDesktopQML
    PRIVATE Qt6::Quick)

install(TARGETS appSerikBLDDesktopQML
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
