#include <QApplication>
#include <Qt/ConnectMediator.h>
#include "Qt/MainWidget.h"
#include "Logic/ImageCursorController.h"
#include "Logic/LabelImageLoader.h"
#include "Logic/OpenCVWrapper.h"
#include "Logic/MatHandler.h"
#include "Logic/PathSearcher.h"
#include "Logic/Facade.h"
#include "Logic/FacadeSlotWrapper.h"

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
