cmake_minimum_required(VERSION 3.19)
project(BetBoomTestTask)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)


add_library(${PROJECT_NAME} inc/Qt/MainWidget.cpp inc/Qt/MainWidget.h)

find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME} PUBLIC inc)

add_executable(${PROJECT_NAME}_debug main.cpp)
target_link_libraries(${PROJECT_NAME}_debug ${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME}_debug PUBLIC inc)