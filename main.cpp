#include <QApplication>
#include <Qt/ConnectMediator.h>
#include "Qt/MainWidget.h"
#include "Logic/ImageCursorController.h"
#include "Logic/LabelImageLoader.h"
#include "Logic/OpenCVWrapper.h"
#include "Logic/MatHandler.h"
#include "Logic/PathSearcher.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto pathToImage = argv[1];

    auto labelLoader = std::make_shared<LabelImageLoader>();
    auto label = labelLoader->loadImageToLabel(pathToImage);
    label->reformSize(QSize(1100, 900));
    //label->show();

    auto openCvWrapper = std::make_shared<OpenCVWrapper>();
    openCvWrapper->loadImage(pathToImage);

    auto pathSearcher = std::make_shared<PathSearcher>(openCvWrapper);

    auto matHandler = std::make_shared<MatHandler>(openCvWrapper, pathSearcher);
    auto connector = new ConnectMediator;

    auto cursorController = new ImageCursorController(connector, matHandler);
    cursorController->setPixmap(*label->pixmap());





    MainWidget widget(cursorController, connector);
    widget.show();

    return QApplication::exec();
}
