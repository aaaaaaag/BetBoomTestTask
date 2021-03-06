#include <QApplication>
#include "Qt/MainWidget.h"
#include "Qt/ImageCursorController.h"
#include "Logic/LabelImageLoader.h"
#include "Logic/OpenCV/OpenCVWrapper.h"
#include "Logic/OpenCV/MatHandler.h"
#include "Logic/OpenCV/PathSearcher.h"
#include "Logic/Facade.h"
#include "Qt/FacadeSlotWrapper.h"

int main(int argc, char *argv[]) {
    cv::Vec3b backgroundColor(255, 255, 255);
    QApplication a(argc, argv);

    auto pathToImage = argv[1];

    auto labelLoader = std::make_shared<LabelImageLoader>();
    auto label = labelLoader->loadImageToLabel(pathToImage);
    label->reformSize(QSize(960, 540));

    auto openCvWrapper = std::make_shared<OpenCVWrapper>();
    openCvWrapper->loadImage(pathToImage);

    auto pathSearcher = std::make_shared<PathSearcher>(openCvWrapper, backgroundColor);

    auto matHandler = std::make_shared<MatHandler>(openCvWrapper, pathSearcher);

    auto cursorController = new ImageCursorController(matHandler, label->getOrigImageSize());
    cursorController->setPixmap(*label->pixmap());


    cursorController->reformSize(label->size());

    auto facade = std::make_shared<Facade>(matHandler, cursorController, nullptr);
    auto facadeWrapper = std::make_shared<FacadeSlotWrapper>(facade);

    MainWidget widget(cursorController, facadeWrapper);
    widget.show();

    return QApplication::exec();
}
