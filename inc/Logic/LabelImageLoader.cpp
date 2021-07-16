//
// Created by denis on 16.07.2021.
//

#include "LabelImageLoader.h"
#include "Qt/ImageLabel.h"
QLabel *LabelImageLoader::loadImageToLabel(std::string path) {
    QPixmap pixmap(path.data());
    int w = pixmap.width();
    int h = pixmap.height();

    auto *lab = new ImageLabel; //TODO maybe fabric method

    lab->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
    return lab;
}
