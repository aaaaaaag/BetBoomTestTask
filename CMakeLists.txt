cmake_minimum_required(VERSION 3.19)
project(BetBoomTestTask)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)


add_library(${PROJECT_NAME} src/Qt/MainWidget.cpp inc/Qt/MainWidget.h src/Logic/OpenCV/OpenCVWrapper.cpp inc/Logic/OpenCV/OpenCVWrapper.h inc/Logic/OpenCV/IOpenCVWrapper.h
        inc/Logic/IImageCursorController.h src/Logic/ImageCursorController.cpp inc/Logic/ImageCursorController.h
        inc/Logic/ILabelImageLoader.h inc/Qt/IImageLabel.h src/Qt/ImageLabel.cpp inc/Qt/ImageLabel.h src/Logic/LabelImageLoader.cpp inc/Logic/LabelImageLoader.h inc/Logic/OpenCV/IMatHandler.h src/Logic/OpenCV/MatHandler.cpp inc/Logic/OpenCV/MatHandler.h src/Logic/OpenCV/DotChecker.cpp inc/Logic/OpenCV/DotChecker.h src/Logic/Exception.cpp inc/Logic/Exception.h src/Logic/OpenCV/PathSearcher.cpp inc/Logic/OpenCV/PathSearcher.h inc/Logic/OpenCV/IPathSearcher.h src/Qt/WarningThrower.cpp inc/Qt/WarningThrower.h inc/Qt/IWarningThrower.h
        inc/Qt/WarningThrower.h src/Qt/WarningThrower.cpp inc/Logic/Commands/IButtonCommand.h src/Logic/Commands/CommandGetResultPix.cpp inc/Logic/Commands/CommandGetResultPix.h src/Logic/Commands/CommandGetResultMM.cpp inc/Logic/Commands/CommandGetResultMM.h src/Logic/Facade.cpp inc/Logic/Facade.h inc/Logic/IFacade.h src/Logic/FacadeSlotWrapper.cpp inc/Logic/FacadeSlotWrapper.h src/Logic/Commands/CommandSetStartPoint.cpp inc/Logic/Commands/CommandSetStartPoint.h src/Logic/Commands/CommandSetEndPoint.cpp inc/Logic/Commands/CommandSetEndPoint.h)

find_package( OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME} PUBLIC inc)

add_executable(${PROJECT_NAME}_debug main.cpp)
target_link_libraries(${PROJECT_NAME}_debug ${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME}_debug PUBLIC inc)