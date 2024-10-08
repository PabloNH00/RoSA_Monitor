cmake_minimum_required(VERSION 3.5)

project(RoSA_Monitor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        rosawindow.cpp
        simulationwindow.cpp
        launchermanager.cpp
        Launcher.cpp
        shelloutputwindow.cpp
        selectrosacomponents.cpp

        mainwindow.h
        rosawindow.h
        simulationwindow.h
        launchermanager.h
        Launcher.h
        shelloutputwindow.h
        selectrosacomponents.h

        mainwindow.ui
        simulationwindow.ui
        rosawindow.ui
        shelloutputwindow.ui
        selectrosacomponents.ui

        resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(RoSA_Monitor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET RoSA_Monitor APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(RoSA_Monitor SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(RoSA_Monitor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(RoSA_Monitor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(RoSA_Monitor PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(RoSA_Monitor)
endif()
