//
// Created by denis on 16.07.2021.
//

#include "ImageLabel.h"

const QPixmap* ImageLabel::getPixMap() {
    return this->pixmap();
}

void ImageLabel::reformSize(QSize size) {
    this->setPixmap(this->getPixMap()->scaled(size.width(), size.height(), Qt::KeepAspectRatio));
}
