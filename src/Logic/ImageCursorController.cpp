//
// Created by denis on 16.07.2021.
//

#include "Logic/ImageCursorController.h"
#include "Qt/IConnectMediator.h"
#include <utility>

QPoint ImageCursorController::getMousePos(QMouseEvent *event) {
    return event->pos();
}

void ImageCursorController::mousePressEvent(QMouseEvent *ev) {
    if (m_state != mouseDoState::none)
    {
        auto pos = getMousePos(ev);
        switch (m_state) {
            case mouseDoState::setStartDot:
                m_pMatHandler->SetStartDot(pos);
                break;
            case mouseDoState::setEndDot:
                m_pMatHandler->SetEndDot(pos);
                break;
            default:
                break;
        }
        m_state = mouseDoState::none;
    }
}

ImageCursorController::ImageCursorController(QLabel* label, std::shared_ptr<IMatHandler> matHandler):
m_label(label),
m_pMatHandler(std::move(matHandler))
{
    connect(this, SIGNAL(pressedMouse(QMouseEvent *)), this, SLOT(mousePressEvent(QMouseEvent *)));
    connect(this, SIGNAL(setStartPoint()), this, SLOT(setStartDot()));
    connect(this, SIGNAL(setEndPoint()), this, SLOT(setEndDot()));
}

void ImageCursorController::setStartDot() {
    m_state = mouseDoState::setStartDot;
}

void ImageCursorController::setEndDot() {
    m_state = mouseDoState::setEndDot;
}


