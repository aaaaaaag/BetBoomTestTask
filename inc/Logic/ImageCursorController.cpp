//
// Created by denis on 16.07.2021.
//

#include "ImageCursorController.h"

QPointF ImageCursorController::getMousePos(QMouseEvent *event) {
    return event->pos();
}

void ImageCursorController::mousePressEvent(QMouseEvent *ev) {

}

ImageCursorController::ImageCursorController(QLabel* label): m_label(label) {
    connect(this, SIGNAL(pressedMouse(QMouseEvent *)), this, SLOT(mousePressEvent(QMouseEvent *)));
}


