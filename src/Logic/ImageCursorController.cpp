//
// Created by denis on 16.07.2021.
//

#include "Logic/ImageCursorController.h"
#include "Qt/IConnectMediator.h"
#include <utility>
#include <iostream>
#include "Logic/Exception.h"
#include "Qt/WarningThrower.h"
QPoint ImageCursorController::getMousePos(QMouseEvent *event) {
    return event->pos();
}

void ImageCursorController::mousePressEvent(QMouseEvent *ev) {
    std::cout << "Pressed\n";
    if (m_state != mouseDoState::none)
    {

        auto pos = getMousePos(ev);
        pos.setY(pos.y() - 160);

        auto x = pos.x() * 2;
        auto y = pos.y() * 2;
        pos.setY(x);
        pos.setX(y);

        std::cout << "Dot: (" << pos.x() << ", " << pos.y() << ")\n";
        try {
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
        }
        catch (Exception &ex)
        {
            WarningThrower::ShowWarning(&ex);
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
    connect(mediator, SIGNAL(getResultPix()), this, SLOT(res()));
}

void ImageCursorController::setStartDot() {
    std::cout << "setStartDot pressed!\n";
    m_state = mouseDoState::setStartDot;
}

void ImageCursorController::setEndDot() {
    std::cout << "setEndDot pressed!\n";
    m_state = mouseDoState::setEndDot;
}

void ImageCursorController::res() {
    try {
        auto res = m_pMatHandler->GetResultPix();
        std::cout << "Fucking res getted!!!!!!!!! = " << res << std::endl;
    }
    catch (Exception &ex)
    {
        WarningThrower::ShowWarning(&ex);
    }
}


