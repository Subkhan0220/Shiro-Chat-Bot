cmake_minimum_required(VERSION 3.16)

project(SHIROOO VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network) # <--- Добавляем Network
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network) # <--- Добавляем Network

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SHIROOO
        main.cpp
        shiro.cpp
        shiro.h
        shiro.ui
        rec.qrc
    )
else()
    add_executable(SHIROOO
        main.cpp
        shiro.cpp
        shiro.h
        shiro.ui
    )
endif()

target_link_libraries(SHIROOO PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network) # <--- Связываем с Network

set_target_properties(SHIROOO PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SHIROOO
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SHIROOO)
endif()

