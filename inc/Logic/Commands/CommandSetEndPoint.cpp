//
// Created by denis on 18.07.2021.
//

#include "CommandSetEndPoint.h"

void CommandSetEndPoint::execute() {
    m_controller->setState(mouseDoState::setEndDot);
}

CommandSetEndPoint::CommandSetEndPoint(IImageCursorController *controller):
m_controller(controller)
{
}
