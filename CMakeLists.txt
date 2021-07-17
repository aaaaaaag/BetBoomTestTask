cmake_minimum_required(VERSION 3.19)
project(BetBoomTestTask)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)


add_library(${PROJECT_NAME} src/Qt/MainWidget.cpp inc/Qt/MainWidget.h src/Logic/OpenCVWrapper.cpp inc/Logic/OpenCVWrapper.h inc/Logic/IOpenCVWrapper.h
        inc/Logic/IImageCursorController.h src/Logic/ImageCursorController.cpp inc/Logic/ImageCursorController.h
        inc/Qt/IConnectMediator.h src/Qt/ConnectMediator.cpp inc/Qt/ConnectMediator.h inc/Logic/ILabelImageLoader.h inc/Qt/IImageLabel.h inc/Logic/IQPixMapToMatConverter.h src/Logic/QPixMapToMatConverter.cpp inc/Logic/QPixMapToMatConverter.h src/Qt/ImageLabel.cpp inc/Qt/ImageLabel.h src/Logic/LabelImageLoader.cpp inc/Logic/LabelImageLoader.h inc/Logic/IMatHandler.h inc/Logic/MatHandler.cpp inc/Logic/MatHandler.h inc/Logic/DotChecker.cpp inc/Logic/DotChecker.h)

find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME} PUBLIC inc)

add_executable(${PROJECT_NAME}_debug main.cpp)
target_link_libraries(${PROJECT_NAME}_debug ${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME}_debug PUBLIC inc)