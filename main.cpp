#include <QApplication>
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
    label.
    label->show();

    auto openCvWrapper = std::make_shared<OpenCVWrapper>();
    openCvWrapper->loadImage(pathToImage);

    auto pathSearcher = std::make_shared<PathSearcher>(openCvWrapper);

    auto matHandler = std::make_shared<MatHandler>(openCvWrapper, pathSearcher);


    auto cursorController = std::make_shared<ImageCursorController>(label, matHandler);






    MainWidget widget(label);
    widget.show();

    return QApplication::exec();
}
