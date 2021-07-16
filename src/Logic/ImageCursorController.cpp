//
// Created by denis on 16.07.2021.
//

#include "Logic/ImageCursorController.h"

QPointF ImageCursorController::getMousePos(QMouseEvent *event) {
    return event->pos();
}

void ImageCursorController::mousePressEvent(QMouseEvent *ev) {
    if (m_state != mouseDoState::none)
    {
        auto pos = getMousePos(ev);

    }
}

ImageCursorController::ImageCursorController(QLabel* label): m_label(label) {
    connect(this, SIGNAL(pressedMouse(QMouseEvent *)), this, SLOT(mousePressEvent(QMouseEvent *)));
}

void ImageCursorController::setStartDot() {
    m_state = mouseDoState::setStartDot;
}

void ImageCursorController::setEndDot() {
    m_state = mouseDoState::setEndDot;
}


