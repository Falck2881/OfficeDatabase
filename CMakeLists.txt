cmake_minimum_required(VERSION 3.18)

project(ProviderDataBase VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Core Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Sql REQUIRED)

qt_add_resources(STYLE_RCC "${CMAKE_CURRENT_SOURCE_DIR}/RCC/StyleApp.qrc")
qt_add_resources(IMAGE_RCC "${CMAKE_CURRENT_SOURCE_DIR}/RCC/Image/Images.qrc")

set(WINDOWS         Windows/MainWindow.h Windows/MainWindow.cpp Windows/MainWindow.ui
                    Windows/WindowContacts.cpp Windows/WindowContacts.h Windows/WindowContacts.ui)

set(OTHER_SOURCES Sources/Identify.h
                  Sources/IdentifyCompany.h Sources/IdentifyCompany.cpp
                  Sources/IdentifyContacts.h Sources/IdentifyContacts.cpp
                  Sources/IdentifyProduct.h Sources/IdentifyProduct.cpp
                  Sources/ProductTables.h Sources/ProductTables.cpp
                  Sources/LustrofProductTables.h Sources/LustrofProductTables.cpp
                  Sources/BraubergProductTables.h Sources/BraubergProductTables.cpp
                  Sources/FunctionsDataBase.h
                  Sources/Find.h
                  Sources/FindProduct.h Sources/FindProduct.cpp)

set(PROJECT_SOURCES main.cpp ${WINDOWS} ${OTHER_SOURCES})

add_executable(ProviderDataBase WIN32 ${PROJECT_SOURCES} ${STYLE_RCC} ${IMAGE_RCC})


target_link_libraries(ProviderDataBase PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                               Qt${QT_VERSION_MAJOR}::Core
                                               Qt${QT_VERSION_MAJOR}::Sql)

target_include_directories(ProviderDataBase PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Windows"
                                                    "${CMAKE_CURRENT_SOURCE_DIR}/Sources")

set_target_properties(ProviderDataBase PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ProviderDataBase)
endif()
