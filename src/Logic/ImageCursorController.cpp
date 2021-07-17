//
// Created by denis on 16.07.2021.
//

#include "Logic/ImageCursorController.h"
#include "Qt/IConnectMediator.h"
#include <utility>
#include <iostream>

QPoint ImageCursorController::getMousePos(QMouseEvent *event) {
    return event->pos();
}

void ImageCursorController::mousePressEvent(QMouseEvent *ev) {
    std::cout << "Pressed\n";
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

ImageCursorController::ImageCursorController(IConnectMediator* mediator, std::shared_ptr<IMatHandler> matHandler):
m_pMatHandler(std::move(matHandler))
{
    //connect(this, SIGNAL(mousePressEvent(QMouseEvent *)), this, SLOT(mousePressEvent(QMouseEvent *)));
    connect(mediator, SIGNAL(setStartPoint()), this, SLOT(setStartDot()));
    connect(mediator, SIGNAL(setEndPoint()), this, SLOT(setEndDot()));
}

void ImageCursorController::setStartDot() {
    std::cout << "setStartDot pressed!\n";
    m_state = mouseDoState::setStartDot;
}

void ImageCursorController::setEndDot() {
    std::cout << "setEndDot pressed!\n";
    m_state = mouseDoState::setEndDot;
}


