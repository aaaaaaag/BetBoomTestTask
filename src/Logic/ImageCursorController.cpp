//
// Created by denis on 16.07.2021.
//

#include "Logic/ImageCursorController.h"
#include <utility>
#include <iostream>
#include "Logic/Exception.h"
#include "Qt/WarningThrower.h"
QPoint ImageCursorController::getMousePos(QMouseEvent *event) {
    auto pos = event->pos();

    auto kx = this->m_origImageSize.height() / this->height();
    auto ky = this->m_origImageSize.width() / this->width();

    auto x = pos.x() * kx;
    auto y = pos.y() * ky;
    pos.setY(x);
    pos.setX(y);

    return pos;
}

void ImageCursorController::mousePressEvent(QMouseEvent *ev) {
    auto pos = getMousePos(ev);
    std::cout << "click coord: (" << pos.x() << ", " << pos.y() << ")\n";
    try {
        switch (m_state) {
            case mouseDoState::setStartDot:
                m_pMatHandler->SetStartDot(pos);
                m_state = mouseDoState::none;
                break;
            case mouseDoState::setEndDot:
                m_pMatHandler->SetEndDot(pos);
                m_state = mouseDoState::none;
                break;
            default:
                break;
        }
    }
    catch (Exception &ex)
    {
        WarningThrower::ShowWarning(&ex);
    }

}

void ImageCursorController::setState(mouseDoState state) {
    m_state = state;
}

ImageCursorController::ImageCursorController(std::shared_ptr<IMatHandler> matHandler, QSize origImageSize):
m_pMatHandler(std::move(matHandler))
{
    this->m_origImageSize = origImageSize;
}