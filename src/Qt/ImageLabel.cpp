//
// Created by denis on 16.07.2021.
//

#include "Qt/ImageLabel.h"

const QPixmap* ImageLabel::getPixMap() {
    return this->pixmap();
}

void ImageLabel::reformSize(QSize size) {
    this->setMaximumSize(size);
    this->setMinimumSize(size);
    this->setPixmap(this->getPixMap()->scaled(size.width(), size.height(), Qt::KeepAspectRatio));
}

ImageLabel::ImageLabel(QSize origImageSize): m_origImageSize(origImageSize) {
}

QSize ImageLabel::getOrigImageSize() {
    return m_origImageSize;
}
